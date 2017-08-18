


/* Copyright ChenDong(Wilbur), email <baisaichen@live.com>. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef LIGHTINK_MSGPACK_PACKERADAPTOR_CPP_

#define LIGHTINK_MSGPACK_PACKERADAPTOR_CPP_

#include <string.h>
#include <vector>
#include <map>
#include "Packer.h"
#include "Common/TypeTool.h"
#include "Common/TypeListDefine.h"

namespace LightInk
{
	template <typename TBuffer, typename T>
	inline RuntimeError pack(TBuffer & buffer, const T & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const T & v)");
		LogTraceReturn(v.pack(buffer));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const char & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const char & v)");
		LogTraceReturn(Packer<TBuffer>::pack_char(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const signed char & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const signed char & v)");
		LogTraceReturn(Packer<TBuffer>::pack_signed_char(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const short & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const short & v)");
		LogTraceReturn(Packer<TBuffer>::pack_short(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const int & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const int & v)");
		LogTraceReturn(Packer<TBuffer>::pack_int(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const long & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const long & v)");
		LogTraceReturn(Packer<TBuffer>::pack_long(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const long long & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const long long & v)");
		LogTraceReturn(Packer<TBuffer>::pack_long_long(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const unsigned char & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const unsigned char & v)");
		LogTraceReturn(Packer<TBuffer>::pack_unsigned_char(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const unsigned short & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const unsigned short & v)");
		LogTraceReturn(Packer<TBuffer>::pack_unsigned_short(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const unsigned int & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const unsigned int & v)");
		LogTraceReturn(Packer<TBuffer>::pack_unsigned_int(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const unsigned long & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const unsigned long & v)");
		LogTraceReturn(Packer<TBuffer>::pack_unsigned_long(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const unsigned long long & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const unsigned long long & v)");
		LogTraceReturn(Packer<TBuffer>::pack_unsigned_long_long(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const float & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const float & v)");
		LogTraceReturn(Packer<TBuffer>::pack_float(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const double & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const double & v)");
		LogTraceReturn(Packer<TBuffer>::pack_double(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const TypeEmpty &)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const TypeEmpty &)");
		LogTraceReturn(Packer<TBuffer>::pack_nil(buffer));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const bool & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const bool & v)");
		LogTraceReturn(Packer<TBuffer>::pack_bool(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const RuntimeError & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const RuntimeError & v)");
		LogTraceReturn(Packer<TBuffer>::pack_int(buffer, v));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const char * v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const char * v)");
		uint32 len = strlen(v);
		RuntimeError e = Packer<TBuffer>::pack_str(buffer, len);
		if (e != RE_Success)
		{
			LogTraceReturn(e);
		}
		LogTraceReturn(Packer<TBuffer>::pack_str_body(buffer, v, len));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const char * v, uint32 len)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const char * v, uint32 len)");
		RuntimeError e = Packer<TBuffer>::pack_str(buffer, len);
		if (e != RE_Success)
		{
			LogTraceReturn(e);
		}
		LogTraceReturn(Packer<TBuffer>::pack_str_body(buffer, v, len));
	}

	template <typename TBuffer>
	inline RuntimeError pack(TBuffer & buffer, const std::string & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const string v)");
		LogTraceReturn(Packer<TBuffer>::pack_str_string(buffer, v));
	}

	template <typename TBuffer, typename T>
	inline RuntimeError pack(TBuffer & buffer, const T * v, uint32 len)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const T * v, uint32 len)");
		RuntimeError e = Packer<TBuffer>::pack_array(buffer, len);
		if (e != RE_Success)
		{
			LogTraceReturn(e);
		}
		for (uint32 i = 0; i < len; ++i)
		{
			e = pack<TBuffer, T>(buffer, *(v + i));
			if (e != RE_Success)
			{
				LogTraceReturn(e);
			}
		}
		LogTraceReturn(RE_Success);
	}


	template <typename TBuffer, typename T>
	inline RuntimeError pack(TBuffer & buffer, const std::vector<T> & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const std::vector<T> & v)");
		RuntimeError e = Packer<TBuffer>::pack_array(buffer, v.size());
		if (e != RE_Success)
		{
			LogTraceReturn(e);
		}
		for (size_t i = 0; i < v.size(); ++i)
		{
			e = pack(buffer, v[i]);
			if (e != RE_Success)
			{
				LogTraceReturn(e);
			}
		}
		LogTraceReturn(RE_Success);
	}


	template <typename TBuffer, typename K, typename T>
	inline RuntimeError pack(TBuffer & buffer, const std::map<K, T> & v)
	{
		LogTrace("RuntimeError pack(TBuffer & buffer, const std::map<K, T> & v)");
		RuntimeError e = Packer<TBuffer>::pack_map(buffer, v.size());
		if (e != RE_Success)
		{
			LogTraceReturn(e);
		}
		for (typename std::map<K, T>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			e = pack(buffer, iter->first);
			if (e != RE_Success)
			{
				LogTraceReturn(e);
			}
			e = pack(buffer, iter->second);
			if (e != RE_Success)
			{
				LogTraceReturn(e);
			}
		}
		LogTraceReturn(RE_Success);
	}

}


#endif
