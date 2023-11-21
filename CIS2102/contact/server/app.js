require('dotenv').config();
const express = require('express');
require('express-async-errors');
const app = express();
const { contactRouter } = require('./routes');

// Middleware
app.use(express.json());
app.use(require('cors')());

// Routers
app.get('/', (_, res) => {
  res.send('<h1>Hello World</h1>');
});
app.use('/contact', contactRouter);

app.use((req, res) => {
  res.status(404).json({ error: 'unknown endpoint' });
});

app.use((err, req, res, next) => {
  console.log(err);
  res.status(500).json({ error: err.message });
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log('Server is listening on', PORT);
});
