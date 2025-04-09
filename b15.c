// Import required libraries
const express = require('express');
const mysql = require('mysql2');

// Create an instance of Express
const app = express();

// Set up middleware to parse JSON
app.use(express.json());

// MySQL connection setup
const db = mysql.createConnection({
  host: 'localhost',   // MySQL host
  user: 'root',        // MySQL username
  password: 'password',// MySQL password
  database: 'test_db'  // Your database name
});

// Establish a MySQL connection
db.connect((err) => {
  if (err) {
    console.error('Error connecting to the MySQL database:', err);
    return;
  }
  console.log('Connected to the MySQL database');
});

// Sample API route to get data from the MySQL database
app.get('/api/users', (req, res) => {
  const sqlQuery = 'SELECT * FROM users'; // Replace with your actual query

  db.query(sqlQuery, (err, results) => {
    if (err) {
      console.error('Error fetching data from MySQL:', err);
      return res.status(500).json({ message: 'Database query failed' });
    }
    res.json(results); // Send the results as JSON
  });
});

// Sample API route to add data to MySQL database
app.post('/api/users', (req, res) => {
  const { name, email } = req.body;  // Expecting name and email in the body

  const sqlQuery = 'INSERT INTO users (name, email) VALUES (?, ?)';
  
  db.query(sqlQuery, [name, email], (err, result) => {
    if (err) {
      console.error('Error inserting data into MySQL:', err);
      return res.status(500).json({ message: 'Database insertion failed' });
    }
    res.status(201).json({ message: 'User added successfully', id: result.insertId });
  });
});

// Set up the server to listen on a port
const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
