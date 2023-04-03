from debian:10.12

run apt update -y && apt upgrade -y && apt install wget vim -y
run apt install php7.3 php-fpm php-mysql mariadb-client -y

run wget https://fr.wordpress.org/wordpress-6.0-en_GB.tar.gz -P /var/www && cd /var/www && tar -xzf wordpress-6.0-en_GB.tar.gz && rm wordpress-6.0-en_GB.tar.gz

run chown -R root:root /var/www/wordpress

