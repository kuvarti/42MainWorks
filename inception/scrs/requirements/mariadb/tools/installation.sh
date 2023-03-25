echo "CREATE DATABASE IF NOT EXISTS $db_name ;" > $sqlfile
echo "CREATE USER IF NOT EXISTS '$db_user'@'%' IDENTIFIED BY '$db_user_passwd' ;" >> $sqlfile
echo "GRANT ALL PRIVILEGES ON $db_name.* TO '$db_user'@'%' ; " >> $sqlfile
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '12345' ; " >> $sqlfile
