export DYLD_LIBRARY_PATH=./lib
export DYLD_FORCE_FLAT_NAMESPACE=1
export DYLD_INSERT_LIBRARIES="./lib/libft_malloc.so"
export LD_PRELOAD=`pwd`/$DYLD_INSERT_LIBRARIES

$@
