/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2012, ruki All rights reserved.
 *
 * @author		ruki
 * @file		prefix.h
 *
 */
#ifndef TB_STREAM_PREFIX_H
#define TB_STREAM_PREFIX_H

/* ///////////////////////////////////////////////////////////////////////
 * includes
 */
#include "../prefix.h"
#include "../libc/libc.h"
#include "../network/url.h"

/* ///////////////////////////////////////////////////////////////////////
 * macros
 */

/// the stream ctrl
#define TB_STREAM_CTRL(type, ctrl) 								(((type) << 16) | (ctrl))
#define TB_STREAM_CTRL_FLTR(type, ctrl) 						TB_STREAM_CTRL(TB_STREAM_TYPE_FLTR, (((type) << 8) | (ctrl)))

/// the stream state
#define TB_STREAM_STATE(type, state) 							(((type) << 16) | (state))

/* ///////////////////////////////////////////////////////////////////////
 * types
 */

/// the stream mode enum
typedef enum __tb_stream_mode_e
{
	TB_STREAM_MODE_NONE 	= 0
,	TB_STREAM_MODE_AIOO 	= 1 ///!< for gstream
,	TB_STREAM_MODE_AICO 	= 2 ///!< for astream

}tb_stream_mode_e;

/// the stream type enum
typedef enum __tb_stream_type_e
{
 	TB_STREAM_TYPE_NONE 	= 0
, 	TB_STREAM_TYPE_FILE 	= 1
, 	TB_STREAM_TYPE_SOCK 	= 2
, 	TB_STREAM_TYPE_HTTP 	= 3
, 	TB_STREAM_TYPE_DATA 	= 4
, 	TB_STREAM_TYPE_FLTR 	= 5

}tb_stream_type_e;

/// the stream ctrl enum
typedef enum __tb_stream_ctrl_e
{
	TB_STREAM_CTRL_NONE 					= 0

	// the stream
,	TB_STREAM_CTRL_GET_URL 					= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 1)
,	TB_STREAM_CTRL_GET_HOST 				= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 2)
,	TB_STREAM_CTRL_GET_PORT 				= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 3)
,	TB_STREAM_CTRL_GET_PATH 				= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 4)
,	TB_STREAM_CTRL_GET_SSL 					= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 5)
,	TB_STREAM_CTRL_GET_TIMEOUT 				= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 6)
,	TB_STREAM_CTRL_GET_SIZE 				= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 7)
,	TB_STREAM_CTRL_GET_OFFSET 				= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 8)

,	TB_STREAM_CTRL_SET_URL 					= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 11)
,	TB_STREAM_CTRL_SET_HOST 				= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 12)
,	TB_STREAM_CTRL_SET_PORT 				= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 13)
,	TB_STREAM_CTRL_SET_PATH 				= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 14)
,	TB_STREAM_CTRL_SET_SSL 					= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 15)
,	TB_STREAM_CTRL_SET_TIMEOUT 				= TB_STREAM_CTRL(TB_STREAM_TYPE_NONE, 16)

	// the stream for data
,	TB_STREAM_CTRL_DATA_SET_DATA 			= TB_STREAM_CTRL(TB_STREAM_TYPE_DATA, 1)

	// the stream for file
,	TB_STREAM_CTRL_FILE_SET_MODE 			= TB_STREAM_CTRL(TB_STREAM_TYPE_FILE, 1)
,	TB_STREAM_CTRL_FILE_SET_HANDLE 			= TB_STREAM_CTRL(TB_STREAM_TYPE_FILE, 2)
,	TB_STREAM_CTRL_FILE_GET_HANDLE 			= TB_STREAM_CTRL(TB_STREAM_TYPE_FILE, 3)

	// the stream for sock
,	TB_STREAM_CTRL_SOCK_SET_TYPE 			= TB_STREAM_CTRL(TB_STREAM_TYPE_SOCK, 1)
,	TB_STREAM_CTRL_SOCK_SET_HANDLE 			= TB_STREAM_CTRL(TB_STREAM_TYPE_SOCK, 2)
,	TB_STREAM_CTRL_SOCK_GET_HANDLE 			= TB_STREAM_CTRL(TB_STREAM_TYPE_SOCK, 3)
,	TB_STREAM_CTRL_SOCK_KEEP_ALIVE 			= TB_STREAM_CTRL(TB_STREAM_TYPE_SOCK, 4)

	// the stream for http
