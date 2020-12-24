#pragma once
#include <zlib.h>
#define CHUNK 16384

namespace huobi_futures
{
	namespace utils
	{
		int DecompressString(const char *src, int srcLen, const char *dst, int dstLen)
		{
			z_stream strm;
			strm.zalloc = NULL;
			strm.zfree = NULL;
			strm.opaque = NULL;

			strm.avail_in = srcLen;
			strm.avail_out = dstLen;
			strm.next_in = (Bytef *)src;
			strm.next_out = (Bytef *)dst;

			int err = -1, ret = -1;
			err = inflateInit2(&strm, MAX_WBITS + 16);
			if (err == Z_OK)
			{
				err = inflate(&strm, Z_FINISH);
				if (err == Z_STREAM_END)
				{
					ret = strm.total_out;
				}
				else
				{
					inflateEnd(&strm);
					return err;
				}
			}
			else
			{
				inflateEnd(&strm);
				return err;
			}
			inflateEnd(&strm);
			return err;
		}

	} // namespace utils
} // namespace huobi_futures
