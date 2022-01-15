/* takes as an argument 0, 1 or 2:
*  0 - sets the memory allocation algorithm to first-fit (standard)
*  1 - sets the memory allocation algorithm to best-fit
*  2 - sets the memory allocation algorithm to worst-fit
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <lib.h>
#include <errno.h>


PUBLIC int chmem_alloc_alg( int chosen_alg )
{
	/* ... _syscall(..BEST_FIT..) ... */
    message msg;
    if (chosen_alg != 0 && chosen_alg != 1 && chosen_alg != 2) {
        printf("Wrong argument for best_fit function: %d. Should be 0, 1 or 2", chosen_alg);
        return EINVAL;
    }
    msg.m1_i1 = chosen_alg;
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