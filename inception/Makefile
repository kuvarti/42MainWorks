FOLDER		= /home/aeryilma/data
COMPOSE		= ./scrs/docker-compose.yml
SERVICES	= mariadb nginx wordpress

all: req up

up:
	docker-compose -f $(COMPOSE) up --build $(SERVICES)

down:
	docker-compose -f $(COMPOSE) down
	@echo 1 | sudo -S rm -rf $(FOLDER)

start:

stop:

removecache:
	@docker rmi -f $(docker images | grep "none" | awk '{print $3; print " "}')
	@docker rmi -f $(docker images | grep "scrs" | awk '{print $3; print " "}')
	@docker rmi -f $(docker images | grep "custom" | awk '{print $3; print " "}')
	@echo "Cache removed"

req:
	@mkdir --verbose --parent $(FOLDER)
	@mkdir --verbose --parent $(FOLDER)/wordpress
	@mkdir --verbose --parent $(FOLDER)/mariadb
