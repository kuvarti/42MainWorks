mysql -e "CREATE DATABASE IF NOT EXISTS $db_name ;"
mysql -e "CREATE USER IF NOT EXISTS '$db_user'@'%' IDENTIFIED BY '$db_user_passwd' ;"
mysql -e "GRANT ALL PRIVILEGES ON $db_name.* TO '$db_user'@'%' ";
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$rootpasswd' ;"
mysql -e "FLUSH PRIVILEGES";
mysqladmin -u root -p$rootpasswd shutdown
