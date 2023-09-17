const express = require('express');
const app = express();
const cors = require('cors');
require('dotenv').config();
const todoController = require('./controllers/todo.controller');

app.use(cors());
app.use(express.json());

app.get('/', (_, res) => {
  res.send('Hello World');
});

app.get('/todo', async (_, res) => {
  const todos = await todoController.getTodos();
  res.json({ todos });
});

app.get('/todo/:id', async (req, res) => {
  try {
    const todo = await todoController.getTodo(req.params.id);
    res.json({ todo });
  } catch (err) {
    res.status(404).json({ success: false, error: err.message });
  }
});

app.post('/todo', async (req, res) => {
  const { title, content } = req.body;
  const newTodo = await todoController.insertTodo(title, content);
  res.status(201).json({ todo: newTodo });
});

app.patch('/todo/:id', async (req, res) => {
  const { title, content } = req.body;

  try {
    const updatedTodo = await todoController.updateTodo(
      req.params.id,
      title,
      content
    );
    res.json(updatedTodo);
  } catch (err) {
    res.status(400).json({ success: false, error: err.message });
  }
});

app.delete('/todo/:id', async (req, res) => {
  try {
    await todoController.deleteTodo(req.params.id);
    res.status(204).json({ success: true });
  } catch (err) {
    res.status(404).json({ success: false, error: err.message });
  }
});

app.listen(process.env.PORT ?? 3000, () => {
  console.log(
    `🚀 Server now running on http://localhost:${process.env.PORT ?? 3000}`
  );
});
