mkdir -p /var/run/mysqld
chown mysql:mysql /var/run/mysqld
chmod 775 /var/run/mysqld

service mysql start
sh /custom/installation.sh

exec mysqld_safe
