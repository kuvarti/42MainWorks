rm /etc/mysql/mariadb.conf.d/50-server.cnf
chmod 755 /custom/50-server.cnf
cp /custom/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

#export db_name=inceptiondb
#export db_user=nolan
#export db_user_passwd=123
#export sqlfile=/custom/installation.sql

#sh /custom/installation.sh

#/etc/init.d/mariadb start
#mysql -uroot --password="" -e "source /custom/installation.sql"

#tail -f /dev/null
