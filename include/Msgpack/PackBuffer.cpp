


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

#ifndef LIGHTINK_MSGPACK_PACKBUFFER_CPP_
#define LIGHTINK_MSGPACK_PACKBUFFER_CPP_

#include "Msgpack/PackBuffer.h"
#include "Msgpack/Packer.h"
#include "Msgpack/Unpacker.h"


namespace LightInk
{
	template <typename DBuffer>
	inline PackBuffer<DBuffer>::PackBuffer() : m_readPos(0)
	{
		LogTrace("PackBuffer<DBuffer>::PackBuffer()");
		LogTraceReturnVoid;
	}

	template <typename DBuffer>
	inline PackBuffer<DBuffer>::PackBuffer(uint32 initSize) : m_buffer(initSize), m_readPos(0)
	{
		LogTrace("PackBuffer<DBuffer>::PackBuffer(uint32 initSize)");
		LogTraceReturnVoid;
	}

	template <typename DBuffer>
	inline PackBuffer<DBuffer>::PackBuffer(const PackBuffer & cp) : m_buffer(cp.m_buffer), m_readPos(cp.m_readPos)
	{
		LogTrace("PackBuffer<DBuffer>::PackBuffer(const PackBuffer & cp)");
		LogTraceReturnVoid;
	}

	template <typename DBuffer>
	inline PackBuffer<DBuffer> & PackBuffer<DBuffer>::operator = (const PackBuffer & right)
	{
		LogTrace("PackBuffer<DBuffer> & PackBuffer<DBuffer>::operator = (const PackBuffer & right)");
		m_buffer = right.m_buffer;
		m_readPos = right.m_readPos;
		LogTraceReturn((*this));
	}

	template <typename DBuffer>
	inline PackBuffer<DBuffer>::~PackBuffer()
	{
		LogTrace("PackBuffer<DBuffer>::~PackBuffer()");
		m_readPos = 0;
		LogTraceReturnVoid;
	}

	template <typename DBuffer>
	inline PackBuffer<DBuffer> * PackBuffer<DBuffer>::clone()
	{
		LogTrace("PackBuffer<DBuffer> * PackBuffer<DBuffer>::clone()");
		LogTraceReturn((new PackBuffer<DBuffer>(*this)));
	}

	template <typename DBuffer>
	inline PackBuffer<DBuffer> * PackBuffer<DBuffer>::deep_clone()
	{
		LogTrace("PackBuffer<DBuffer> * PackBuffer<DBuffer>::deep_clone()");
		PackBuffer<DBuffer> * p = new PackBuffer<DBuffer>(m_buffer.buffer_size());
		p->write(*this);
		LogTraceReturn(p);
	}

	template <typename DBuffer>
	inline bool PackBuffer<DBuffer>::release()
	{
		LogTrace("bool PackBuffer<DBuffer>::release()");
		clear();
		if (m_buffer.buffer_size() > 0xffu)
		{
			LogTraceReturn(false);
		}
		LogTraceReturn(true);
	}

	template <typename DBuffer>
	inline void PackBuffer<DBuffer>::clear()
	{
		LogTrace("void PackBuffer<DBuffer>::clear()");
		m_buffer.clear();
		m_readPos = 0;
		LogTraceReturnVoid;
	}

	template <typename DBuffer>
	inline char * PackBuffer<DBuffer>::data() const
	{
		LogTrace("char * PackBuffer<DBuffer>::data()");
		LogTraceReturn((m_buffer.data() + m_readPos));
	}

	template <typename DBuffer>
	inline uint32 PackBuffer<DBuffer>::size() const
	{
		LogTrace("uint32 PackBuffer<DBuffer>::size()");
		LogTraceReturn((m_buffer.write_pos() - m_readPos));
	}

	template <typename DBuffer>
	inline uint32 PackBuffer<DBuffer>::buffer_size() const
	{
		LogTrace("uint32 PackBuffer<DBuffer>::buffer_size()");
		LogTraceReturn(m_buffer.buffer_size());
	}

	template <typename DBuffer>
	inline uint32 PackBuffer<DBuffer>::free_size() const
	{
		LogTrace("uint32 PackBuffer<DBuffer>::free_size() const");
		LogTraceReturn(m_buffer.buffer_size() - m_buffer.write_pos());
	}

	template <typename DBuffer>
	inline void PackBuffer<DBuffer>::write_pos(uint32 pos)
	{
		LogTrace("void PackBuffer<DBuffer>::write_pos(uint32 pos)");
		m_buffer.write_pos(pos);
		LogTraceReturnVoid;
	}

	template <typename DBuffer>
	inline uint32 PackBuffer<DBuffer>::write_pos() const
	{
		LogTrace("uint32 PackBuffer<DBuffer>::write_pos()");
		LogTraceReturn(m_buffer.write_pos());
	}

	template <typename DBuffer>
	inline void PackBuffer<DBuffer>::read_pos(uint32 pos)
	{
		LogTrace("void PackBuffer<DBuffer>::read_pos(uint32 pos)");
		if (pos <= m_buffer.write_pos())
		{
			m_readPos = pos;
		} 
		else
		{
			m_readPos = m_buffer.write_pos();
		}
		LogTraceReturnVoid;
	}

