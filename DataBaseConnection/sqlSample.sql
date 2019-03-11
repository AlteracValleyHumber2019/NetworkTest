CREATE DATABASE IF NOT EXISTS loginDatabase;
USE loginDatabase;

DROP TABLE players;
CREATE TABLE  IF NOT EXISTS players (player_id INT NOT NULL PRIMARY KEY AUTO_INCREMENT, player_name VARCHAR(32) NOT NULL, 
												player_password VARCHAR(32) NOT NULL, player_email VARCHAR(32) NOT NULL);

INSERT INTO players (player_name, player_password, player_email) VALUES ('JeffHat', 'root', 'jeffhat@gmail.com');
INSERT INTO players (player_name, player_password, player_email) VALUES ('RedHat', 'root', 'redhat@gmail.com');
SELECT * FROM players;