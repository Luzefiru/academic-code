import { useState, useEffect } from 'react';
import todoService from '../helpers/todoService';

export interface Todo {
  id: number;
  title: string;
  content: string;
}

const useTodo = () => {
  const [todos, setTodos] = useState<Todo[]>([]);

  useEffect(() => {
    const initializeTodos = async () => {
      const todos = await todoService.getTodos();
      setTodos(todos);
    };
    initializeTodos();
  }, []);

  const addTodo = async (title: string, content: string) => {
    const newTodo: Todo = await todoService.addTodo(title, content);
    setTodos((todos) => [...todos, newTodo]);
  };

  const updateTodo = async (id: number, title: string, content: string) => {
    await todoService.updateTodo(id, title, content);
    const updatedTodo: Todo = { id, title, content };
    setTodos((todos) => todos.map((t) => (t.id === id ? updatedTodo : t)));
  };

  const deleteTodo = async (id: number) => {
    await todoService.deleteTodo(id);
    setTodos((todos) => todos.filter((t) => t.id !== id));
  };

  return { todos, addTodo, updateTodo, deleteTodo };
};

export default useTodo;
