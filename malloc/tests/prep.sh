export LD_LIBRARY_PATH=../lib:$LD_LIBRARY_PATH

make all;
LD_PRELOAD=../lib/libft_malloc.so ./test1/Test1MallocFt;
