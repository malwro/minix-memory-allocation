
/* w.c - polecenie w przyjmuje jako argument 1 albo 0 */
/* wlaczajac/wylaczajac algorytm worst fit w systemie Minix */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <lib.h>
#include <errno.h>


PUBLIC int chmem_alloc_alg( int w )
{
	/* ... _syscall(..BEST_FIT..) ... */
    message msg;
    if (w != 0 && w != 1 && w != 2) {
        printf("Wrong argument for best_fit function: %d. Should be 0, 1 or 2", w);
        return EINVAL;
    }
    msg.m1_i1 = w;
    _syscall(MM_PROC_NR, CHMEM_ALLOC_ALG, &msg);
    return 0;
}

int
main( int argc, char *argv[] )
{
	if( argc < 2 )
		return 1;
	chmem_alloc_alg( atoi( argv[1] ) );
	return 0;
}