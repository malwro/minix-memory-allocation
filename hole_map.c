/* displays number and sizes of free memory blocks */

#include <stdio.h>
#include <unistd.h>
#include <lib.h>
                                                                                
PUBLIC int hole_map( void *buffer, size_t nbytes)
{
	/* ... _syscall(..HOLE_MAP..) ... */
    message msg;
    msg.m1_i1 = nbytes;
    msg.m1_p1 = buffer;
    return _syscall(MM, HOLE_MAP, &msg);
}
                                                                                
int
main( void )
{
        unsigned int    b[1024];
        unsigned int    *p, a, l;
        int     res;

		res = hole_map( b, sizeof( b ) );
        printf( "[%d] ", res ); /* number of pairs addesss-size */
        p = b;
        while( *p )
        {
                l = *p++; /* size */
                a = *p++; /* not used */
                printf( "%d ", l );
        }
        printf( "\n" );
        return 0;
}