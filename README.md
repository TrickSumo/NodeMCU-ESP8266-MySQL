# NodeMCU-ESP8266-MySQL
Connect NodeMCU ESP8266 To MySQL Database.

1. Create MySQL database

create database db1;
CREATE USER myuser1@localhost IDENTIFIED BY 'Secure2020#';
GRANT ALL PRIVILEGES ON db1.* TO myuser1@localhost;
FLUSH PRIVILEGES;


CREATE TABLE `db1`.`nodemcu_table` ( `id` INT(10) NOT NULL AUTO_INCREMENT , `val` FLOAT(10) NOT NULL , `val2` FLOAT(10) NOT NULL , `date` DATE NOT NULL , `time` TIME NOT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;

exit;

2. Upload PHP Files to server.

3. Upload code to NodeMCU ESP8266.

For video tutorial, checkout:- 
