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

in Vertex
{
	vec4 worldPos;
	vec4 screenpos;
	vec4 screenpos_light;
} iVert;

out vec4 fragColor;
void main() {
	// raymarch vars
	vec3 rayStart = (iVert.worldPos.xyz);

	vec2 texc = 0.5*((iVert.screenpos.xy/iVert.screenpos.w)+1);
	vec3 rayEnd = texture(backtex, texc).xyz;

	vec3 rayDir = rayEnd - rayStart;
	vec3 normRayDir = normalize(rayDir);

	float len = length(rayDir);

	if(len == 0 || len >100){
		discard;
	}

	float safeStepSize=stepSize;
	if(stepSize<=0)
		safeStepSize=0.001;

	float safeShadowStepMult=shadowStepMult;
	if(safeShadowStepMult<=1)
		safeShadowStepMult=1;

	vec3 step = normalize(rayDir)*safeStepSize;

	vec3 ray = vec3(0,0,0);
	vec4 acc = vec4(0,0,0,0);
	vec4 voxelColor = vec4(0,0,0,0);


	while(length(ray)<len &&  acc.a < 1.0) {
		voxelColor = texture(volumeTex, rayStart+ray+vec3(0.5));

		voxelColor.a = densityScale*(1-pow(1-voxelColor.a,safeStepSize/0.01));
		voxelColor.rgb = voxelColor.rgb*voxelColor.a;

		float opaAccRead = texture(shadowTex, rayStart+ray+vec3(0.5)).a;

		opaAccRead = clamp((opaAccRead) / (shadTres), 0, 1);	

		voxelColor.rgb = (1-opaAccRead)*voxelColor.rgb;

		acc = acc + (1.0-acc.a)*voxelColor;
		
		ray += step;
	}
	
	fragColor = acc;
}