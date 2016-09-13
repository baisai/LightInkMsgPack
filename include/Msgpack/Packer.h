


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

#ifndef LIGHTINK_MSGPACK_PACKER_H_

#define LIGHTINK_MSGPACK_PACKER_H_

#include "Sysdep.h"
#include "PackBuffer.h"
#include "DataBuffer.h"

namespace LightInk
{
	template <typename TBuffer>
	class LIGHTINK_TEMPLATE_DECL Packer
	{
	public:
		Packer();
		Packer(TBuffer* b);
		Packer(TBuffer& b);
		void set_buffer(TBuffer * b);
		void set_buffer(TBuffer & b);
		TBuffer * get_buffer();

	public:
		RuntimeError pack_uint8(uint8 d){ LogTrace("RuntimeError pack_uint8(uint8 d)"); LogTraceReturn(pack_uint8(*m_buffer, d)); }
		RuntimeError pack_uint16(uint16 d) { LogTrace("RuntimeError pack_uint16(uint16 d)"); LogTraceReturn(pack_uint16(*m_buffer, d)); }
		RuntimeError pack_uint32(uint32 d) { LogTrace("RuntimeError pack_uint32(uint32 d)"); LogTraceReturn(pack_uint32(*m_buffer, d)); }
		RuntimeError pack_uint64(uint64 d) { LogTrace("RuntimeError pack_uint64(uint64 d)"); LogTraceReturn(pack_uint64(*m_buffer, d)); }
		RuntimeError pack_int8(int8 d) { LogTrace("RuntimeError pack_int8(int8 d)"); LogTraceReturn(pack_int8(*m_buffer ,d)); }
		RuntimeError pack_int16(int16 d) { LogTrace("RuntimeError pack_int16(int16 d)"); LogTraceReturn(pack_int16(*m_buffer, d)); }
		RuntimeError pack_int32(int32 d) { LogTrace("RuntimeError pack_int32(int32 d)"); LogTraceReturn(pack_int32(*m_buffer, d)); }
		RuntimeError pack_int64(int64 d) { LogTrace("RuntimeError pack_int64(int64 d)"); LogTraceReturn(pack_int64(*m_buffer, d)); }

		RuntimeError pack_fix_uint8(uint8 d) { LogTrace("RuntimeError pack_fix_uint8(uint8 d)"); LogTraceReturn(pack_fix_uint8(*m_buffer, d)); }
		RuntimeError pack_fix_uint16(uint16 d) { LogTrace("RuntimeError pack_fix_uint16(uint16 d)"); LogTraceReturn(pack_fix_uint16(*m_buffer, d)); }
		RuntimeError pack_fix_uint32(uint32 d) { LogTrace("RuntimeError pack_fix_uint32(uint32 d)"); LogTraceReturn(pack_fix_uint32(*m_buffer, d)); }
		RuntimeError pack_fix_uint64(uint64 d) { LogTrace("RuntimeError pack_fix_uint64(uint64 d)"); LogTraceReturn(pack_fix_uint64(*m_buffer, d)); }
		RuntimeError pack_fix_int8(int8 d) { LogTrace("RuntimeError pack_fix_int8(int8 d)"); LogTraceReturn(pack_fix_int8(*m_buffer, d)); }
		RuntimeError pack_fix_int16(int16 d) { LogTrace("RuntimeError pack_fix_int16(int16 d)"); LogTraceReturn(pack_fix_int16(*m_buffer, d)); }
		RuntimeError pack_fix_int32(int32 d) { LogTrace("RuntimeError pack_fix_int32(int32 d)"); LogTraceReturn(pack_fix_int32(*m_buffer, d)); }
		RuntimeError pack_fix_int64(int64 d) { LogTrace("RuntimeError pack_fix_int64(int64 d)"); LogTraceReturn(pack_fix_int64(*m_buffer, d)); }

