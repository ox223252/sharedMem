#ifndef __SHAREDMEM_H__
#define __SHAREDMEM_H__
////////////////////////////////////////////////////////////////////////////////
/// \copiright ox223252, 2018
///
/// This program is free software: you can redistribute it and/or modify it
///     under the terms of the GNU General Public License published by the Free
///     Software Foundation, either version 2 of the License, or (at your
///     option) any later version.
///
/// This program is distributed in the hope that it will be useful, but WITHOUT
///     ANY WARRANTY; without even the implied of MERCHANTABILITY or FITNESS FOR
///     A PARTICULAR PURPOSE. See the GNU General Public License for more
///     details.
///
/// You should have received a copy of the GNU General Public License along with
///     this program. If not, see <http://www.gnu.org/licenses/>
////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////
/// \file sharedMem.h
/// \brief Created to simplify shared mem usage
/// \author ox223252
/// \date 2018-02
/// \copyright GPLv2
/// \version 0.1
/// \warning NONE
/// \bug NONE
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// \fn int getSharedMem ( void ** restrict data, const uint32_t size, 
///     const uint32_t key );
/// \param[ out ] data: NULL pointer address to access to shared memeory
/// \param[ in ] size: shared memory size
/// \param[ in ] key: shared memeory key access
/// \brief created sharedmemory access point for data pointer, in read/write 
///     mode
/// \return 0: OK
///         1: shmget failed, verify errno
///         2: shmat failed
///         3: data pointer invalid
///         4: setDetachOnExit() failed, shared memory exist
////////////////////////////////////////////////////////////////////////////////
int getSharedMem ( void ** restrict data, const uint32_t size, 
	const uint32_t key );

#endif
