


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

#ifndef LIGHTINK_COMMON_RUNTIMEERROR_H_
#define LIGHTINK_COMMON_RUNTIMEERROR_H_
#include <stddef.h>
#include "Common/Type.h"

#define LIGHTINK_GET_RUNTIMEERROR_DES_FUNC(name) \
const char * name(RuntimeError e)

#define LIGHTINK_GET_RUNTIMEERROR_DES_FUNC_INT(name) \
const char * name(int e)

namespace LightInk
{
	//错误代码
	enum RuntimeError
	{
		RE_Success = 0,
		RE_ThreadSelfExit = 1,
		RE_UnknownError = 2,

		RE_Log_HaveInited,
		RE_Log_FileFailed,
		RE_Log_WriteChannelFailed,
		RE_Log_FlushChannelFailed,
		RE_Log_LogFailed,
		RE_Log_LoggerNameExist,

		RE_Msgpack_TypeError,
		RE_Msgpack_StringLenError,
		RE_Msgpack_ArrayLenError,
		RE_Msgpack_MemoryNotEnoughError,
		RE_Msgpack_DataCompressedError,
		RE_Msgpack_DataEncryptError,
		RE_Msgpack_DataOutOfRangeError,
		RE_Msgpack_EmptyData,
		RE_Msgpack_DisableResize,

		RE_Memory_MemoryNotEnoughError,
		RE_Memory_MemoryOutofRange,

		RE_Reactor_DoNotInit,
		RE_Reactor_DoNotHaveFree,
		RE_Reactor_SubReactorOutOfRange,
		RE_Reactor_CacheQueueExists,
		RE_Reactor_CacheQueueNotExists,
		RE_Reactor_LinkDisableSendMessage,
		RE_Reactor_HaveInited,
		RE_Reactor_ReactorClosing,
		RE_Reactor_NotThisLink,
		RE_Reactor_NotThisWaitLink,
		RE_Reactor_RouterError,
		RE_Reactor_FromLinkTypeError,
		RE_Reactor_NotLinkRouter,
		RE_Reactor_LinkInvalid,
		RE_Reactor_LinkExecInvalid,
		RE_Reactor_LinkCountMax,
		RE_Reactor_LinkNotLogin,
		RE_Reactor_MessageTooBig,
		RE_Reactor_LinkCacheMax,
		RE_Reactor_NewLinkFailed,

		RE_RawProtocol_LengthMax,
		RE_RawProtocol_Error,
		RE_RawProtocol_CompressEncryptError,

		RE_Lua_ThisStateInited,
		RE_Lua_NewStateFailed,
		RE_Lua_StringEmpty,
		RE_Lua_RuntimeError,
		RE_Lua_TheDataIsNil,
		RE_Lua_StackTopNotTable,
		RE_Lua_ClassNotRegister,
		RE_Lua_HaveLoadedConfig,
		RE_Lua_HaveNoLoadedConfig,
		RE_Lua_TypeError,
		RE_Lua_ConfigCommentError,
		RE_Lua_LuaEngineNotInit,
		RE_Lua_CheckConfigError,

		RE_MessageQueue_HaveInited,
		RE_MessageQueue_NotActived,
		RE_MessageQueue_MessageHandleExists,
		RE_MessageQueue_MessageHandleNotExists,
		RE_MessageQueue_Full,
		RE_MessageQueue_PumpClose,

		RE_Def_DefObjectExists,
		RE_Def_NotThisArgType,
		RE_Def_MapMust2Elem,
		RE_Def_NotRegisterOpcode,
		RE_Def_MessageLengthLess,
		RE_Def_ArrayNotPair,
		RE_Def_MapNotPair,
		RE_Def_ArrayNotLen,
		RE_Def_ArraylenLess,

		RE_Redis_Disconnect,
		RE_Redis_ThisLinkBeUsed,
		RE_Redis_ThisLinkNotUsed,
		RE_Redis_NeedMoreData,
		RE_Redis_DataHeadError,
		RE_Redis_DataTypeError,
		RE_Redis_DataDeepError,
		RE_Redis_ReplyOutOfRange,
		RE_Redis_AlreadyHaveReply,

		RE_Mongo_JsonError,
		RE_Mongo_BsonTypeError,
		RE_Mongo_BsonAppendFaild,
		RE_Mongo_DatabaseMongoInited,
		RE_Mongo_DoNotSelectDb,
		RE_Mongo_RuntimeError,

		RE_Runner_Exiting,
		RE_Runner_OpenFileFailed,
		RE_Runner_WriteFileFailed,
		RE_Runner_ObjectIsNULL,
		RE_Runner_NotLuaConfig,

		RE_Http_RequestCMDError,
		RE_Http_ProtocolError,
		RE_Http_StatusCodeNotExists,
		RE_Http_NotSupportWebSocket,
		RE_Http_ParserFailed,
		RE_Http_IsNotRequest,
		RE_Http_IsNotResponse,
		RE_Http_ReplyIsNULL,

		RE_Leveldb_OperatorFailed,

		RE_Mysql_DatabaseMysqlInited,
		RE_Mysql_RuntimeError,
	};


	template <RuntimeError e>
	struct LIGHTINK_TEMPLATE_DECL RuntimeErrorDes
	{
		enum { ErrorCode = e };
		static const char * error;
	};


	LIGHTINK_DECL LIGHTINK_GET_RUNTIMEERROR_DES_FUNC(get_runtime_error);
	LIGHTINK_DECL LIGHTINK_GET_RUNTIMEERROR_DES_FUNC_INT(get_runtime_error_int);
}



#endif