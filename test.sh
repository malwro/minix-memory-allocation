#!/bin/sh
# script for tests of HOLE_MAP AND CHMEM_ALLOC_ALG
# system functions

cc -o hole_map hole_map.c 
cc -o chmem_alloc_alg chmem_alloc_alg.c
cc -o do_sleep do_sleep.c
chmem =8000 do_sleep

echo "-[ std ]----------------------------------------"
./chmem_alloc_alg 0
for i in 1 2 3 4 5 6 7 8 9 10
do
	./do_sleep 10 &
	./hole_map
	sleep 1
done
for i in 1 2 3 4 5 6 7 8 9 10
do
	./hole_map
	sleep 1
done
echo "-[ best ]--------------------------------------"
./chmem_alloc_alg 1
for i in 1 2 3 4 5 6 7 8 9 10
do
	./do_sleep 10 &
	./hole_map
	sleep 1
done
for i in 1 2 3 4 5 6 7 8 9 10
do
	./hole_map
	sleep 1
done
echo "-[ chmem_alloc_algorst ]--------------------------------------"
./chmem_alloc_alg 2
for i in 1 2 3 4 5 6 7 8 9 10
do
	./do_sleep 10 &
	./hole_map
	sleep 1
done
for i in 1 2 3 4 5 6 7 8 9 10
do
	./hole_map
	sleep 1
done
echo "-[ std ]----------------------------------------"
./chmem_alloc_alg 0