		RuntimeError pack_char(char d) { LogTrace("RuntimeError pack_char(char d)"); LogTraceReturn(pack_char(*m_buffer, d)); }
		RuntimeError pack_signed_char(signed char d) { LogTrace("RuntimeError pack_signed_char(signed char d)"); LogTraceReturn(pack_signed_char(*m_buffer, d)); }
		RuntimeError pack_short(short d)  { LogTrace("RuntimeError pack_short(short d)"); LogTraceReturn(pack_short(*m_buffer, d)); }
		RuntimeError pack_int(int d) { LogTrace("RuntimeError pack_int(int d)"); LogTraceReturn(pack_int(*m_buffer, d)); }
		RuntimeError pack_long(long d) { LogTrace("RuntimeError pack_long(long d)"); LogTraceReturn(pack_long(*m_buffer, d)); }
		RuntimeError pack_long_long(long long d) { LogTrace("RuntimeError pack_long_long(long long d)"); LogTraceReturn(pack_long_long(*m_buffer, d)); }
		RuntimeError pack_unsigned_char(unsigned char d) { LogTrace("RuntimeError pack_unsigned_char(unsigned char d)"); LogTraceReturn(pack_unsigned_char(*m_buffer, d)); }
		RuntimeError pack_unsigned_short(unsigned short d) { LogTrace("RuntimeError pack_unsigned_short(unsigned short d)"); LogTraceReturn(pack_unsigned_short(*m_buffer, d)); }
		RuntimeError pack_unsigned_int(unsigned int d) { LogTrace("RuntimeError pack_unsigned_int(unsigned int d)"); LogTraceReturn(pack_unsigned_int(*m_buffer, d)); }
		RuntimeError pack_unsigned_long(unsigned long d) { LogTrace("RuntimeError pack_unsigned_long(unsigned long d)"); LogTraceReturn(pack_unsigned_long(*m_buffer, d)); }
		RuntimeError pack_unsigned_long_long(unsigned long long d) { LogTrace("RuntimeError pack_unsigned_long_long(unsigned long long d)"); LogTraceReturn(pack_unsigned_long_long(*m_buffer, d)); }

		RuntimeError pack_float(float d) { LogTrace("RuntimeError pack_float(float d)"); LogTraceReturn(pack_float(*m_buffer, d)); }
		RuntimeError pack_double(double d) { LogTrace("RuntimeError pack_double(double d)"); LogTraceReturn(pack_double(*m_buffer, d)); }

		RuntimeError pack_nil() { LogTrace("RuntimeError pack_nil()"); LogTraceReturn(pack_nil(*m_buffer)); }
		RuntimeError pack_bool(bool d) { LogTrace("RuntimeError pack_bool(bool d)"); LogTraceReturn(pack_bool(*m_buffer, d)); }

		RuntimeError pack_array(uint32 n) { LogTrace("RuntimeError pack_array(uint32 n)"); LogTraceReturn(pack_array(*m_buffer, n)); }

		RuntimeError pack_map(uint32 n) { LogTrace("RuntimeError pack_map(uint32 n)"); LogTraceReturn(pack_map(*m_buffer, n)); }

		RuntimeError pack_str(uint32 l) { LogTrace("RuntimeError pack_str(uint32 l)"); LogTraceReturn(pack_str(*m_buffer, l)); }
		RuntimeError pack_str_body(const char* b, uint32 l) { LogTrace("RuntimeError pack_str_body(const char* b, uint32 l)"); LogTraceReturn(pack_str_body(*m_buffer, b, l)); }

		RuntimeError pack_str_string(const std::string & s) { LogTrace("RuntimeError pack_str_string(const std::string & s)"); LogTraceReturn(pack_str_string(*m_buffer, s)); }

		RuntimeError pack_bin(uint32 l) { LogTrace("RuntimeError pack_bin(uint32 l)"); LogTraceReturn(pack_bin(*m_buffer, l)); }
		RuntimeError pack_bin_body(const char* b, uint32 l) { LogTrace("RuntimeError pack_bin_body(const char* b, uint32 l)"); LogTraceReturn(pack_bin_body(*m_buffer, b, l)); }

		RuntimeError pack_ext(uint32 l, int8 type) { LogTrace("RuntimeError pack_ext(uint32 l, int8 type)"); LogTraceReturn(pack_ext(*m_buffer, l, type)); }
		RuntimeError pack_ext_body(const char* b, uint32 l) { LogTrace("RuntimeError pack_ext_body(const char* b, uint32 l)"); LogTraceReturn(pack_ext_body(*m_buffer, b, l)); }
	public: //static func

		static RuntimeError pack_uint8(TBuffer & buffer, uint8 d);
		static RuntimeError pack_uint16(TBuffer & buffer, uint16 d);
		static RuntimeError pack_uint32(TBuffer & buffer, uint32 d);
		static RuntimeError pack_uint64(TBuffer & buffer, uint64 d);
		static RuntimeError pack_int8(TBuffer & buffer, int8 d);
		static RuntimeError pack_int16(TBuffer & buffer, int16 d);
		static RuntimeError pack_int32(TBuffer & buffer, int32 d);
		static RuntimeError pack_int64(TBuffer & buffer, int64 d);

		static RuntimeError pack_fix_uint8(TBuffer & buffer, uint8 d);
		static RuntimeError pack_fix_uint16(TBuffer & buffer, uint16 d);
		static RuntimeError pack_fix_uint32(TBuffer & buffer, uint32 d);
		static RuntimeError pack_fix_uint64(TBuffer & buffer, uint64 d);
		static RuntimeError pack_fix_int8(TBuffer & buffer, int8 d);
		static RuntimeError pack_fix_int16(TBuffer & buffer, int16 d);
		static RuntimeError pack_fix_int32(TBuffer & buffer, int32 d);
		static RuntimeError pack_fix_int64(TBuffer & buffer, int64 d);

