sh /custom/installation.sh

/etc/init.d/mariadb start
mysql -uroot --password="" -e "source /custom/installation.sql"
tail -f /dev/null
