# Inception — User Guide
### WordPress Infrastructure on Docker

42 School Project by Emma Benoist

## What is this project?

This project runs a complete WordPress website using three Docker containers working together. Each container has a specific role and they communicate through a private network. All data is saved on your machine so nothing is lost when you restart.

---

## How it works

```
[ Your Browser ]
       |
       | HTTPS only — port 443
       |
[ NGINX Container ]          ← The only door into the system
       |
       | Sends PHP requests
       |
[ WordPress Container ]      ← Runs the website logic
       |
       | Reads/writes data
       |
[ MariaDB Container ]        ← Stores everything (posts, users, settings)
```

The key point: **only NGINX is exposed to the outside**. WordPress and MariaDB are completely hidden inside the Docker network. You cannot access them directly.

---

## Getting started

### 1. Prerequisites

Make sure you have the following installed on your machine:

- Docker
- Docker Compose
- Make

Also add this line to your `/etc/hosts` file so your browser knows where to find the site:

```
127.0.0.1 ebenoist.42.fr
```

### 2. Configure your environment

Before the first launch, fill in the `srcs/.env` file with your own values:

```env
# Your domain
DOMAIN_NAME=ebenoist.42.fr

# Database settings
MYSQL_DATABASE=wordpress
MYSQL_USER=your_db_user
MYSQL_PASSWORD=your_db_password
MYSQL_ROOT_PASSWORD=your_root_password

# WordPress admin account (username must NOT contain "admin" or "administrator")
WP_ADMIN=your_admin_name
WP_ADMIN_PASSWORD=your_admin_password
WP_ADMIN_EMAIL=your_admin@email.com

# WordPress regular user account
WP_USER=your_username
WP_USER_PASSWORD=your_user_password
WP_USER_EMAIL=your_user@email.com
```

> ⚠️ Never commit this file to Git. It contains sensitive information.

### 3. Launch everything

```bash
make
```

This single command will create the necessary data folders, build all three Docker images from scratch, and start the containers. The first build takes a few minutes since it downloads Debian and installs all packages. Subsequent builds are much faster thanks to Docker's cache.

---

## Daily usage

### Starting and stopping

```bash
make          # Build and start everything
make up       # Start containers (if already built)
make down     # Stop containers (data is kept)
make re       # Full rebuild from scratch
make fclean   # Stop everything and delete all data
```

### Monitoring

```bash
make status   # Quick view of container health
make logs     # Live logs from all containers
docker logs nginx       # Logs for a specific container
docker logs wordpress
docker logs mariadb
```

---

## Accessing the website

### As a visitor

Just open your browser and go to:

```
https://ebenoist.42.fr
```

Your browser will warn you about the certificate — this is expected since we use a self-signed certificate. Click **Advanced** then **Proceed to site**.

You will see the WordPress homepage with all published posts and pages. No login required.

### As a regular user

Go to the login page:

```
https://ebenoist.42.fr/wp-login.php
```

Login with the credentials defined in `.env` under `WP_USER` and `WP_USER_PASSWORD`. As a regular user (subscriber) you can read content but cannot modify the site.

### As an administrator

Go to the admin panel:

```
https://ebenoist.42.fr/wp-admin
```

Login with the credentials defined in `.env` under `WP_ADMIN` and `WP_ADMIN_PASSWORD`. As an administrator you have full control over the site — you can create and edit posts, manage users, install themes and plugins, and change all settings.

---

## Managing WordPress content

### Creating a post

1. Log in as administrator at `/wp-admin`
2. Go to **Posts → Add New**
3. Write your title and content
4. Click **Publish**

### Managing users

1. Go to **Users → All Users**
2. You will see both accounts: the administrator and the regular user
3. You can add new users, change roles, or reset passwords from here

### Changing a password

1. Go to **Users → Your Profile**
2. Scroll down to **Account Management**
3. Click **Set New Password**
4. Save your changes

---

## Verifying the infrastructure

### Check all containers are running

```bash
make status
```

Expected output:

```
NAMES       STATUS          PORTS
nginx       Up X minutes    0.0.0.0:443->443/tcp
wordpress   Up X minutes    9000/tcp
mariadb     Up X minutes    3306/tcp
```

### Check the database

```bash
docker exec mariadb mysql -u wpuser -pwppassword123 -e "SHOW TABLES;" wordpress
```

You should see all WordPress tables listed.

### Check WordPress users

```bash
docker exec wordpress wp user list --allow-root --path=/var/www/html/wordpress
```

You should see your administrator and regular user accounts.

### Test the website from command line

```bash
curl -k https://ebenoist.42.fr
```

You should see WordPress HTML in your terminal.

---

## Troubleshooting

| Symptom | Likely cause | Fix |
|---------|-------------|-----|
| 502 Bad Gateway | WordPress not ready yet | Wait 30 seconds and refresh |
| Site shows setup wizard | WordPress not installed | Run `make re` |
| Cannot connect to database | MariaDB still starting | Wait and check `docker logs mariadb` |
| Blank white page | PHP error | Check `docker logs wordpress` |
| Certificate warning | Self-signed cert (expected) | Click Advanced → Proceed |
| Port 443 already in use | Another service on port 443 | Stop the conflicting service |

---

## Data persistence

Your data is stored on the host machine at:

```
/home/ebenoist/data/
    ├── wordpress/    ← All WordPress files and uploads
    └── mariadb/      ← All database files
```

This means even if you run `make down` and `make up`, all your posts, users, and settings will still be there. Only `make fclean` will delete this data permanently.

---

*Inception — 42 School | ebenoist*
