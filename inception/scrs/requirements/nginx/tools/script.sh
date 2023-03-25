openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out $OUT_ -subj "/C=TR/L=TR/O=42/OU=student/CN=aeryilma.42.tr"

rm /etc/nginx/http.d/default.conf
chmod 755 /custom/default.conf
cp /custom/default.conf /etc/nginx/http.d/default.conf

mkdir --verbose --parent /var/www/html

nginx -g "daemon off;"
