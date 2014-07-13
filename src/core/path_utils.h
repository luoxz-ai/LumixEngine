#pragma once

#include <cstring>

namespace Lumix
{
	struct LUMIX_CORE_API PathUtils
	{
		static void normalize(const char* path, char* out, uint32_t max_size)
		{
			ASSERT(max_size > 0);
			uint32_t i = 0;
			if (path[0] == '\\' || path[0] == '/')
				++path;
			while (*path != '\0' && i < max_size)
			{
				*out = *path == '\\' ? '/' : *path;
				*out = *path >= 'A' && *path <= 'Z' ? *path - 'A' + 'a' : *out;

				path++;
				out++;
				i++;
			}
			(i < max_size ? *out : *(out - 1)) = '\0';
		}

		static void getDir(char* dir, int max_length, const char* src)
		{
			copyString(dir, max_length, src);
			for (int i = strlen(dir) - 1; i >= 0; --i)
			{
				if (dir[i] == '\\' || dir[i] == '/')
				{
					++i;
					dir[i] = '\0';
					break;
				}
			}
		}

		static void getFilename(char* filename, int /*max_length*/, const char* src)
		{
			for (int i = strlen(src) - 1; i >= 0; --i)
			{
				if (src[i] == '\\' || src[i] == '/')
				{
					++i;
					strcpy(filename, src + i);
					break;
				}
			}
		}
		private:
			PathUtils();
			~PathUtils();
	};
}