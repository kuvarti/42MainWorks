from alpine:3.17

run apk update && apk upgrade && apk add --no-cache openssl nginx
run mkdir -p /etc/nginx/ssl && openssl req -newkey rsa:2048 -x509 -days 365 -nodes \
-out /etc/ssl/certs/nginx-selfsigned.crt \
-keyout /etc/ssl/private/nginx-selfsigned.key \
-subj "/C=TR/ST=Kocaeli/L=TR/O=42/OU=student/CN=aeryilma.42.tr/UID=aeryilma"

copy ./conf/nginx.conf /etc/nginx/nginx.conf
copy ./conf/default.conf /custom/default.conf
copy ./tools/script.sh /custom/script.sh

cmd sh /custom/script.sh
