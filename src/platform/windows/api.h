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
 * @file		api.h
 *
 */
#ifndef TB_PLATFROM_WINDOWS_API_H
#define TB_PLATFROM_WINDOWS_API_H

/* ///////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"
#include <windows.h>
#include <winsock2.h>

/* ///////////////////////////////////////////////////////////////////////
 * types
 */

// the OVERLAPPED_ENTRY type
typedef struct _OVERLAPPED_ENTRY 
{
	ULONG_PTR    lpCompletionKey;
	LPOVERLAPPED lpOverlapped;
	ULONG_PTR    Internal;
	DWORD        dwNumberOfBytesTransferred;

}OVERLAPPED_ENTRY, *LPOVERLAPPED_ENTRY;

// the AcceptEx func type from mswsock
typedef BOOL (WINAPI* tb_api_AcceptEx_t)( 	SOCKET sListenSocket
											,	SOCKET sAcceptSocket
											,	PVOID lpOutputBuffer
											,	DWORD dwReceiveDataLength
											,	DWORD dwLocalAddressLength
											,	DWORD dwRemoteAddressLength
											,	LPDWORD lpdwBytesReceived
											,	LPOVERLAPPED lpOverlapped);

// the ConnectEx func type from mswsock
typedef BOOL (WINAPI* tb_api_ConnectEx_t)( SOCKET s
											, 	struct sockaddr const*name
											,	tb_int_t namelen
											,	PVOID lpSendBuffer
											,	DWORD dwSendDataLength
											,	LPDWORD lpdwBytesSent
											,	LPOVERLAPPED lpOverlapped);

// the TransmitFile func type from mswsock
typedef BOOL (WINAPI* tb_api_TransmitFile_t)( SOCKET hSocket
												,	HANDLE hFile
												,	DWORD nNumberOfBytesToWrite
												,	DWORD nNumberOfBytesPerSend
												,	LPOVERLAPPED lpOverlapped
												,	LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers
												,	DWORD dwReserved);

// the GetQueuedCompletionStatusEx func type from kernel32
typedef BOOL (WINAPI* tb_api_GetQueuedCompletionStatusEx_t)( 	HANDLE CompletionPort
																, 	LPOVERLAPPED_ENTRY lpCompletionPortEntries
																, 	ULONG ulCount
																, 	PULONG ulNumEntriesRemoved
																, 	DWORD dwMilliseconds
																, 	BOOL fAlertable);

// the CancelIoEx func type from kernel32
typedef BOOL (WINAPI* tb_api_CancelIoEx_t)(HANDLE hFile, LPOVERLAPPED lpOverlapped);

/* ///////////////////////////////////////////////////////////////////////
 * interfaces
 */

/// the AcceptEx func type 
tb_api_AcceptEx_t 							tb_api_AcceptEx(tb_noarg_t);

/// the ConnectEx func type 
tb_api_ConnectEx_t 							tb_api_ConnectEx(tb_noarg_t);

/// the TransmitFile func type 
tb_api_TransmitFile_t 						tb_api_TransmitFile(tb_noarg_t);

/// the GetQueuedCompletionStatusEx func type 
tb_api_GetQueuedCompletionStatusEx_t 		tb_api_GetQueuedCompletionStatusEx(tb_noarg_t);

/// the CancelIoEx func type 
tb_api_CancelIoEx_t 						tb_api_CancelIoEx(tb_noarg_t);


#endif