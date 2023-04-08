sleep 10
if [ ! -r /var/www/wordpress/wp-config.php ]; then
	wp config create --allow-root --dbname=$db_name --dbuser=$db_user --dbpass=$db_user_passwd --dbhost=mariadb:3306 --path='/var/www/wordpress'

sleep 2

wp core install --url=$domain --title=$sitetitle --admin_user=$adminuser --admin_password=$adminpasswd --admin_email=$adminemail --allow-root --path='/var/www/wordpress'
wp user create --allow-root --role=author $user1 $user1mail --user_pass=$user1pass --path='/var/www/wordpress' >> /log.txt
fi

if [ ! -d /run/php ]; then
	mkdir /run/php
fi
/usr/sbin/php-fpm7.3 -F
