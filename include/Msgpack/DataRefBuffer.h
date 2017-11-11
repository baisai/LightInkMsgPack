



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
#ifndef LIGHTINK_MSGPACK_DATAREFBUFFER_H_
#define LIGHTINK_MSGPACK_DATAREFBUFFER_H_

#include <string>
#include "Common/RuntimeError.h"
#include "Common/Type.h"
#include "Common/Log.h"
#include "Common/SmallObject.h"

namespace LightInk
{
	class LIGHTINK_DECL DataRefBuffer : public SmallObject
	{
	public:
		DataRefBuffer();
		DataRefBuffer(const DataRefBuffer & cp);
		DataRefBuffer(uint32 size);
		~DataRefBuffer();

		DataRefBuffer & operator = (const DataRefBuffer & right);

		void clear();
		char * data() const;

		uint32 buffer_size() const;

		void write_pos(uint32 pos);
		uint32 write_pos() const;

		RuntimeError write(const void * data, uint32 size);
		RuntimeError write(const std::string & data);


		RuntimeError read(void * data, uint32 size, uint32 offset = 0);
		RuntimeError read(std::string & data, uint32 size, uint32 offset = 0);
		RuntimeError read(const char ** data, uint32 size, uint32 offset = 0);

		RuntimeError resize_buffer(uint32 size);


	protected:
		const char * m_buffer;
		uint32 m_size;
	};

	inline void DataRefBuffer::clear()
	{
		LogTrace("DataRefBuffer::clear()");
		m_buffer = NULL;
		m_size = 0;
		LogTraceReturnVoid;
	}

	//warning can not use write 
	inline char * DataRefBuffer::data() const
	{
		LogTrace("char * DataRefBuffer::data() const");
		LogTraceReturn(const_cast<char *>(m_buffer));
	}

	inline uint32 DataRefBuffer::buffer_size() const
	{
		LogTrace("uint32 DataRefBuffer::buffer_size() const");
		LogTraceReturn(m_size);
	}

	inline void DataRefBuffer::write_pos(uint32 pos)
	{
		LogTrace("void DataRefBuffer::write_pos(uint32 pos)");
		LogTraceReturnVoid;
	}

	inline uint32 DataRefBuffer::write_pos() const
	{
		LogTrace("uint32 DataRefBuffer::write_pos() const");
		LogTraceReturn(m_size);
	}

	inline RuntimeError DataRefBuffer::resize_buffer(uint32 size)
	{
		LogTrace("RuntimeError DataRefBuffer::resize_buffer(uint32 size)");
		LogTraceReturn(RE_Success);
	}

}

#endif