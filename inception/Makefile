FOLDER		= /home/aeryilma/data
COMPOSE		= ./scrs/docker-compose.yml
SERVICES	= mariadb nginx wordpress portrainer adminer

all: req up

up:
	docker-compose -f $(COMPOSE) up -d --build $(SERVICES)

down: fclean
	docker-compose -f $(COMPOSE) down

start:
	docker-compose -f $(COMPOSE) start

stop:
	docker-comsope -f $(COMPOSE) stop

log:
	docker-compose -f $(COMPOSE) logs | less

fclean:
	@echo 1 | sudo -S rm -rf $(FOLDER)

removecache:
	@docker rmi -f $(shell docker images | grep "none" | awk '{print $3; print " "}')
	@docker rmi -f $(shell docker images | grep "scrs" | awk '{print $3; print " "}')
	@docker rmi -f $(shell docker images | grep "custom" | awk '{print $3; print " "}')
	@echo "Cache removed"

req:
	@mkdir --verbose --parent $(FOLDER)
	@mkdir --verbose --parent $(FOLDER)/wordpress
	@mkdir --verbose --parent $(FOLDER)/mariadb
	@mkdir --verbose --parent $(FOLDER)/portrainer
