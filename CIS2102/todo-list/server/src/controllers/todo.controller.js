const sequelize = require('../db');

sequelize.query(`
  CREATE TABLE IF NOT EXISTS todo (
    id INTEGER AUTO_INCREMENT,
    title VARCHAR(255),
    content TEXT,
    PRIMARY KEY(id)
  )
  `);

const getTodos = async () => {
  const [todos] = await sequelize.query('SELECT * FROM todo');
  return todos;
};

const getTodo = async (id) => {
  const [selectedTodos] = await sequelize.query(
    `SELECT * FROM todo WHERE id = ?`,
    {
      replacements: [id],
    }
  );

  if (selectedTodos.length === 0) {
    throw new Error(`No todos exist with id ${id}`);
  }

  return selectedTodos[0];
};

const insertTodo = async (title, content) => {
  const [newTodoId] = await sequelize.query(
    `
    INSERT INTO todo (title, content)
    VALUES (?, ?)
    `,
    {
      replacements: [title, content],
    }
  );

  const newTodo = getTodo(newTodoId);
  return newTodo;
};

const updateTodo = async (id, title, content) => {
  const [result] = await sequelize.query(
    `UPDATE todo SET title = ?, content = ? WHERE id = ?`,
    { replacements: [title, content, id] }
  );
  if (result.affectedRows === 0) {
    throw new Error(`Failed to update todo with id: ${id}`);
  }
};

const deleteTodo = async (id) => {
  const [result] = await sequelize.query(`DELETE FROM todo WHERE id = ?`, {
    replacements: [id],
  });
  if (result.affectedRows === 0) {
    throw new Error(`Failed to delete todo with id: ${id}`);
  }
};

module.exports = { getTodos, getTodo, insertTodo, updateTodo, deleteTodo };
