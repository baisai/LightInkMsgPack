


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
#ifndef LIGHTINK_COMMON_RUNTIMEERROR_CPP_
#define LIGHTINK_COMMON_RUNTIMEERROR_CPP_

#include "Common/RuntimeError.h"



#define LIGHTINK_DEFINE_ERROR_DES(code, des) \
	template <> \
	const char * RuntimeErrorDes<code>::error = des


#define LIGHTINK_GET_ERROR_DES_BEGIN(name)\
LIGHTINK_GET_RUNTIMEERROR_DES_FUNC(name) \
{ \
	switch (e) \
	{ \

#define LIGHTINK_GET_ERROR_DES_END \
	default: \
	break; \
	} \
	return RuntimeErrorDes<RE_UnknownError>::error; \
} \

#define LIGHTINK_GET_ERROR_DES(code) \
case code:\
	return RuntimeErrorDes<code>::error;

namespace LightInk
{

	template<RuntimeError e>
	const char * RuntimeErrorDes<e>::error = "Undefined Error!!!";

	//错误描述
	LIGHTINK_DEFINE_ERROR_DES(RE_Success, "Sucess!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_ThreadSelfExit, "Thread Self Exit!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_UnknownError, "Error!!!Unknown --> Unknown Error!!!");


	LIGHTINK_DEFINE_ERROR_DES(RE_Msgpack_TypeError, "Error!!!Msgpack --> Type Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Msgpack_StringLenError, "Error!!!Msgpack --> String Length Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Msgpack_ArrayLenError, "Error!!!Msgpack --> Array Length Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Msgpack_MemoryNotEnoughError, "Error!!!Msgpack --> Memory Not Enough Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Msgpack_DataCompressedError, "Error!!!Msgpack --> Data Has Compressed or Uncompressed Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Msgpack_DataEncryptError, "Error!!!Msgpack --> Data Has Encrypt or Decrypt Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Msgpack_DataOutOfRangeError, "Error!!!Msgpack --> Data Is Out of Range Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Msgpack_EmptyData, "Error!!!Msgpack --> Data Is Empty!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Msgpack_DisableResize, "Error!!!Msgpack --> The Buffer Is FixLen, Disable Resize!!!");

