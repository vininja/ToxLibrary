uniform vec3 uOffset;
const uvec3 voxelRes = ivec3(uTDOutputInfo.res.zw, uTDOutputInfo.depth.y);
const vec4 invRes = vec4(uTDOutputInfo.res.xy, uTDOutputInfo.depth.x,1); // 0-1

vec4 readInputVoxel(ivec3 coord){
	return texelFetch(sTD3DInputs[0],coord,0);
}

vec4 readOutputVoxel(ivec3 coord){
	return imageLoad(sTDComputeOutputs[0],coord);
	//return texelFetch(sTD3DInputs[0],coord,0);
}

void writeOutputVoxel(ivec3 coord, vec4 data){
	imageStore(sTDComputeOutputs[0],coord,data);
	return;
}

//Jumping Flood Algorithm - adapted from https://unitylist.com/p/k6u/Mesh-To-SDF
void JFAIter(int offset, ivec3 id) {
	vec4 closest = readOutputVoxel(id);
	float closestDist = 5000.0f;
	//ivec3 bounds = voxelRes;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				ivec3 at = ivec3(i-1, j-1, k-1) * offset + id;
				//if (any(at > 0) || any(at >= 25)) continue;
				//if (any(lessThan(at,ivec3(0))) || any(greaterThan(at,bounds))) continue;
				//memoryBarrier();
				vec4 voxel = readOutputVoxel(at)*voxelRes.z;
				// non seed / hasn't seen a seed
				if (voxel.w == 0.0f) continue;
				float voxelDist = distance(id, voxel.xyz);
				if (voxelDist < closestDist) {
					closestDist = voxelDist;
					closest = voxel*invRes;
				}
			}
		}
	}
	//memoryBarrier();
	closest.xyz += uOffset*invRes.z;
	writeOutputVoxel(id, closest);
}

layout (local_size_x = 8, local_size_y = 8, local_size_z = 8) in;
void main(){
	ivec3 gId = ivec3(gl_GlobalInvocationID.xyz);

	if ( uTDPass == 0){
		writeOutputVoxel(gId, readInputVoxel(gId));
	}
	else if ( uTDPass == 1){
		//JFAIter(128, gId);
		//JFAIter(64, gId);
		JFAIter(32, gId);
		JFAIter(16, gId);
	}
	else {
		JFAIter(8, gId);
		JFAIter(4, gId);
		JFAIter(2, gId);
		JFAIter(1, gId);
	}
		/*
		for (int offset = 128; offset >= 1; offset /= 2) {
			JFAIter(offset, gId);
			//memoryBarrier();
		}
		*/
}