,	TB_STREAM_CTRL_HTTP_GET_HEAD 			= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 1)
,	TB_STREAM_CTRL_HTTP_GET_RANGE 			= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 2)
,	TB_STREAM_CTRL_HTTP_GET_METHOD 			= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 3)
,	TB_STREAM_CTRL_HTTP_GET_VERSION			= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 4)
,	TB_STREAM_CTRL_HTTP_GET_REDIRECT		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 5) 
,	TB_STREAM_CTRL_HTTP_GET_HEAD_FUNC		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 6)
,	TB_STREAM_CTRL_HTTP_GET_HEAD_PRIV		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 7)
,	TB_STREAM_CTRL_HTTP_GET_AUTO_UNZIP		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 8)
,	TB_STREAM_CTRL_HTTP_GET_POST_URL		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 9)
,	TB_STREAM_CTRL_HTTP_GET_POST_DATA		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 10)
,	TB_STREAM_CTRL_HTTP_GET_POST_FUNC		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 11)
,	TB_STREAM_CTRL_HTTP_GET_POST_PRIV		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 12)
,	TB_STREAM_CTRL_HTTP_GET_POST_LRATE		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 13)

,	TB_STREAM_CTRL_HTTP_SET_HEAD 			= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 20)
,	TB_STREAM_CTRL_HTTP_SET_RANGE 			= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 21)
,	TB_STREAM_CTRL_HTTP_SET_METHOD 			= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 22)
,	TB_STREAM_CTRL_HTTP_SET_VERSION			= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 23)
,	TB_STREAM_CTRL_HTTP_SET_REDIRECT		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 24)
,	TB_STREAM_CTRL_HTTP_SET_HEAD_FUNC		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 25)
,	TB_STREAM_CTRL_HTTP_SET_HEAD_PRIV		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 26)
,	TB_STREAM_CTRL_HTTP_SET_AUTO_UNZIP		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 27)
,	TB_STREAM_CTRL_HTTP_SET_POST_URL		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 28)
,	TB_STREAM_CTRL_HTTP_SET_POST_DATA		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 29)
,	TB_STREAM_CTRL_HTTP_SET_POST_FUNC		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 30)
,	TB_STREAM_CTRL_HTTP_SET_POST_PRIV		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 31)
,	TB_STREAM_CTRL_HTTP_SET_POST_LRATE		= TB_STREAM_CTRL(TB_STREAM_TYPE_HTTP, 32)

	// the stream for filter
,	TB_STREAM_CTRL_FLTR_GET_STREAM 			= TB_STREAM_CTRL(TB_STREAM_TYPE_FLTR, 1)
,	TB_STREAM_CTRL_FLTR_GET_FILTER 			= TB_STREAM_CTRL(TB_STREAM_TYPE_FLTR, 2)
,	TB_STREAM_CTRL_FLTR_SET_STREAM 			= TB_STREAM_CTRL(TB_STREAM_TYPE_FLTR, 3)
,	TB_STREAM_CTRL_FLTR_SET_FILTER 			= TB_STREAM_CTRL(TB_STREAM_TYPE_FLTR, 4)
,	TB_STREAM_CTRL_FLTR_SET_READ_SIZE 		= TB_STREAM_CTRL(TB_STREAM_TYPE_FLTR, 5)

}tb_stream_ctrl_e;

