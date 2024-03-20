export LD_LIBRARY_PATH=../lib:$LD_LIBRARY_PATH

make deneme;
LD_PRELOAD=/home/kuvarti/42MainWorks/malloc/lib/libft_malloc.so ./a.out;
