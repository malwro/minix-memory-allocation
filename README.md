# Minix Memory Allocation Algorithms
This repository contains the most popular memory allocation algorithms implemented in Minix 2.0.3 operating system.

## Changed files
- ``/usr/include/callnr.h`` - added two new system calls: ``HOLE_MAP`` and ``CHMEM_ALLOC_ALG``. Incremented the ``NCALLS`` constant by two.
- ``/usr/src/fs/table.c`` - added two empty addresses in places of functions which handle new system calls. The FS server should not handle ``HOLE_MAP`` and ``CHMEM_ALLOC_ALG`` syscalls.
- ``/usr/src/mm/alloc.c`` - added new algorithms in ``alloc_mem`` function. Added definitions for ``do_hole_map`` and ``do_chmem_alloc_alg`` functions which handle new system calls.
- ``/usr/src/mm/proto.h`` - added prototypes of functions which handle new system calls.
- ``/usr/src/mm/table.c`` - added addresses of ``do_hole_ap`` and ``do_chem_alloc_alg`` functions.

## New System Calls
The ``CHMEM_ALLOC_ALG`` system call allows the user to change the default first-fit algorithm to one chosen from available algorithms: (for now) best fit or worst-fit. This system call is handled by ``do_chmem_alloc_alg`` function.

The ``HOLE_MAP`` system call returns in a buffer of size ``nbytes`` the information about current contents of the free memory blocks list maintained by the module memory management (MM). The structure of the information received in the buffer should be as follows:
``size1, address1, size2, address2, ..., 0`` where successive size and address pairs correspond to information about the next elements of the free block list. Size 0 represents the last item in the list. This system call is handled by ``do_hole_map`` function.
