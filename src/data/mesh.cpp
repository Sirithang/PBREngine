#include "data/mesh.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace sigurd;
using namespace sigurd::data;

void mesh::loadFromFile(Mesh& mesh, const char* file)
{
	foundation::Array<alfar::Vector3> position(foundation::memory_globals::default_allocator());
	foundation::Array<alfar::Vector3> uv(foundation::memory_globals::default_allocator());
	foundation::Array<alfar::Vector3> normal(foundation::memory_globals::default_allocator());

	foundation::Array<Vertex> vertices(foundation::memory_globals::default_allocator());

	FILE *fp;
	struct stat st;
	char buffer[2048];

	fp = fopen(file, "r");
	if (fp == NULL) {
		return;
	}

	fstat(fileno(fp), &st);

	fgets(&buffer[0], 2048, fp);
	while(!feof(fp))
	{
		if(buffer[0] == 'v')
		{
			alfar::Vector3 v;
			sscanf(buffer, "v %f %f %f", &v.x, &v.y, &v.z);
			foundation::array::push_back(position, v);
		}
		else if(buffer[0] == 'vt')
		{
			alfar::Vector3 vt;
			sscanf(buffer, "vt %f %f %f", &vt.x, &vt.y, &vt.z);
			foundation::array::push_back(uv, vt);
		}
		else if(buffer[0] == 'n')
		{
			alfar::Vector3 n;
			sscanf(buffer, "n %f %f %f", &n.x, &n.y, &n.z);
			foundation::array::push_back(normal, n);
		}
		else if(buffer[0] == 'f')
		{
			Vertex v;
			int pos[3];
			int uv[3];
			int norm[3];

			sscanf(buffer, "f %i/%i/%i %i/%i/%i %i/%i/%i", &pos[0], &uv[0], &norm[0],  &pos[1], &uv[1], &norm[1], &pos[2], &uv[2], &norm[2]);
			printf("f %i/%i/%i %i/%i/%i %i/%i/%i", &pos[0], &uv[0], &norm[0],  &pos[1], &uv[1], &norm[1], &pos[2], &uv[2], &norm[2]);
		}

		fgets(&buffer[0], 2048, fp);
	}
}