/// the stream state enum
typedef enum __tb_stream_state_e
{
	TB_STREAM_STATE_OK 						= 0
,	TB_STREAM_STATE_CLOSED 					= 1
,	TB_STREAM_STATE_KILLED 					= 2
,	TB_STREAM_STATE_PAUSED 					= 3
,	TB_STREAM_STATE_WAIT_FAILED 			= 4
,	TB_STREAM_STATE_NOT_SUPPORTED 			= 5
,	TB_STREAM_STATE_UNKNOWN_ERROR 			= 6

,	TB_STREAM_SOCK_STATE_DNS_FAILED 		= TB_STREAM_STATE(TB_STREAM_TYPE_SOCK, 1)
,	TB_STREAM_SOCK_STATE_CONNECT_FAILED		= TB_STREAM_STATE(TB_STREAM_TYPE_SOCK, 2)
,	TB_STREAM_SOCK_STATE_CONNECT_TIMEOUT	= TB_STREAM_STATE(TB_STREAM_TYPE_SOCK, 3)
,	TB_STREAM_SOCK_STATE_SSL_FAILED			= TB_STREAM_STATE(TB_STREAM_TYPE_SOCK, 4)
,	TB_STREAM_SOCK_STATE_RECV_TIMEOUT		= TB_STREAM_STATE(TB_STREAM_TYPE_SOCK, 5)
,	TB_STREAM_SOCK_STATE_SEND_TIMEOUT		= TB_STREAM_STATE(TB_STREAM_TYPE_SOCK, 6)

,	TB_STREAM_HTTP_STATE_RESPONSE_204 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 1)
,	TB_STREAM_HTTP_STATE_RESPONSE_300 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 2)
,	TB_STREAM_HTTP_STATE_RESPONSE_301 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 3)
,	TB_STREAM_HTTP_STATE_RESPONSE_302 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 4)
,	TB_STREAM_HTTP_STATE_RESPONSE_303 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 5)
,	TB_STREAM_HTTP_STATE_RESPONSE_304 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 6)
,	TB_STREAM_HTTP_STATE_RESPONSE_400 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 7)
,	TB_STREAM_HTTP_STATE_RESPONSE_401 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 8)
,	TB_STREAM_HTTP_STATE_RESPONSE_402 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 9)
,	TB_STREAM_HTTP_STATE_RESPONSE_403 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 10)
,	TB_STREAM_HTTP_STATE_RESPONSE_404 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 11)
,	TB_STREAM_HTTP_STATE_RESPONSE_405 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 12)
,	TB_STREAM_HTTP_STATE_RESPONSE_406 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 13)
,	TB_STREAM_HTTP_STATE_RESPONSE_407 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 14)
,	TB_STREAM_HTTP_STATE_RESPONSE_408 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 15)
,	TB_STREAM_HTTP_STATE_RESPONSE_409 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 16)
,	TB_STREAM_HTTP_STATE_RESPONSE_410 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 17)
,	TB_STREAM_HTTP_STATE_RESPONSE_411 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 18)
,	TB_STREAM_HTTP_STATE_RESPONSE_412 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 19)
,	TB_STREAM_HTTP_STATE_RESPONSE_413 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 20)
,	TB_STREAM_HTTP_STATE_RESPONSE_414 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 21)
,	TB_STREAM_HTTP_STATE_RESPONSE_415 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 22)
,	TB_STREAM_HTTP_STATE_RESPONSE_416 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 23)
,	TB_STREAM_HTTP_STATE_RESPONSE_500 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 24)
,	TB_STREAM_HTTP_STATE_RESPONSE_501 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 25)
,	TB_STREAM_HTTP_STATE_RESPONSE_502 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 26)
,	TB_STREAM_HTTP_STATE_RESPONSE_503 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 27)
,	TB_STREAM_HTTP_STATE_RESPONSE_504 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 28)
,	TB_STREAM_HTTP_STATE_RESPONSE_505 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 29)
,	TB_STREAM_HTTP_STATE_RESPONSE_506 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 30)
,	TB_STREAM_HTTP_STATE_RESPONSE_507 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 31)
,	TB_STREAM_HTTP_STATE_RESPONSE_UNK 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 32)
,	TB_STREAM_HTTP_STATE_RESPONSE_NUL 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 33)
,	TB_STREAM_HTTP_STATE_REQUEST_FAILED 	= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 34)
,	TB_STREAM_HTTP_STATE_POST_FAILED 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 35)
,	TB_STREAM_HTTP_STATE_RANGE_INVALID 		= TB_STREAM_STATE(TB_STREAM_TYPE_HTTP, 36)

}tb_stream_state_e;

/// the stream type 
typedef struct __tb_stream_t
{
	/// the stream mode
	tb_uint8_t 		mode : 2;

	/// the stream type
	tb_uint8_t 		type : 6;

	/// the url
	tb_url_t 		url;

	// is opened?
	tb_atomic_t 	bopened;

	// is stoped?
	tb_atomic_t 	bstoped;

	// the timeout
	tb_long_t 		timeout;

	/// ctrl stream
	tb_bool_t 		(*ctrl)(tb_handle_t stream, tb_size_t ctrl, tb_va_list_t args);

	/// kill
	tb_void_t 		(*kill)(tb_handle_t astream);

}tb_stream_t;

#endif
