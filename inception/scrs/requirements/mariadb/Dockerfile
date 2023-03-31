from debian:10.12

#volume /home/aeryilma/data/mariadb/. /var/lib/mysql/.

run apt update -y && apt upgrade -y && apt install mariadb-server vim -y

copy /conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
copy /tools/. /custom/.

expose 3306 

cmd sh /custom/starter.sh
