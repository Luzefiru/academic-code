import axios from 'axios';
const baseUrl = 'http://127.0.0.1:3000/todo';
import { Todo } from '../hooks/useTodo';

const getTodos = async (): Promise<Todo[]> => {
  const res = await axios.get(baseUrl);
  console.log(res);
  return res.data.todos;
};

const addTodo = async (title: string, content: string): Promise<Todo> => {
  const res = await axios.post(baseUrl, { title, content });
  console.log(res);
  return res.data.todo;
};

const updateTodo = async (id: number, title: string, content: string) => {
  const res = await axios.patch(`${baseUrl}/${id}`, { title, content });
  console.log(res);
};

const deleteTodo = async (id: number) => {
  const res = await axios.delete(`${baseUrl}/${id}`);
  console.log(res);
};

const exports = { getTodos, addTodo, updateTodo, deleteTodo };

export default exports;
