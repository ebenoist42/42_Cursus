# DEV_DOC.md — Developer Documentation

## Prerequisites

Make sure the following are installed on your VM:
- Docker
- Docker Compose
- Make
- Git

```bash
docker --version
docker compose version
make --version
git --version
```

---

## Environment Setup from Scratch

### 1. Clone the repository
```bash
git clone git@github.com:ebenoist42/inception.git
cd inception
```

### 2. Create the `.env` file
Create `srcs/.env` with the following content:
```env
# Domain
DOMAIN_NAME=ebenoist.42.fr

# MySQL
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
MYSQL_PASSWORD=wppassword123
MYSQL_ROOT_PASSWORD=rootpassword123

# WordPress Admin (must NOT contain admin/administrator)
WP_ADMIN=webmaster
WP_ADMIN_PASSWORD=<your_password>
WP_ADMIN_EMAIL=admin@ebenoist.42.fr

# WordPress User
WP_USER=ebenoist
WP_USER_PASSWORD=<your_password>
WP_USER_EMAIL=ebenoist@ebenoist.42.fr
```

### 3. Create the secrets files
```bash
echo -e "webmaster\nebenoist" > secrets/credentials.txt
echo "wppassword123" > secrets/db_password.txt
echo "rootpassword123" > secrets/db_root_password.txt
```

### 4. Configure domain name
Add this line to `/etc/hosts`:
```
127.0.0.1 ebenoist.42.fr
```

---

## Build and Launch

### Full build and start
```bash
make
```
This runs: `setup` → `build` → `up`

### Build images only
```bash
make build
```

### Start containers only (after build)
```bash
make up
```

---

## Makefile Commands

| Command | Description |
|---------|-------------|
| `make` | Setup + build + start |
| `make build` | Build Docker images |
| `make up` | Start containers in background |
| `make down` | Stop containers |
| `make clean` | Stop + remove containers and networks |
| `make fclean` | Full cleanup including data |
| `make re` | Full rebuild from scratch |
| `make logs` | Show real-time logs |
| `make status` | Show container status |

## Commandes Docker Compose

# Démarrer en arrière-plan
docker compose -f srcs/docker-compose.yml up -d

# Arrêter
docker compose -f srcs/docker-compose.yml down

# Arrêter et supprimer les volumes
docker compose -f srcs/docker-compose.yml down -v

# Voir les logs
docker compose -f srcs/docker-compose.yml logs -f

# Voir l'état
docker compose -f srcs/docker-compose.yml ps
---

## Container Management

### List running containers
```bash
docker ps
```

### Enter a container
```bash
docker exec -it nginx bash
docker exec -it wordpress bash
docker exec -it mariadb bash
```

### Restart a single container
```bash
docker restart nginx
docker restart wordpress
docker restart mariadb
```

### View container logs
```bash
docker logs nginx
docker logs wordpress
docker logs mariadb
```

### Check WordPress users
```bash
docker exec wordpress wp user list --allow-root --path=/var/www/html/wordpress
```

### Check MariaDB tables
```bash
docker exec mariadb mysql -u wpuser -pwppassword123 wordpress -e "SHOW TABLES;"
```

## Commandes de test

# Vérifier NGINX
docker exec nginx nginx -t                    # Test config
docker exec nginx ss -tlnp | grep 443         # Port ouvert

# Vérifier MariaDB
docker exec mariadb mysql -u root -p'RootPwd' -e "SHOW DATABASES;"
docker exec mariadb mysql -u root -p'RootPwd' -e "SELECT user,host FROM mysql.user;"

# Vérifier WordPress
docker exec wordpress php -v                   # Version PHP
docker exec wordpress wp core is-installed --allow-root
docker exec wordpress wp user list --allow-root

# Vérifier la connectivité
docker exec wordpress mysqladmin ping -h mariadb -u wtohami- -p'Password'
---

## Data Persistence

### Where is data stored?

| Volume | Container path | Host path |
|--------|---------------|-----------|
| `wordpress_data` | `/var/www/html/wordpress` | `/home/ebenoist/data/wordpress` |
| `mariadb_data` | `/var/lib/mysql` | `/home/ebenoist/data/mariadb` |

### Check volumes
```bash
docker volume ls
```

### Data survives container restarts
Data is stored on the host machine at `/home/ebenoist/data/`. Even if containers are stopped or removed, data remains intact as long as you don't run `make fclean`.

### ⚠️ Warning
Running `make fclean` will **permanently delete** all data including the WordPress database and files.

---

## Project Structure

```
inception/
├── Makefile                          # Project entry point
├── README.md                         # Project overview
├── USER_DOC.md                       # User documentation
├── DEV_DOC.md                        # Developer documentation
├── secrets/                          # Sensitive credentials (not on git)
│   ├── credentials.txt
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs/
    ├── .env                          # Environment variables (not on git)
    ├── docker-compose.yml            # Services definition
    └── requirements/
        ├── nginx/
        │   ├── Dockerfile
        │   └── conf/nginx.conf
        ├── wordpress/
        │   ├── Dockerfile
        │   └── tools/setup.sh
        └── mariadb/
            ├── Dockerfile
            ├── conf/mariadb.conf
            └── tools/setup.sh
```

---

## Security Notes

- `.env` and `secrets/` are listed in `.gitignore` — never commit them
- NGINX is the **only entry point** via port **443** with TLSv1.2/TLSv1.3
- No passwords are stored in Dockerfiles
- MariaDB is not exposed outside the Docker network
