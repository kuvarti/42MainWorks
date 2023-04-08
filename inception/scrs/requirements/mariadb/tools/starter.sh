mkdir -p /var/run/mysqld
chown mysql:mysql /var/run/mysqld
chmod 775 /var/run/mysqld

#mysql_install_db
service mysql start
sh /custom/installation.sh
service mysql status
#mysqladmin -u root --password="$rootpasswd" shutdown
#exec mysqld_safe
tail -f /var/log/mysql/error.log
