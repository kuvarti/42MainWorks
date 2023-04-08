rm /etc/nginx/http.d/default.conf
chmod 755 /custom/default.conf
cp /custom/default.conf /etc/nginx/http.d/default.conf

mkdir --verbose --parent /var/www/html
sed -i.bak "s/DOMAINE_NAME/$domain/g" /etc/nginx/http.d/default.conf

nginx -g "daemon off;"
