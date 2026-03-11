#!/bin/bash

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld
chown -R mysql:mysql /var/lib/mysql

if [ ! -f "/var/lib/mysql/.inception_init" ]; then
    echo "First run: initializing database..."

    mysql_install_db --user=mysql --datadir=/var/lib/mysql --skip-test-db
    chown -R mysql:mysql /var/lib/mysql

    mysqld --user=mysql --skip-networking &

    echo "Waiting for MariaDB to start..."
    while ! mysqladmin ping --silent 2>/dev/null; do
        sleep 1
    done
    echo "MariaDB is up."

    mysql -u root -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
    mysql -u root -e "CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
    mysql -u root -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';"
    mysql -u root -e "FLUSH PRIVILEGES;"

    echo "Database and user created."
    touch /var/lib/mysql/.inception_init

    mysqladmin -u root shutdown
    sleep 2
fi

echo "Starting MariaDB..."
exec mysqld --user=mysql
