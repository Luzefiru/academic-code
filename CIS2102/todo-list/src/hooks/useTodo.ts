import { useState } from 'react';

export interface Todo {
  id: number;
  title: string;
  content: string;
}

const useTodo = () => {
  const [todos, setTodos] = useState<Todo[]>([]);

  const addTodo = (title: string, content: string) => {
    const newTodo: Todo = { content, title, id: todos.length };
    setTodos((todos) => [...todos, newTodo]);
  };

  const updateTodo = (id: number, title: string, content: string) => {
    const updatedTodo: Todo = { id, title, content };
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
