#!/bin/bash

mkdir -p /var/www/html/wordpress
cd /var/www/html/wordpress

# Wait for MariaDB to be ready
echo "Waiting for MariaDB..."
while ! php -r "new PDO('mysql:host=mariadb;dbname=${MYSQL_DATABASE}', '${MYSQL_USER}', '${MYSQL_PASSWORD}');" 2>/dev/null; do
    sleep 2
done
echo "MariaDB is ready!"

if [ ! -f wp-config.php ]; then
    wp core download --allow-root --path=/var/www/html/wordpress

    # Retry wp config create in case MariaDB connection is flaky
    until wp config create \
        --allow-root \
        --dbname=$MYSQL_DATABASE \
        --dbuser=$MYSQL_USER \
        --dbpass=$MYSQL_PASSWORD \
        --dbhost=mariadb \
        --path=/var/www/html/wordpress; do
        echo "wp config create failed, retrying in 3s..."
        sleep 3
    done

    wp core install \
        --allow-root \
        --url=$DOMAIN_NAME \
        --title="Inception" \
        --admin_user=$WP_ADMIN \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email=$WP_ADMIN_EMAIL \
        --path=/var/www/html/wordpress

    wp user create \
        --allow-root \
        $WP_USER $WP_USER_EMAIL \
        --user_pass=$WP_USER_PASSWORD \
        --path=/var/www/html/wordpress
fi

mkdir -p /run/php
exec php-fpm8.2 -F