	template <typename DBuffer>
	inline uint32 PackBuffer<DBuffer>::read_pos() const
	{
		LogTrace("uint32 PackBuffer<DBuffer>::read_pos()");
		LogTraceReturn(m_readPos);
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::write(const PackBuffer<DBuffer> & data)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::write(const PackBuffer<DBuffer> & data)");
		LogTraceReturn(m_buffer.write(data.data(), data.write_pos()));
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::write(const char * data, uint32 size)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::write(const char * data, uint32 size)");
		LogTraceReturn(m_buffer.write(data, size));
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::write(const signed char * data, uint32 size)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::write(const signed char * data, uint32 size)");
		LogTraceReturn(m_buffer.write(data, size));
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::write(const unsigned char * data, uint32 size)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::write(const unsigned char * data, uint32 size)");
		LogTraceReturn(m_buffer.write(data, size));
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::write(const std::string & data)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::write(const string & data)");
		LogTraceReturn(m_buffer.write(data));
	}

	template <typename DBuffer>
	template <typename T>
	inline RuntimeError PackBuffer<DBuffer>::pack(const T & data)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::pack(const T & data)");
		LogTraceReturn(LightInk::pack(*this, data));
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::read(PackBuffer & data)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::read(PackBuffer & data)");
		LogTraceReturn(data.write(*this));
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::read(char * data, uint32 size)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::read(char * data, uint32 size)");
		RuntimeError e = m_buffer.read(data, size, m_readPos);
		if (e != RE_Success)
		{
			LogTraceReturn(e);
		}
		m_readPos += size;
		LogTraceReturn(RE_Success);
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::read(signed char * data, uint32 size)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::read(signed char * data, uint32 size)");
		RuntimeError e = m_buffer.read(data, size, m_readPos);
		if (e != RE_Success)
		{
			LogTraceReturn(e);
		}
		m_readPos += size;
		LogTraceReturn(RE_Success);
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::read(unsigned char * data, uint32 size)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::read(unsigned char * data, uint32 size)");
		RuntimeError e = m_buffer.read(data, size, m_readPos);
		if (e != RE_Success)
		{
			LogTraceReturn(e);
		}
		m_readPos += size;
		LogTraceReturn(RE_Success);
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::read(std::string & data, uint32 size)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::read(string & data, uint32 size)");
		RuntimeError e = m_buffer.read(data, size, m_readPos);
		if (e != RE_Success)
		{
			LogTraceReturn(e);
		}
		m_readPos += size;
		LogTraceReturn(RE_Success);
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::read(char ** data, uint32 size)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::read(char ** data, uint32 size)");
		RuntimeError e = m_buffer.read(data, size, m_readPos);
		if (e != RE_Success)
		{
			LogTraceReturn(e);
		}
		m_readPos += size;
		LogTraceReturn(RE_Success);
	}

	template <typename DBuffer>
	template <typename T>
	inline RuntimeError PackBuffer<DBuffer>::unpack(T & data)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::unpack(T & data)");
		LogTraceReturn(LightInk::unpack(*this, data));
	}

	template <typename DBuffer>
	template <typename T>
	inline PackBuffer<DBuffer> & PackBuffer<DBuffer>::operator << (const T & data)
	{
		LogTrace("PackBuffer<DBuffer> & PackBuffer<DBuffer>::operator << (const T & data)");
		RuntimeError e = LightInk::pack(*this, data);
		if(e != RE_Success)
		{
			throw e;
		}
		LogTraceReturn((*this));
	}

	template <typename DBuffer>
	template <typename T>
	inline PackBuffer<DBuffer> & PackBuffer<DBuffer>::operator >> (T & data)
	{
		LogTrace("PackBuffer<DBuffer> & PackBuffer<DBuffer>::operator >> (T & data)");
		RuntimeError e = LightInk::unpack(*this, data);
		if(e != RE_Success)
		{
			throw e;
		}
		LogTraceReturn((*this));
	}

	template <typename DBuffer>
	inline RuntimeError PackBuffer<DBuffer>::resize_buffer(uint32 size)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::resize_buffer(uint32 size)");
		LogTraceReturn(m_buffer.resize_buffer(size));
	}

	template <typename DBuffer>
	template <typename Compresser>
	inline RuntimeError PackBuffer<DBuffer>::compress(PackBuffer<DataBuffer> & dest)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::compress(PackBuffer<DataBuffer> & dest)");
		LogTraceReturn(Compresser::compress(*this, dest));
	}

	template <typename DBuffer>
	template <typename Compresser>
	inline RuntimeError PackBuffer<DBuffer>::uncompress(PackBuffer<DataBuffer> & dest)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::uncompress(PackBuffer<DataBuffer> & dest)");
		LogTraceReturn(Compresser::uncompress(*this, dest));
	}

	template <typename DBuffer>
	template <typename Encrypter>
	inline RuntimeError PackBuffer<DBuffer>::encrypt(PackBuffer<DataBuffer> & dest, const char * key, uint32 keyLen)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::encrypt(PackBuffer<DataBuffer> & dest, const char * key, uint32 keyLen)");
		LogTraceReturn(Encrypter::encrypt(*this, dest, key, keyLen));
	}

	template <typename DBuffer>
	template <typename Encrypter>
	inline RuntimeError PackBuffer<DBuffer>::decrypt(PackBuffer<DataBuffer> & dest, const char * key, uint32 keyLen)
	{
		LogTrace("RuntimeError PackBuffer<DBuffer>::decrypt(PackBuffer<DataBuffer> & dest, const char * key, uint32 keyLen)");
		LogTraceReturn(Encrypter::decrypt(*this, dest, key, keyLen));
	}

	
}

#endif