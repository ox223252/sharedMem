
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdint.h>

#include "../freeOnExit/freeOnExit.h"

int getSharedMem ( void ** restrict data, const uint32_t size, const uint32_t key )
{
	int shmid = 0;

	if ( !data ||
		*data )
	{
		return ( 3 );
	}

	if ( ( shmid = shmget ( key, size, 0644 | IPC_CREAT ) ) == -1 )
	{
		return ( 1 );
	}

	*data = shmat ( shmid, (void *)0, 0 );
	if ( !*data )
	{
		return ( 2 );
	}

	if ( setDetachOnExit ( *data ) )
	{
		return ( 4 );
	}

	return( 0 );
}