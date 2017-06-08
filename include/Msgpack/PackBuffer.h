



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
#ifndef LIGHTINK_MSGPACK_PACKBUFFER_H_
#define LIGHTINK_MSGPACK_PACKBUFFER_H_

#include "Common/RuntimeError.h"
#include "Msgpack/DataBuffer.h"

namespace LightInk
{
	template <typename DBuffer>
	class LIGHTINK_TEMPLATE_DECL PackBuffer
	{
	public:
		PackBuffer();
		PackBuffer(uint32 initSize);
		PackBuffer(const PackBuffer & cp);
		PackBuffer & operator = (const PackBuffer & right);
		virtual ~PackBuffer();
		virtual PackBuffer * clone();
		virtual PackBuffer * deep_clone();

		virtual bool release();

		void clear();
		char * data() const;

		uint32 size() const;
		uint32 buffer_size() const;
		uint32 free_size() const;

		void write_pos(uint32 pos);
		uint32 write_pos() const;
		void read_pos(uint32 pos);
		uint32 read_pos() const;

		RuntimeError write(const PackBuffer & data);

		RuntimeError write(const char * data, uint32 size);

		RuntimeError write(const signed char * data, uint32 size);

		RuntimeError write(const unsigned char * data, uint32 size);

		RuntimeError write(const std::string & data);

		template <typename T>
		RuntimeError pack(const T & data);

		RuntimeError read(PackBuffer & data);

		RuntimeError read(char * data, uint32 size);

		RuntimeError read(signed char * data, uint32 size);

		RuntimeError read(unsigned char * data, uint32 size);

		RuntimeError read(std::string & data, uint32 size);

		RuntimeError read(char ** data, uint32 size);

		template <typename T>
		RuntimeError unpack(T & data);

		template <typename T>
		PackBuffer & operator << (const T & data);

		template <typename T>
		PackBuffer & operator >> (T & data);

		RuntimeError resize_buffer(uint32 size);

		template <typename Compresser>
		RuntimeError compress(PackBuffer<DataBuffer> & dest);

		template <typename Compresser>
		RuntimeError uncompress(PackBuffer<DataBuffer> & dest);

		template <typename Encrypter>
		RuntimeError encrypt(PackBuffer<DataBuffer> & dest, const char * key, uint32 keyLen);

		template <typename Encrypter>
		RuntimeError decrypt(PackBuffer<DataBuffer> & dest, const char * key, uint32 keyLen);


	protected:
		DBuffer m_buffer;
		uint32 m_readPos;
	};

}


#include "Msgpack/PackBuffer.cpp"

#endif