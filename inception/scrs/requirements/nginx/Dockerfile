from alpine:3.17

run apk update && apk upgrade && apk add --no-cache openssl nginx

copy ./conf/default.conf /custom/default.conf
copy ./tools/script.sh /custom/script.sh

cmd sh /custom/script.sh
