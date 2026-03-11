# Inception - 42 School Project

*This project has been created as part of the 42 curriculum by ebenoist*

## Description

Inception is a system administration project from 42 School. The goal is to set up a small but complete web infrastructure using **Docker** and **Docker Compose**, entirely inside a **Virtual Machine** running Debian 12.

---

## Infrastructure Overview

```
                        Internet
                           │
                           ▼
                    ┌─────────────┐
                    │    NGINX    │  ← Only entry point
                    │  Port 443   │    TLSv1.2 / TLSv1.3
                    │   (HTTPS)   │
                    └──────┬──────┘
                           │ FastCGI (port 9000)
                           ▼
                    ┌─────────────┐
                    │  WordPress  │  ← PHP Application
                    │  + php-fpm  │    Content Management
                    └──────┬──────┘
                           │ MySQL protocol (port 3306)
                           ▼
                    ┌─────────────┐
                    │   MariaDB   │  ← Database
                    │  Database   │    Stores all WP data
                    └─────────────┘

          All containers connected via Docker network: inception
          Data persisted via Docker named volumes
```

---

## What is Docker?

**Docker** is a platform that allows you to run applications inside isolated environments called **containers**. Think of it like a lightweight virtual machine, but much faster and more efficient.

### Docker vs Virtual Machine

| | Virtual Machine | Docker Container |
|---|---|---|
| Size | Several GB | A few MB |
| Boot time | Several minutes | Seconds |
| Isolation | Full OS | Process-level |
| Performance | Heavy | Lightweight |

### Key Docker concepts

**Docker Image**
A Docker image is a read-only template used to create containers. It contains the OS, dependencies, and application code. Think of it like a recipe — it describes exactly how to build the environment.

**Docker Container**
A container is a running instance of an image. You can create many containers from the same image, each completely isolated from the others. Think of it like a dish cooked from the recipe.

**Dockerfile**
A Dockerfile is a text file containing instructions to build a Docker image step by step. Each instruction creates a new layer in the image.

**Docker Compose**
Docker Compose is a tool that allows you to define and run **multiple containers** together using a single `docker-compose.yml` file. Instead of starting each container manually, you define all services, networks and volumes in one place and launch everything with a single command.

---

## Services

### 🌐 NGINX

NGINX is a high-performance **web server** and **reverse proxy**. In this project, it acts as the **only entry point** into the infrastructure. It receives all HTTPS requests on port 443, handles SSL/TLS termination, and forwards PHP requests to WordPress via FastCGI protocol.

- Handles TLSv1.2 and TLSv1.3 only (no older, insecure versions)
- Uses a self-signed SSL certificate generated at build time
- Forwards `.php` requests to WordPress on port 9000

### 📝 WordPress + php-fpm

WordPress is the world's most popular **Content Management System (CMS)**. It powers over 40% of all websites on the internet. In this project, WordPress runs with **php-fpm** (FastCGI Process Manager), which is a PHP interpreter optimized for handling web requests efficiently.

- WordPress manages all website content (posts, pages, users)
- php-fpm handles PHP execution and communicates with NGINX via FastCGI
- Two users are created: one administrator and one regular user
- The administrator username must NOT contain "admin" or "administrator"

### 🗄️ MariaDB

MariaDB is an open-source **relational database** system, created as a fork of MySQL. It stores all WordPress data: posts, users, settings, comments, and more. WordPress communicates with MariaDB using the MySQL protocol.

- Stores the entire WordPress database
- Only accessible from within the Docker network (not exposed to the outside)
- Two users: a root user and a dedicated WordPress user

---

## Docker Network & Volumes

### Network

All three containers are connected via a custom **bridge network** called `inception`. This allows containers to communicate with each other using their service names (e.g., WordPress connects to MariaDB using the hostname `mariadb`). No container is directly accessible from outside except NGINX on port 443.

### Volumes

Two **named volumes** are used for persistent data storage. Without volumes, all data would be lost when containers are stopped.

| Volume | Content | Host path |
|--------|---------|-----------|
| `wordpress_data` | WordPress files | `/home/ebenoist/data/wordpress` |
| `mariadb_data` | Database files | `/home/ebenoist/data/mariadb` |

---

## Requirements

- Docker
- Docker Compose
- Make
- Virtual Machine running Debian 12 (Bookworm)

---

## Instructions

### 1. Clone the repository

```bash
git clone git@github.com:ebenoist42/inception.git
cd inception
```

### 2. Configure environment variables

Create the `.env` file in `srcs/` with the following variables:

```env
DOMAIN_NAME=ebenoist.42.fr
MYSQL_DATABASE=wordpress
MYSQL_USER=<your_db_user>
MYSQL_PASSWORD=<your_db_password>
WP_ADMIN=<admin_username>        # Must NOT contain admin/administrator
WP_ADMIN_PASSWORD=<admin_password>
WP_ADMIN_EMAIL=<admin_email>
WP_USER=<user_username>
WP_USER_PASSWORD=<user_password>
WP_USER_EMAIL=<user_email>
```

### 3. Configure domain name

Add the following line to `/etc/hosts`:

```
127.0.0.1 ebenoist.42.fr
```

### 4. Build and start

```bash
make
```

### 5. Access the website

**As an administrator:**
- Go to `https://ebenoist.42.fr/wp-admin`
- Login: `webmaster`
- Password: `ebenoist` (defined in `.env` → `WP_ADMIN_PASSWORD`)

**As a regular user:**
- Go to `https://ebenoist.42.fr/wp-login.php`
- Login: `ebenoist`
- Password: `ebenoist` (defined in `.env` → `WP_USER_PASSWORD`)

**As a visitor (without login)**
- Can only read public articles and pages
- No account needed
- Open your browser and go to: `https://ebenoist.42.fr`

---

## Makefile Commands

| Command | Description |
|---------|-------------|
| `make` | Setup directories, build images and start containers |
| `make build` | Build Docker images |
| `make up` | Start containers in detached mode |
| `make down` | Stop containers |
| `make clean` | Stop and remove containers + networks |
| `make fclean` | Full cleanup including data |
| `make re` | Rebuild from scratch |
| `make logs` | Show real-time logs |
| `make status` | Show container status |

---

## Security

- NGINX is the **only entry point** via port **443** using **TLSv1.2/TLSv1.3**
- All passwords are stored in `.env` file (never committed to git)
- Self-signed SSL certificate generated at build time
- No passwords stored in Dockerfiles
- `.env` and `secrets/` are listed in `.gitignore`

---

## Resources

- [Docker Documentation](https://docs.docker.com/)
- [Docker Compose Documentation](https://docs.docker.com/compose/)
- [NGINX Documentation](https://nginx.org/en/docs/)
- [WordPress Documentation](https://developer.wordpress.org/)
- [MariaDB Documentation](https://mariadb.com/kb/en/)

### AI Usage

Claude (claude.ai) was used during this project to help understand Docker concepts, debug configuration issues, and improve documentation. All code and configuration was written and validated by the author.

---

## Author

**ebenoist** - 42 School
