from debian:bookworm

run apt update -y && apt upgrade -y && apt install mariadb-server -y

copy /conf/50-server.cnf /custom/50-server.cnf
copy /tools/. /custom/.

run sh /custom/script.sh
cmd sh /custom/starter.sh
