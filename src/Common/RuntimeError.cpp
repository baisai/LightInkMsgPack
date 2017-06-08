


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

	LIGHTINK_DEFINE_ERROR_DES(RE_Log_HaveInited, "Error!!!Log --> LogMsg Have Inited!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Log_FileFailed, "Error!!!Log --> LogMsg Open File Failed!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Log_WriteChannelFailed, "Error!!!Log --> LogMsg Write Channel Failed!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Log_FlushChannelFailed, "Error!!!Log --> LogMsg Flush Channel Failed!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Log_LogFailed, "Error!!!Log --> LogMsg Log Failed!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Log_LoggerNameExist, "Error!!!Log --> LogMsg This Logger Name Is Exist!!!");

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

	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_DoNotInit, "Error!!!Reactor --> Reactor Is Not Inited!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_DoNotHaveFree, "Error!!!Reactor --> Reactor Do Not Have Free Reactor!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_SubReactorOutOfRange, "Error!!!Reactor --> Sub Reactor Out Of Range!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_CacheQueueExists, "Error!!!Reactor --> The Cache Queue Exists!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_CacheQueueNotExists, "Error!!!Reactor --> The Cache Queue Not Exists!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_LinkDisableSendMessage, "Error!!!Reactor --> The Link Disable SendMessage");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_HaveInited, "Error!!!Reactor --> The Reactor Is Inited!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_ReactorClosing, "Error!!!Reactor --> The Reactor Is Closing!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_NotThisLink, "Error!!!Reactor --> This Link Is Not Exists!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_NotThisWaitLink, "Error!!!Reactor --> This Wait Link Is Not Exists!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_RouterError, "Error!!!Reactor --> The MessagePacket Router Is Not This Server!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_FromLinkTypeError, "Error!!!Reactor --> The MessagePacket's From Link Type Is Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_NotLinkRouter, "Error!!!Reactor --> The Link Router Info Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_LinkInvalid, "Error!!!Reactor --> The Link Is Invalid!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_LinkExecInvalid, "Error!!!Reactor --> The LinkExec Is Invalid!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_LinkCountMax, "Error!!!Reactor --> The Link Count Max!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_LinkNotLogin, "Error!!!Reactor --> The Link Is Not Login!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_MessageTooBig, "Error!!!Reactor --> The Message Too Big!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_LinkCacheMax, "Error!!!Reactor --> The Link Cache Frame Data Max!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Reactor_NewLinkFailed, "Error!!!Reactor --> New Link Failed!!!");

	LIGHTINK_DEFINE_ERROR_DES(RE_RawProtocol_LengthMax, "Error!!!RawProtocol --> Message Length Max!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_RawProtocol_Error, "Error!!!RawProtocol --> Message Protocol Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_RawProtocol_CompressEncryptError, "Error!!!RawProtocol --> Message Protocol Compress or Encrypt Error!!!");

	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_ThisStateInited, "Error!!!Lua --> This Lua State Has Already Init!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_NewStateFailed, "Error!!!Lua --> New Lua State Failed!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_StringEmpty, "Error!!!Lua --> Lua Call Arg Is Empty String!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_RuntimeError, "Error!!!Lua --> Lua Runtime Error, The Error Info Look Script Error Info!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_TheDataIsNil, "Error!!!Lua --> Lua The Data Is Nil!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_StackTopNotTable, "Error!!!Lua --> The Lua Stack Top Is Not A Table!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_ClassNotRegister, "Error!!!Lua --> The Class Not Register!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_HaveLoadedConfig, "Error!!!Lua --> Have Loaded Config!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_HaveNoLoadedConfig, "Error!!!Lua --> Have No Loaded Config!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_TypeError, "Error!!!Lua --> Lua Object Type Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_ConfigCommentError, "Error!!!Lua --> The Config Comment Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_LuaEngineNotInit, "Error!!!Lua --> The Lua Engine Is Not Inited!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Lua_CheckConfigError, "Error!!!Lua --> Check Server Config Error!!!Config Have Some Problem!!!");

	LIGHTINK_DEFINE_ERROR_DES(RE_MessageQueue_HaveInited,"Error!!!MessageQueue --> The MessageQueue Have Inited!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_MessageQueue_NotActived,"Error!!!MessageQueue --> The MessageQueue Not Actived!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_MessageQueue_MessageHandleExists, "Error!!!MessageQueue -- > The MessageHandle Exists!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_MessageQueue_MessageHandleNotExists, "Error!!!MessageQueue -- > Not Register this MessageHandle Opcode And Not Register MessageUnhandle!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_MessageQueue_Full, "Error!!!MessageQueue --> This MessageQueue Is Full!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_MessageQueue_PumpClose, "Error!!!MessageQueue --> The Pump Is Closed!!!");

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

	LIGHTINK_DEFINE_ERROR_DES(RE_Mongo_JsonError, "Error!!!Mongo --> Json Format Is Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Mongo_BsonTypeError, "Error!!!Mongo --> Bson Value Type Is Errorr!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Mongo_BsonAppendFaild, "Error!!!Mongo --> Bson Append Value Faild!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Mongo_DatabaseMongoInited, "Error!!!Mongo --> Database Mongo Have Inited!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Mongo_DoNotSelectDb, "Error!!!Mongo --> You Do Not Select Db!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Mongo_RuntimeError, "Error!!!Mongo --> Runtime Error!!!");

	LIGHTINK_DEFINE_ERROR_DES(RE_Runner_Exiting, "Error!!!Runner --> The Program is exiting!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Runner_OpenFileFailed, "Error!!!Runner --> Open File Failed!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Runner_WriteFileFailed, "Error!!!Runner --> Write File Failed!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Runner_ObjectIsNULL, "Error!!!Runner --> The Object Is NULL!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Runner_NotLuaConfig, "Error!!!Runner --> Not Lua Config!!!");

	LIGHTINK_DEFINE_ERROR_DES(RE_Http_RequestCMDError, "Error!!!Http --> Request CMD Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Http_ProtocolError, "Error!!!Http --> Protocol Error!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Http_StatusCodeNotExists, "Error!!!Http --> Status Code Not Exists!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Http_NotSupportWebSocket, "Error!!!Http --> This Protocol Not Support Web Socket!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Http_ParserFailed, "Error!!!Http --> Parser Failed!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Http_IsNotRequest, "Error!!!Http --> This is Not Request!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Http_IsNotResponse, "Error!!!Http --> This is Not Response!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Http_ReplyIsNULL, "Error!!!Http --> This Protocol Reply Is NULL!!!");

	LIGHTINK_DEFINE_ERROR_DES(RE_Leveldb_OperatorFailed, "Error!!!Leveldb --> Operator Failed \"get_last_error\" Get More Info!!!");

	LIGHTINK_DEFINE_ERROR_DES(RE_Mysql_DatabaseMysqlInited, "Error!!!Mysql --> Database Mysql Have Inited!!!");
	LIGHTINK_DEFINE_ERROR_DES(RE_Mysql_RuntimeError, "Error!!!Mysql --> Runtime Error!!!");



	//错误代码和错误描述映射
	LIGHTINK_GET_ERROR_DES_BEGIN(get_runtime_error)


	LIGHTINK_GET_ERROR_DES(RE_Success)
	LIGHTINK_GET_ERROR_DES(RE_ThreadSelfExit)
	LIGHTINK_GET_ERROR_DES(RE_UnknownError)

	LIGHTINK_GET_ERROR_DES(RE_Log_HaveInited)
	LIGHTINK_GET_ERROR_DES(RE_Log_FileFailed)
	LIGHTINK_GET_ERROR_DES(RE_Log_WriteChannelFailed)
	LIGHTINK_GET_ERROR_DES(RE_Log_FlushChannelFailed)
	LIGHTINK_GET_ERROR_DES(RE_Log_LogFailed)
	LIGHTINK_GET_ERROR_DES(RE_Log_LoggerNameExist)

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

	LIGHTINK_GET_ERROR_DES(RE_Reactor_DoNotInit)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_DoNotHaveFree)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_SubReactorOutOfRange)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_CacheQueueExists)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_CacheQueueNotExists)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_LinkDisableSendMessage)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_HaveInited)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_ReactorClosing)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_NotThisLink)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_NotThisWaitLink)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_RouterError)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_FromLinkTypeError)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_NotLinkRouter)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_LinkInvalid)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_LinkExecInvalid)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_LinkCountMax)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_LinkNotLogin)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_MessageTooBig)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_LinkCacheMax)
	LIGHTINK_GET_ERROR_DES(RE_Reactor_NewLinkFailed)

	LIGHTINK_GET_ERROR_DES(RE_RawProtocol_LengthMax)
	LIGHTINK_GET_ERROR_DES(RE_RawProtocol_Error)
	LIGHTINK_GET_ERROR_DES(RE_RawProtocol_CompressEncryptError)

	LIGHTINK_GET_ERROR_DES(RE_Lua_ThisStateInited)
	LIGHTINK_GET_ERROR_DES(RE_Lua_NewStateFailed)
	LIGHTINK_GET_ERROR_DES(RE_Lua_StringEmpty)
	LIGHTINK_GET_ERROR_DES(RE_Lua_RuntimeError)
	LIGHTINK_GET_ERROR_DES(RE_Lua_TheDataIsNil)
	LIGHTINK_GET_ERROR_DES(RE_Lua_StackTopNotTable)
	LIGHTINK_GET_ERROR_DES(RE_Lua_ClassNotRegister)
	LIGHTINK_GET_ERROR_DES(RE_Lua_HaveLoadedConfig)
	LIGHTINK_GET_ERROR_DES(RE_Lua_HaveNoLoadedConfig)
	LIGHTINK_GET_ERROR_DES(RE_Lua_TypeError)
	LIGHTINK_GET_ERROR_DES(RE_Lua_ConfigCommentError)
	LIGHTINK_GET_ERROR_DES(RE_Lua_LuaEngineNotInit)
	LIGHTINK_GET_ERROR_DES(RE_Lua_CheckConfigError)

	LIGHTINK_GET_ERROR_DES(RE_MessageQueue_HaveInited)
	LIGHTINK_GET_ERROR_DES(RE_MessageQueue_NotActived)
	LIGHTINK_GET_ERROR_DES(RE_MessageQueue_MessageHandleExists)
	LIGHTINK_GET_ERROR_DES(RE_MessageQueue_MessageHandleNotExists)
	LIGHTINK_GET_ERROR_DES(RE_MessageQueue_Full)
	LIGHTINK_GET_ERROR_DES(RE_MessageQueue_PumpClose)

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

	LIGHTINK_GET_ERROR_DES(RE_Mongo_JsonError)
	LIGHTINK_GET_ERROR_DES(RE_Mongo_BsonTypeError)
	LIGHTINK_GET_ERROR_DES(RE_Mongo_BsonAppendFaild)
	LIGHTINK_GET_ERROR_DES(RE_Mongo_DatabaseMongoInited)
	LIGHTINK_GET_ERROR_DES(RE_Mongo_DoNotSelectDb)
	LIGHTINK_GET_ERROR_DES(RE_Mongo_RuntimeError)

	LIGHTINK_GET_ERROR_DES(RE_Runner_Exiting)
	LIGHTINK_GET_ERROR_DES(RE_Runner_OpenFileFailed)
	LIGHTINK_GET_ERROR_DES(RE_Runner_WriteFileFailed)
	LIGHTINK_GET_ERROR_DES(RE_Runner_ObjectIsNULL)
	LIGHTINK_GET_ERROR_DES(RE_Runner_NotLuaConfig)

	LIGHTINK_GET_ERROR_DES(RE_Http_RequestCMDError)
	LIGHTINK_GET_ERROR_DES(RE_Http_ProtocolError)
	LIGHTINK_GET_ERROR_DES(RE_Http_StatusCodeNotExists)
	LIGHTINK_GET_ERROR_DES(RE_Http_NotSupportWebSocket)
	LIGHTINK_GET_ERROR_DES(RE_Http_ParserFailed)
	LIGHTINK_GET_ERROR_DES(RE_Http_IsNotRequest)
	LIGHTINK_GET_ERROR_DES(RE_Http_IsNotResponse)
	LIGHTINK_GET_ERROR_DES(RE_Http_ReplyIsNULL)

	LIGHTINK_GET_ERROR_DES(RE_Leveldb_OperatorFailed)

	LIGHTINK_GET_ERROR_DES(RE_Mysql_DatabaseMysqlInited)
	LIGHTINK_GET_ERROR_DES(RE_Mysql_RuntimeError)


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