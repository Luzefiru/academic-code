const mysql = require('mysql2');

const connection = mysql.createConnection({
  host: process.env.HOST || 'localhost',
  port: process.env.DB_PORT || 3306,
  user: process.env.DB_USER || 'root',
  password: process.env.DB_PASSWORD || 'example',
  database: process.env.DB_DATABASE || 'app',
});

connection.query(
  `CREATE TABLE IF NOT EXISTS contact (
    id INTEGER NOT NULL UNIQUE AUTO_INCREMENT, 
    student_id INTEGER NOT NULL UNIQUE,
    name VARCHAR(255) NOT NULL,
    age INTEGER NOT NULL,
    contact VARCHAR(50) NOT NULL,
    course VARCHAR(50) NOT NULL,
    PRIMARY KEY(id)
  )`
);

module.exports = connection;
