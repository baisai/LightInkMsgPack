


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
#ifndef LIGHTINK_MSGPACK_DATAFIXBUFFER_CPP_
#define LIGHTINK_MSGPACK_DATAFIXBUFFER_CPP_

#include "DataFixBuffer.h"

namespace LightInk
{
	template <uint32 FixLen>
	DataFixBuffer<FixLen>::DataFixBuffer() : m_writePos(0)
	{
		LogTrace("DataFixBuffer<FixLen>::DataFixBuffer()");
		LogTraceReturnVoid;
	}

	template <uint32 FixLen>
	DataFixBuffer<FixLen>::DataFixBuffer(const DataFixBuffer & cp) : m_writePos(cp.m_writePos)
	{
		LogTrace("DataFixBuffer<FixLen>::DataFixBuffer(const DataFixBuffer & cp)");
		memcpy(m_buffer, cp.m_buffer, m_writePos); 
		LogTraceReturnVoid;
	}

	template <uint32 FixLen>
	DataFixBuffer<FixLen>::DataFixBuffer(uint32 size) : m_writePos(0)
	{
		LogTrace("DataFixBuffer<FixLen>::DataFixBuffer(uint32 size)");
		LogTraceReturnVoid;
	}

	template <uint32 FixLen>
	DataFixBuffer<FixLen>::~DataFixBuffer()
	{
		LogTrace("DataFixBuffer<FixLen>::~DataFixBuffer()");
		m_writePos = 0;
		LogTraceReturnVoid;
	}

	template <uint32 FixLen>
	DataFixBuffer<FixLen> & DataFixBuffer<FixLen>::operator = (const DataFixBuffer & right)
	{
		LogTrace("DataFixBuffer<FixLen> & DataFixBuffer<FixLen>::operator = (const DataFixBuffer & right)");
		m_writePos = right.m_writePos;
		memcpy(m_buffer, right.m_buffer, m_writePos);
		LogTraceReturnVoid;
	}


	template <uint32 FixLen>
	inline void DataFixBuffer<FixLen>::clear()
	{
		LogTrace("void DataFixBuffer<FixLen>::clear()");
		m_writePos = 0;
		LogTraceReturnVoid;
	}

	template <uint32 FixLen>
	inline char * DataFixBuffer<FixLen>::data() const
	{
		LogTrace("char * DataFixBuffer<FixLen>::data() const");
		LogTraceReturn((char *)m_buffer);
	}


	template <uint32 FixLen>
	inline uint32 DataFixBuffer<FixLen>::buffer_size() const
	{
		LogTrace("uint32 DataFixBuffer<FixLen>::buffer_size() const");
		LogTraceReturn(FixLen);
	}


	template <uint32 FixLen>
	inline void DataFixBuffer<FixLen>::write_pos(uint32 pos)
	{
		LogTrace("void DataFixBuffer<FixLen>::write_pos(uint32 pos)");
		m_writePos = pos;
		LogTraceReturnVoid;
	}

	template <uint32 FixLen>
	inline uint32 DataFixBuffer<FixLen>::write_pos() const
	{
		LogTrace("uint32 DataFixBuffer<FixLen>::write_pos() const");
		LogTraceReturn(m_writePos);
	}


	template <uint32 FixLen>
	RuntimeError DataFixBuffer<FixLen>::write(const char * data, uint32 size)
	{
		LogTrace("RuntimeError DataFixBuffer<FixLen>::write(const char * data, uint32 size)");
		if (m_writePos + size > FixLen)
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		memcpy(m_buffer + m_writePos, data, size);
		m_writePos += size;
		LogTraceReturn(RE_Success);
	}

	template <uint32 FixLen>
	RuntimeError DataFixBuffer<FixLen>::write(const signed char * data, uint32 size)
	{
		LogTrace("RuntimeError DataFixBuffer<FixLen>::write(const signed char * data, uint32 size)");
		if (m_writePos + size > FixLen)
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		memcpy(m_buffer + m_writePos, data, size);
		m_writePos += size;
		LogTraceReturn(RE_Success);
	}

	template <uint32 FixLen>
	RuntimeError DataFixBuffer<FixLen>::write(const unsigned char * data, uint32 size)
	{
		LogTrace("RuntimeError DataFixBuffer<FixLen>::write(const unsigned char * data, uint32 size)");
		if (m_writePos + size > FixLen)
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		memcpy(m_buffer + m_writePos, data, size);
		m_writePos += size;
		LogTraceReturn(RE_Success);
	}

	template <uint32 FixLen>
	inline RuntimeError DataFixBuffer<FixLen>::write(const std::string & data)
	{
		LogTrace("RuntimeError DataFixBuffer<FixLen>::write(const std::string & data)");
		LogTraceReturn(write(data.c_str(), data.size()));
	}



	template <uint32 FixLen>
	RuntimeError DataFixBuffer<FixLen>::read(char * data, uint32 size, uint32 offset)
	{
		LogTrace("RuntimeError DataFixBuffer<FixLen>::read(char * data, uint32 size, uint32 offset)");
		if (m_writePos - offset < size) //超过位置
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		memcpy(data, m_buffer + offset, size);
		LogTraceReturn(RE_Success);
	}

	template <uint32 FixLen>
	RuntimeError DataFixBuffer<FixLen>::read(signed char * data, uint32 size, uint32 offset)
	{
		LogTrace("RuntimeError DataFixBuffer<FixLen>::read(signed char * data, uint32 size, uint32 offset)");
		if (m_writePos - offset < size) //超过位置
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		memcpy(data, m_buffer + offset, size);
		LogTraceReturn(RE_Success);
	}

	template <uint32 FixLen>
	RuntimeError DataFixBuffer<FixLen>::read(unsigned char * data, uint32 size, uint32 offset)
	{
		LogTrace("RuntimeError DataFixBuffer<FixLen>::read(unsigned char * data, uint32 size, uint32 offset)");
		if (m_writePos - offset < size) //超过位置
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		memcpy(data, m_buffer + offset, size);
		LogTraceReturn(RE_Success);
	}

	template <uint32 FixLen>
	RuntimeError DataFixBuffer<FixLen>::read(std::string & data, uint32 size, uint32 offset)
	{
		LogTrace("RuntimeError DataFixBuffer<FixLen>::read(std::string & data, uint32 size, uint32 offset)");
		if (m_writePos - offset < size) //超过位置
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		data.append(m_buffer + offset, size);
		LogTraceReturn(RE_Success);
	}

	template <uint32 FixLen>
	RuntimeError DataFixBuffer<FixLen>::read(char ** data, uint32 size, uint32 offset)
	{
		LogTrace("RuntimeError DataFixBuffer<FixLen>::read(char ** data, uint32 size, uint32 offset)");
		if (m_writePos - offset < size) //超过位置
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		*data = m_buffer + offset;
		LogTraceReturn(RE_Success);
	}


	template <uint32 FixLen>
	inline RuntimeError DataFixBuffer<FixLen>::resize_buffer(uint32 size)
	{
		LogTrace("RuntimeError DataFixBuffer<FixLen>::resize_buffer(uint32 size)");
		LogTraceReturn(RE_Msgpack_DisableResize);
	}
}


#endif