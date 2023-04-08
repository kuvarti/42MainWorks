from debian:buster

run apt-get update && apt-get upgrade -y
run apt-get install -y wget php7.3 php-fpm php-mysql mariadb-client

run wget https://wordpress.org/wordpress-6.0.tar.gz -P /var/www && cd /var/www \
	&& tar -xzf wordpress-6.0.tar.gz && rm wordpress-6.0.tar.gz

copy ./conf/php.conf /etc/php/7.3/fpm/pool.d/www.conf
copy ./conf/conf.php /custom/conf.php

run chown -R root:root /var/www/wordpress
run wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

copy tools/. /custom/.
entrypoint ["bash", "custom/starter.sh"]
