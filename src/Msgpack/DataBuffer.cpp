


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

#include "Msgpack/DataBuffer.h"
#include <stdlib.h>
#include <memory.h>
#include "Common/UserMemory.h"

namespace LightInk
{
	DataBuffer::DataBuffer() : m_buffer(NULL), m_size(0), m_writePos(0)
	{
		LogTrace("DataBuffer::DataBuffer()");
		//m_buffer = (char *)LightInkUerMemory->realloc_user(NULL, m_size);
		LogTraceReturnVoid;
	}

	DataBuffer::DataBuffer(const DataBuffer & cp) : m_buffer(NULL), m_size(cp.m_size), m_writePos(cp.m_writePos)
	{
		LogTrace("DataBuffer::DataBuffer(const DataBuffer & cp)");
		if (m_size > 0)
		{
			m_buffer = (char *)LightInkUerMemory->realloc_user(m_buffer, m_size);
			memcpy(m_buffer, cp.m_buffer, m_writePos); 
		}
		LogTraceReturnVoid;
	}

	DataBuffer::DataBuffer(uint32 size) : m_buffer(NULL), m_size(size), m_writePos(0)
	{
		LogTrace("DataBuffer::DataBuffer(uint32 size)");
		if (m_size > 0)
		{
			m_buffer = (char *)LightInkUerMemory->realloc_user(m_buffer, m_size);
		}
		LogTraceReturnVoid;
	}

	DataBuffer::~DataBuffer()
	{
		LogTrace("DataBuffer::~DataBuffer()");
		LightInkUerMemory->realloc_user(m_buffer, 0);
		m_size = 0;
		m_writePos = 0;
		m_buffer = NULL;
		LogTraceReturnVoid;
	}

	DataBuffer & DataBuffer::operator = (const DataBuffer & right)
	{
		LogTrace("DataBuffer & DataBuffer::operator = (const DataBuffer & right)");
		m_buffer = (char *)LightInkUerMemory->realloc_user(m_buffer, right.m_size);
		if (right.m_size > 0)
		{
			memcpy(m_buffer, right.m_buffer, right.m_writePos); 
		}
		m_size = right.m_size;
		m_writePos = right.m_writePos;
		LogTraceReturn(*this);
	}

	RuntimeError DataBuffer::write(const char * data, uint32 size)
	{
		LogTrace("RuntimeError DataBuffer::write(const char * data, uint32 size)");
		if (m_writePos + size > m_size)
		{
			RuntimeError e = reset_buffer(m_writePos + size);
			if (e != RE_Success)
			{
				LogTraceReturn(e);
			}
		}
		memcpy(m_buffer + m_writePos, data, size);
		m_writePos += size;
		LogTraceReturn(RE_Success);
	}

	RuntimeError DataBuffer::write(const signed char * data, uint32 size)
	{
		LogTrace("RuntimeError DataBuffer::write(const signed char * data, uint32 size)");
		if (m_writePos + size > m_size)
		{
			RuntimeError e = reset_buffer(m_writePos + size);
			if (e != RE_Success)
			{
				LogTraceReturn(e);
			}
		}
		memcpy(m_buffer + m_writePos, data, size);
		m_writePos += size;
		LogTraceReturn(RE_Success);
	}

	RuntimeError DataBuffer::write(const unsigned char * data, uint32 size)
	{
		LogTrace("RuntimeError DataBuffer::write(const unsigned char * data, uint32 size)");
		if (m_writePos + size > m_size)
		{
			RuntimeError e = reset_buffer(m_writePos + size);
			if (e != RE_Success)
			{
				LogTraceReturn(e);
			}
		}
		memcpy(m_buffer + m_writePos, data, size);
		m_writePos += size;
		LogTraceReturn(RE_Success);
	}

	RuntimeError DataBuffer::write(const std::string & data)
	{
		LogTrace("RuntimeError DataBuffer::write(const std::string & data)");
		LogTraceReturn(write(data.c_str(), data.size()));
	}

	RuntimeError DataBuffer::read(char * data, uint32 size, uint32 offset)
	{
		LogTrace("RuntimeError DataBuffer::read(char * data, uint32 size, uint32 offset)");
		if (m_writePos - offset < size) //����λ��
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		memcpy(data, m_buffer + offset, size);
		LogTraceReturn(RE_Success);
	}

	RuntimeError DataBuffer::read(signed char * data, uint32 size, uint32 offset)
	{
		LogTrace("RuntimeError DataBuffer::read(signed char * data, uint32 size, uint32 offset)");
		if (m_writePos - offset < size) //����λ��
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		memcpy(data, m_buffer + offset, size);
		LogTraceReturn(RE_Success);
	}

	RuntimeError DataBuffer::read(unsigned char * data, uint32 size, uint32 offset)
	{
		LogTrace("RuntimeError DataBuffer::read(unsigned char * data, uint32 size, uint32 offset)");
		if (m_writePos - offset < size) //����λ��
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		memcpy(data, m_buffer + offset, size);
		LogTraceReturn(RE_Success);
	}
	RuntimeError DataBuffer::read(std::string & data, uint32 size, uint32 offset)
	{
		LogTrace("RuntimeError DataBuffer::read(std::string & data, uint32 size, uint32 offset)");
		if (m_writePos - offset < size) //����λ��
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		data.append(m_buffer + offset, size);
		LogTraceReturn(RE_Success);
	}

	RuntimeError DataBuffer::read(char ** data, uint32 size, uint32 offset)
	{
		LogTrace("RuntimeError DataBuffer::read(char ** data, uint32 size, uint32 offset)");
		if (m_writePos - offset < size) //����λ��
		{
			LogTraceReturn(RE_Msgpack_DataOutOfRangeError);
		}
		*data = m_buffer + offset;
		LogTraceReturn(RE_Success);
	}

	RuntimeError DataBuffer::resize_buffer(uint32 size)
	{
		LogTrace("RuntimeError DataBuffer::resize_buffer(uint32 size)");
		void * tmp = LightInkUerMemory->realloc_user(m_buffer, size);
		if (!tmp)
		{
			LogTraceReturn(RE_Msgpack_MemoryNotEnoughError);
		}
		m_buffer = static_cast<char *>(tmp);
		if (m_writePos > size)
		{
			m_writePos = size;
		}
		m_size = size;
		LogTraceReturn(RE_Success);
	}


	RuntimeError DataBuffer::reset_buffer(uint32 size)
	{
		LogTrace("RuntimeError DataBuffer::reset_buffer(uint32 size)");
		if (size <= m_size)
		{
			LogTraceReturn(RE_Success);
		}
		if (m_size > 0)
		{
			size = ((size - m_size) << 1) + m_size;
		}
		void* tmp = LightInkUerMemory->realloc_user(m_buffer, size);
		if(!tmp) {
			LogTraceReturn(RE_Msgpack_MemoryNotEnoughError);
		}
		m_buffer = static_cast<char*>(tmp);
		m_size = size;
		LogTraceReturn(RE_Success);
	}

}

