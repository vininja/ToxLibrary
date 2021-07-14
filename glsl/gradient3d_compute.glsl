const vec3 outRes = vec3(uTDOutputInfo.res.zw, uTDOutputInfo.depth.y);
const vec3 invRes = vec3(uTDOutputInfo.res.xy, uTDOutputInfo.depth.x);

// input: normalized voxel coord
vec4 get_gradient(vec3 p){
    vec3 grad;
    float offset = .08f;
    // x
    float xi = (p.x + offset);
    float xf = p.x + offset - xi;

    float xd0 = texture(sTD3DInputs[0], vec3(xi - offset,p.yz)).r;
    float xd1 = texture(sTD3DInputs[0], vec3(xi,p.yz)).r;
    float xd2 = texture(sTD3DInputs[0], vec3(xi + offset,p.yz)).r;
    grad.x = (xd1 - xd0) * (1.0f - xf) + (xd2 - xd1) * xf; // lerp
    // y
    float yi = (p.y + offset);
    float yf = p.y + offset - yi;
    float yd0 = texture(sTD3DInputs[0], vec3(p.x, yi - offset, p.z)).r;
    float yd1 = texture(sTD3DInputs[0], vec3(p.x, yi, p.z)).r;
    float yd2 = texture(sTD3DInputs[0], vec3(p.x, yi + offset, p.z)).r;
    grad.y = (yd1 - yd0) * (1.0f - yf) + (yd2 - yd1) * yf; // lerp
    // z
    float zi = (p.z + offset);
    float zf = p.z + offset - zi;
    float zd0 = texture(sTD3DInputs[0], vec3(p.xy, zi-offset)).r;
    float zd1 = texture(sTD3DInputs[0], vec3(p.xy, zi)).r;
    float zd2 = texture(sTD3DInputs[0], vec3(p.xy, zi+offset)).r;
    grad.z = (zd1 - zd0) * (1.0f - zf) + (zd2 - zd1) * zf; // lerp

    return normalize(vec4(grad,grad.x <=0 || grad.y <=0 || grad.z <=0));
}

vec4 readInputVoxel(ivec3 coord){
    return texelFetch(sTD3DInputs[0],coord,0);
}

vec4 readOutputVoxel(ivec3 coord){
    return imageLoad(sTDComputeOutputs[0],coord);
}

void writeOutputVoxel(ivec3 coord, vec4 data){
    imageStore(sTDComputeOutputs[0],coord,data);
    return;
}

layout (local_size_x = 8, local_size_y = 8, local_size_z = 8) in;
void main(){

    ivec3 gId = ivec3(gl_GlobalInvocationID.xyz);

    if(gId.x < outRes.x && gId.y < outRes.y && gId.z < outRes.z ){
        writeOutputVoxel(gId, readInputVoxel(gId)+get_gradient(gId*invRes).aaaa);
    } 
}