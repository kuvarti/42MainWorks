FOLDER		= /home/aeryilma/data
COMPOSE		= ./scrc/docker-compose.yml

all: req up

up:
	docker-compose -d up -f $(COMPOSE)

down:
	docker-compose down -f $(COMPOSE)

start:

stop:

req:
	@mkdir --verbose --parent $(FOLDER)
	@mkdir --verbose --parent $(FOLDER)/wordpress
	@mkdir --verbose --parent $(FOLDER)/mariadb
