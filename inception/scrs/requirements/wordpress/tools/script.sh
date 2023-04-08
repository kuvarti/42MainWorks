#!/bin/bash

# create directory to use in nginx container later and also to setup the wordpress conf
mkdir --verbose --parents /var/www/html
cd /var/www/html

rm -rf *
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

wp core download --allow-root
mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
mv /custom/conf.php /var/www/html/wp-config.php

sed -i -r "s/db1/$db_name/1"   wp-config.php
sed -i -r "s/user/$db_user/1"  wp-config.php
sed -i -r "s/pwd/$db_user_passwd/1"    wp-config.php

wp core install --url=$domain/ --title=$sitetitle --admin_user=$adminuse --admin_password=$adminpasswd --admin_email=$adminemail --skip-email --allow-root


wp user create $user1 $user1mail --role=author --user_pass=$user1pass --allow-root

wp theme install bizboost --activate --allow-root
wp plugin install redis-cache --activate --allow-root
wp plugin update --all --allow-root

sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/g' /etc/php/7.3/fpm/pool.d/www.conf

mkdir /run/php

wp redis enable --allow-root
/usr/sbin/php-fpm7.3 -F

