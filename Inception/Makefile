COMPOSE_FILE = srcs/docker-compose.yml
DATA_DIR = /home/ebenoist/data

# MAIN COMMANDS
# Default target: setup + build + up
all: setup build up

# Create directories for volumes on host
setup:
	@mkdir -p $(DATA_DIR)/mariadb
	@mkdir -p $(DATA_DIR)/wordpress
	@echo "✅ Data directories created"

# Build Docker images
build:
	docker compose -f $(COMPOSE_FILE) build

# Start containers (-d = detached/background)
up:
	docker compose -f $(COMPOSE_FILE) up -d

# Stop containers
down:
	docker compose -f $(COMPOSE_FILE) down

# CLEANUP COMMANDS
# Stop and remove containers + networks
clean:
	docker compose -f $(COMPOSE_FILE) down -v --remove-orphans

# FULL cleanup (removes EVERYTHING including data)
fclean: clean
	docker system prune -af
	sudo rm -rf $(DATA_DIR)/mariadb/*
	sudo rm -rf $(DATA_DIR)/wordpress/*
	@echo "✅ Full clean done"

# Rebuild from scratch
re: fclean all

# UTILITY COMMANDS
# Real-time logs
logs:
	docker compose -f $(COMPOSE_FILE) logs -f

# Container status
status:
	docker ps --format "table {{.Names}}\t{{.Status}}\t{{.Ports}}"

.PHONY: all setup build up down clean fclean re logs status
