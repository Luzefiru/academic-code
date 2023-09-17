import { useState } from 'react';

interface Todo {
  id: number;
  content: string;
}

const useTodo = () => {
  const [todos, setTodos] = useState<Todo[]>([]);

  const addTodo = (content: string) => {
    const newTodo: Todo = { content, id: todos.length };
    setTodos((todos) => [...todos, newTodo]);
  };

  const updateTodo = (id: number, content: string) => {
    const updatedTodo: Todo = { id, content };
    setTodos((todos) => todos.map((t) => (t.id === id ? updatedTodo : t)));
  };

  const deleteTodo = (id: number) => {
    setTodos((todos) => todos.filter((t) => t.id !== id));
  };

  const clearTodos = () => {
    setTodos([]);
  };

  return { todos, addTodo, updateTodo, deleteTodo, clearTodos };
};

export default useTodo;