	LIGHTINK_DEFINE_ERROR_DES(RE_Memory_MemoryNotEnoughError, "Error!!!Memory --> Memory Is Not Enought!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Memory_MemoryOutofRange, "Error!!!Memory --> Memory Is Outof Range!!!");

	LIGHTINK_DEFINE_ERROR_DES(RE_Def_DefObjectExists, "Error!!!Def --> This Def Message Already Exists!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Def_NotThisArgType, "Error!!!Def --> Not This Def Object ArgType!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Def_MapMust2Elem, "Error!!!Def --> Map Arg Must Have 2 Elem!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Def_NotRegisterOpcode, "Error!!!Def --> Not Register This Opcode!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Def_MessageLengthLess, "Error!!!Def --> The Data Of Message's Length Is Not Enough!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Def_ArrayNotPair, "Error!!!Def --> Array Tags Is Not Pair!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Def_MapNotPair, "Error!!!Def --> Map Tags Is Not Pair!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Def_ArrayNotLen, "Error!!!Def --> Array Need \"len\" field!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Def_ArraylenLess, "Error!!!Def --> Array 's Length Is Not Enough!!!");

	LIGHTINK_DEFINE_ERROR_DES(RE_Redis_Disconnect, "Error!!!Redis --> Redis Connect Disconnect!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Redis_ThisLinkBeUsed, "Error!!!Redis --> This Redis Link Have Be Already Used!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Redis_ThisLinkNotUsed, "Error!!!Redis --> This Redis Link Not Be Used!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Redis_NeedMoreData, "Error!!!Redis --> The Data Is Less, Need More Data!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Redis_DataHeadError, "Error!!!Redis --> The Data Head Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Redis_DataTypeError, "Error!!!Redis --> The Data Type Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Redis_DataDeepError, "Error!!!Redis --> The Data Deep Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Redis_ReplyOutOfRange, "Error!!!Redis --> The Reply Is Out Of Range!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Redis_AlreadyHaveReply, "Error!!!Redis --> The Reply Already Have Data!!!");

	LIGHTINK_DEFINE_ERROR_DES(RE_Leveldb_OperatorFailed, "Error!!!Leveldb --> Operator Failed \"get_last_error\" Get More Info!!!");



	//错误代码和错误描述映射
	LIGHTINK_GET_ERROR_DES_BEGIN(get_runtime_error)


	LIGHTINK_GET_ERROR_DES(RE_Success)
	LIGHTINK_GET_ERROR_DES(RE_ThreadSelfExit)
	LIGHTINK_GET_ERROR_DES(RE_UnknownError)

	LIGHTINK_GET_ERROR_DES(RE_Msgpack_TypeError)
	LIGHTINK_GET_ERROR_DES(RE_Msgpack_StringLenError)
	LIGHTINK_GET_ERROR_DES(RE_Msgpack_ArrayLenError)
	LIGHTINK_GET_ERROR_DES(RE_Msgpack_MemoryNotEnoughError)
	LIGHTINK_GET_ERROR_DES(RE_Msgpack_DataCompressedError)
	LIGHTINK_GET_ERROR_DES(RE_Msgpack_DataEncryptError)
	LIGHTINK_GET_ERROR_DES(RE_Msgpack_DataOutOfRangeError)
	LIGHTINK_GET_ERROR_DES(RE_Msgpack_EmptyData)
	LIGHTINK_GET_ERROR_DES(RE_Msgpack_DisableResize)


	LIGHTINK_GET_ERROR_DES(RE_Memory_MemoryNotEnoughError)
	LIGHTINK_GET_ERROR_DES(RE_Memory_MemoryOutofRange)


	LIGHTINK_GET_ERROR_DES(RE_Def_DefObjectExists)
	LIGHTINK_GET_ERROR_DES(RE_Def_NotThisArgType)
	LIGHTINK_GET_ERROR_DES(RE_Def_MapMust2Elem)
	LIGHTINK_GET_ERROR_DES(RE_Def_NotRegisterOpcode)
	LIGHTINK_GET_ERROR_DES(RE_Def_MessageLengthLess)
	LIGHTINK_GET_ERROR_DES(RE_Def_ArrayNotPair)
	LIGHTINK_GET_ERROR_DES(RE_Def_MapNotPair)
	LIGHTINK_GET_ERROR_DES(RE_Def_ArrayNotLen)
	LIGHTINK_GET_ERROR_DES(RE_Def_ArraylenLess)

	LIGHTINK_GET_ERROR_DES(RE_Redis_Disconnect)
	LIGHTINK_GET_ERROR_DES(RE_Redis_ThisLinkBeUsed)
	LIGHTINK_GET_ERROR_DES(RE_Redis_ThisLinkNotUsed)
	LIGHTINK_GET_ERROR_DES(RE_Redis_NeedMoreData)
	LIGHTINK_GET_ERROR_DES(RE_Redis_DataHeadError)
	LIGHTINK_GET_ERROR_DES(RE_Redis_DataTypeError)
	LIGHTINK_GET_ERROR_DES(RE_Redis_DataDeepError)
	LIGHTINK_GET_ERROR_DES(RE_Redis_ReplyOutOfRange)
	LIGHTINK_GET_ERROR_DES(RE_Redis_AlreadyHaveReply)

	LIGHTINK_GET_ERROR_DES(RE_Leveldb_OperatorFailed)

	LIGHTINK_GET_ERROR_DES_END

	LIGHTINK_GET_RUNTIMEERROR_DES_FUNC_INT(get_runtime_error_int)
	{
		return get_runtime_error((RuntimeError)e);
	}
}

#undef LIGHTINK_DEFINE_ERROR_DES
#undef LIGHTINK_GET_ERROR_DES_BEGIN
#undef LIGHTINK_GET_ERROR_DES
#undef LIGHTINK_GET_ERROR_DES_END

#endif