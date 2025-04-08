const express = require('express');
const mysql = require('mysql2');

// Initialize the app and MySQL connection
const app = express();
const port = 3000;

// Create MySQL connection
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'root', // Replace with your MySQL username
  password: '', // Replace with your MySQL password
  database: 'test_db' // Replace with your database name
});

// Connect to the MySQL database
connection.connect(err => {
  if (err) {
    console.error('error connecting to the database: ' + err.stack);
    return;
  }
  console.log('connected to the database');
});

// Define a route to fetch data from the database
app.get('/api/users', (req, res) => {
  const query = 'SELECT * FROM users'; // Replace with your table/query
  connection.query(query, (err, results) => {
    if (err) {
      console.error(err);
      res.status(500).send('Database query error');
    } else {
      res.json(results);
    }
  });
});

// Define a route to insert data into the database
app.post('/api/users', express.json(), (req, res) =>
