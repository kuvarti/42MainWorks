sleep 10
if [ ! -r /var/www/wordpress/wp-config.php ]; then
	wp config create --allow-root --dbname=$db_name --dbuser=$db_user --dbpass=$db_user_passwd --dbhost=mariadb:3306 --path='/var/www/wordpress'

sleep 2
wp core download --allow-root
head -n -1 /var/www/wordpress/wp-config.php > tmp.txt; mv tmp.txt /var/www/wordpress/wp-config.php
cat /custom/conf.php >> /var/www/wordpress/wp-config.php


wp core install --url=$domain --title=$sitetitle --admin_user=$adminuser --admin_password=$adminpasswd --admin_email=$adminemail --allow-root --path='/var/www/wordpress'
wp user create --allow-root --role=author $user1 $user1mail --user_pass=$user1pass --path='/var/www/wordpress' >> /log.txt
wp theme install bizboost --activate --allow-root --path='/var/www/wordpress'
wp plugin install redis-cache --activate --allow-root --path='/var/www/wordpress'
wp plugin update --all --allow-root --path='/var/www/wordpress'
fi

if [ ! -d /run/php ]; then
	mkdir /run/php
fi
wp redis enable --allow-root  --path='/var/www/wordpress'
/usr/sbin/php-fpm7.3 -F
