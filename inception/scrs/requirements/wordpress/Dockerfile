from debian:buster

copy ./conf/. /custom/.
copy ./tools/. /custom/.

run apt update -y && apt upgrade -y
run apt install php-fpm php-mysql curl vim -y

cmd ["sh", "/custom/script.sh"]
