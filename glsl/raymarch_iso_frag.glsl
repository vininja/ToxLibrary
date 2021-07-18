uniform sampler2D backtex;
uniform sampler2D backlighttex;
uniform sampler3D volumeTex;
uniform sampler3D shadowTex;

uniform float stepSize;
uniform float volSize;
uniform float densityScale;
uniform float shadowStepMult;
uniform float shadowMult;
uniform float shadTres;
uniform float surfaceTres;

uniform mat4 lookAtMat;

// input: normalized voxel coord
vec3 get_gradient(vec3 p){
    vec3 grad;
    float offset = .0008f;
    // x
    float xi = (p.x + offset);
    float xf = p.x + offset - xi;

    float xd0 = texture(volumeTex, vec3(xi - offset,p.yz)).a;
    float xd1 = texture(volumeTex, vec3(xi,p.yz)).a;
    float xd2 = texture(volumeTex, vec3(xi + offset,p.yz)).a;
    grad.x = (xd1 - xd0) * (1.0f - xf) + (xd2 - xd1) * xf; // lerp
    // y
    float yi = (p.y + offset);
    float yf = p.y + offset - yi;
    float yd0 = texture(volumeTex, vec3(p.x, yi - offset, p.z)).a;
    float yd1 = texture(volumeTex, vec3(p.x, yi, p.z)).a;
    float yd2 = texture(volumeTex, vec3(p.x, yi + offset, p.z)).a;
    grad.y = (yd1 - yd0) * (1.0f - yf) + (yd2 - yd1) * yf; // lerp
    // z
    float zi = (p.z + offset);
    float zf = p.z + offset - zi;
    float zd0 = texture(volumeTex, vec3(p.xy, zi-offset)).a;
    float zd1 = texture(volumeTex, vec3(p.xy, zi)).a;
    float zd2 = texture(volumeTex, vec3(p.xy, zi+offset)).a;
    grad.z = (zd1 - zd0) * (1.0f - zf) + (zd2 - zd1) * zf; // lerp
    return normalize(grad);
}

in Vertex
{
	vec4 worldPos;
	vec4 screenpos;
	vec4 screenpos_light;
} iVert;

out vec4 fragColor[2];
void main() {
	// raymarch vars
	vec3 rayStart = (iVert.worldPos.xyz);

	vec2 texc = 0.5*((iVert.screenpos.xy/iVert.screenpos.w)+1);
	vec3 rayEnd = texture(backtex, texc).xyz;

	vec3 rayDir = rayEnd - rayStart;
	vec3 normRayDir = normalize(rayDir);

	float len = length(rayDir);

	if(len <= 0 || len >= 100){
		discard;
	}

	float safeStepSize=stepSize;
	if(stepSize<=0)
		safeStepSize=0.001;

	vec3 step = normalize(rayDir)*safeStepSize;

	vec3 ray = vec3(0,0,0);
	vec4 acc = vec4(0,0,0,0);
	vec4 voxelColor = vec4(0,0,0,0);

	vec3 specular;
	while(length(ray)<len /*&&  acc.a < 1.0*/) {
		vec3 pos = rayStart+ray+vec3(0.5);
		vec3 lightDir = pos-uTDLights[0].position.xyz;
		lightDir = normalize(lightDir);
		vec3 lightColor1 = vec3(10);
		//vec3 lightColor2 = 2*vec3(0.898,0.76,0.596);
		vec3 lightColor2 = vec3(1.5);
		vec3 viewDir = (lookAtMat*vec4(0.0,0.0,-1.0,0.0)).xyz;

		voxelColor = texture(volumeTex, pos);

		if(voxelColor.a >= surfaceTres){
			float specularStrength = 1.5;
			//normal
			vec3 n = get_gradient(pos);
			//diffuse
			vec3 diff = max(dot(n, lightDir), 0.0)*lightColor2;
			//specular
			vec3 reflectDir = reflect(-lightDir, n);  
			float spec = pow(max(dot(viewDir, reflectDir), 0.0), 150);
			specular = specularStrength * spec * lightColor1;
			acc.rgb = 2*(diff)*voxelColor.rgb;
			acc.a=1;
			//acc.rgb = n;
			break;
		}
		ray += step;
	}
	
	fragColor[0] = acc;

	if(specular.r > 0.1)
		fragColor[1] = vec4(specular,1);
	else
		fragColor[1] = vec4(0);
}