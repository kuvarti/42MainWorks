
if [ "$(uname -s)" = "Darwin" ]; then
	export LD_PRELOAD=`pwd`/$DYLD_INSERT_LIBRARIES
	$@
else
	export LD_LIBRARY_PATH=lib
	$@
fi
