uniform float uSensorAngle;
uniform float uRotationAngle;
uniform float uSeed;
uniform float uStepSize;
uniform float uSensorDistanceOffset;
uniform float uPctRandomDir;
uniform float uStepSizeMultiplier;
uniform float uAspect;
uniform vec2 uTrailThresholds;
uniform vec2 uDepositThresholds;
uniform float uKillPct;
uniform float uDepositAmt;
uniform float iFrame;
uniform vec2 xrange;
uniform vec2 yrange;
uniform vec2 zrange;

#define MATHPI 3.141592653589793
#define TWOPI 6.28318530718

const vec3 outRes = vec3(uTDOutputInfo.res.zw, uTDOutputInfo.depth.y);
const vec3 invRes = vec3(uTDOutputInfo.res.xy, uTDOutputInfo.depth.x);

void wrap(inout vec3 pos)
{
	if(pos.x > xrange.y)
		pos.x -= xrange.y - xrange.x;
	else if(pos.x < xrange.x)
			pos.x += xrange.y - xrange.x;

	if(pos.y > yrange.y)
		pos.y -= yrange.y - yrange.x;
	else 
		if(pos.y < yrange.x)
			pos.y += yrange.y - yrange.x;
	
	if(pos.z > zrange.y)
		pos.z -= zrange.y - zrange.x;
	else if(pos.z < zrange.x)
		pos.z += zrange.y - zrange.x;

}

float rand(vec2 st) {
	return fract(sin(dot(st.xy,vec2(12.9898,78.233)))*43758.5453123);
}

float remap(float value, float low1, float high1, float low2, float high2){
    return(low2 + (high2 - low2) * (value - low1) / (high1 - low1));
}

float inverse_remap(float value, float low1, float high1, float low2, float high2){
    return(low1 + (value - low2)*( high1 - low1)/(high2 - low2));
}

vec3 voxelToWorld(vec3 pos){
	vec3 newpos;
    newpos.x = remap(pos.x,-0.5,0.5,xrange.x,xrange.y);
	newpos.y = remap(pos.y,-0.5,0.5,yrange.x,yrange.y);
	newpos.z = remap(pos.z,-0.5,0.5,zrange.x,zrange.y);
	return newpos;
}

vec3 worldToVoxel(vec3 pos){
	vec3 newpos;
    newpos.x = inverse_remap(pos.x,-0.5,0.5,xrange.x,xrange.y);
	newpos.y = inverse_remap(pos.y,-0.5,0.5,yrange.x,yrange.y);
	newpos.z = inverse_remap(pos.z,-0.5,0.5,zrange.x,zrange.y);
	return newpos;
}

layout (local_size_x = 16, local_size_y = 16) in;
void main() {
	ivec2 gId = ivec2(gl_GlobalInvocationID.xy);
	vec4 data0;
	vec4 data1;

	// load init state
	if (iFrame == 1) {
		data0 = texture(sTD2DInputs[0], gId.xy*invRes.xy);
		data1 = data0;
	}
	// load prev state
	else {
		data0 = imageLoad(sTDComputeOutputs[0], gId.xy);
		data1 = imageLoad(sTDComputeOutputs[1], gId.xy);
	}

	vec3 pos = data0.xyz;
	vec3 dir = data1.xyz;

	// end world space
	vec3 pos_voxel = worldToVoxel(pos)+vec3(0.5);
	vec3 dir_voxel = worldToVoxel(dir);
	// begin parameter space

	mat3 sensor[5];
	sensor[0] = mat3(1.0);
	sensor[1] = TDRotateOnAxis(uSensorAngle, vec3(0,1,0));
	sensor[2] = TDRotateOnAxis(-uSensorAngle, vec3(0,1,0));
	sensor[3] = TDRotateOnAxis(uSensorAngle, vec3(1,0,0));
	sensor[4] = TDRotateOnAxis(-uSensorAngle, vec3(1,0,0));

	mat3 turn[5];
	turn[0] = mat3(1.0);
	turn[1] = TDRotateOnAxis(uRotationAngle, vec3(0,1,0));
	turn[2] = TDRotateOnAxis(-uRotationAngle, vec3(0,1,0));
	turn[3] = TDRotateOnAxis(uRotationAngle, vec3(1,0,0));
	turn[4] = TDRotateOnAxis(-uRotationAngle, vec3(1,0,0));

	float reading[5];
	reading[0] = texture(sTD3DInputs[0], pos_voxel + dir_voxel*sensor[0]*uSensorDistanceOffset).r; //front
	reading[1] = texture(sTD3DInputs[0], pos_voxel + dir_voxel*sensor[1]*uSensorDistanceOffset).r; //left
	reading[2] = texture(sTD3DInputs[0], pos_voxel + dir_voxel*sensor[2]*uSensorDistanceOffset).r; //right
	reading[3] = texture(sTD3DInputs[0], pos_voxel + dir_voxel*sensor[3]*uSensorDistanceOffset).r; //up
	reading[4] = texture(sTD3DInputs[0], pos_voxel + dir_voxel*sensor[4]*uSensorDistanceOffset).r; //down

	// Simple sort
	int maxreading = 1;
	//int secondmaxreading = 0;
	for(int i =0; i<5;i++)
		if(reading[i]>reading[maxreading]){
			//secondmaxreading = maxreading;
			maxreading = i;
		}

	float r1 = rand(gId.xy*invRes.xy + vec2(1.13646*uSeed, 1.3261564*uSeed));
	
	dir *= turn[maxreading];
	

	dir_voxel = worldToVoxel(dir);
	vec3 tempPos = pos_voxel + uStepSize * dir_voxel;

	//worldToVoxel(tempPos);
	float trail = texture(sTD3DInputs[0], tempPos.xyz).r;
	//float trail = 20*TDSimplexNoise(10*tempPos.xyz);

	float doDeposit = smoothstep(uDepositThresholds.x, uDepositThresholds.y, trail);
	if (doDeposit == 0.) {
		dir *= turn[int(r1)*4];
	}
	
	float actualStepSize = uStepSize * mix(1., uStepSizeMultiplier, smoothstep(uTrailThresholds.x, uTrailThresholds.y, trail));

	pos += actualStepSize * dir;

	wrap(pos);

	imageStore(sTDComputeOutputs[0], gId.xy, vec4(pos, doDeposit*uDepositAmt));
	imageStore(sTDComputeOutputs[1], gId.xy, vec4(normalize(dir),0));
}