		static RuntimeError pack_char(TBuffer & buffer, char d);
		static RuntimeError pack_signed_char(TBuffer & buffer, signed char d);
		static RuntimeError pack_short(TBuffer & buffer, short d);
		static RuntimeError pack_int(TBuffer & buffer, int d);
		static RuntimeError pack_long(TBuffer & buffer, long d);
		static RuntimeError pack_long_long(TBuffer & buffer, long long d);
		static RuntimeError pack_unsigned_char(TBuffer & buffer, unsigned char d);
		static RuntimeError pack_unsigned_short(TBuffer & buffer, unsigned short d);
		static RuntimeError pack_unsigned_int(TBuffer & buffer, unsigned int d);
		static RuntimeError pack_unsigned_long(TBuffer & buffer, unsigned long d);
		static RuntimeError pack_unsigned_long_long(TBuffer & buffer, unsigned long long d);

		static RuntimeError pack_float(TBuffer & buffer, float d);
		static RuntimeError pack_double(TBuffer & buffer, double d);

		static RuntimeError pack_nil(TBuffer & buffer);
		static RuntimeError pack_bool(TBuffer & buffer, bool d);

		static RuntimeError pack_array(TBuffer & buffer, uint32 n);

		static RuntimeError pack_map(TBuffer & buffer, uint32 n);

		static RuntimeError pack_str(TBuffer & buffer, uint32 l);
		static RuntimeError pack_str_body(TBuffer & buffer, const char * b, uint32 l);

		static RuntimeError pack_str_string(TBuffer & buffer, const std::string & s);

		static RuntimeError pack_bin(TBuffer & buffer, uint32 l);
		static RuntimeError pack_bin_body(TBuffer & buffer, const char * b, uint32 l);

		static RuntimeError pack_ext(TBuffer & buffer, uint32 l, int8 type);
		static RuntimeError pack_ext_body(TBuffer & buffer, const char * b, uint32 l);

	private:
		template <typename T>
		static RuntimeError pack_imp_uint8(TBuffer & buffer, T d);

		template <typename T>
		static RuntimeError pack_imp_uint16(TBuffer & buffer,T d);

		template <typename T>
		static RuntimeError pack_imp_uint32(TBuffer & buffer,T d);

		template <typename T>
		static RuntimeError pack_imp_uint64(TBuffer & buffer,T d);

		template <typename T>
		static RuntimeError pack_imp_int8(TBuffer & buffer,T d);

		template <typename T>
		static RuntimeError pack_imp_int16(TBuffer & buffer,T d);

		template <typename T>
		static RuntimeError pack_imp_int32(TBuffer & buffer,T d);

		template <typename T>
		static RuntimeError pack_imp_int64(TBuffer & buffer,T d);

#if defined(__LITTLE_ENDIAN__)
		template <typename T>
		inline static char take8_8(T d) {
			LogTrace("char take8_8(T d)"); 
			LogTraceReturn(static_cast<char>(reinterpret_cast<uint8*>(&d)[0]));
		}
		template <typename T>
		inline static char take8_16(T d) {
			LogTrace("char take8_16(T d"); 
			LogTraceReturn(static_cast<char>(reinterpret_cast<uint8*>(&d)[0]));
		}
		template <typename T>
		inline static char take8_32(T d) {
			LogTrace("char take8_32(T d)"); 
			LogTraceReturn(static_cast<char>(reinterpret_cast<uint8*>(&d)[0]));
		}
		template <typename T>
		inline static char take8_64(T d) {
			LogTrace("char take8_64(T d)"); 
			LogTraceReturn(static_cast<char>(reinterpret_cast<uint8*>(&d)[0]));
		}

#elif defined(__BIG_ENDIAN__)

		template <typename T>
		inline static char take8_8(T d) {
			LogTrace("char take8_8(T d)"); 
			LogTraceReturn(static_cast<char>(reinterpret_cast<uint8*>(&d)[0]));
		}
		template <typename T>
		inline static char take8_16(T d) {
			LogTrace("char take8_16(T d)"); 
			LogTraceReturn(static_cast<char>(reinterpret_cast<uint8*>(&d)[1]));
		}
		template <typename T>
		inline static char take8_32(T d) {
			LogTrace("char take8_32(T d)"); 
			LogTraceReturn(static_cast<char>(reinterpret_cast<uint8*>(&d)[3]));
		}
		template <typename T>
		inline static char take8_64(T d) {
			LogTrace("char take8_64(T d)"); 
			LogTraceReturn(static_cast<char>(reinterpret_cast<uint8*>(&d)[7]));
		}

#endif

	private:
		TBuffer * m_buffer;

	LIGHTINK_DISABLE_COPY(Packer)
	};

	template <typename TBuffer, typename T>
	RuntimeError pack(TBuffer & buffer, const T & v);


}

#include "Packer.cpp"
#include "PackerAdaptor.cpp"

#endif
