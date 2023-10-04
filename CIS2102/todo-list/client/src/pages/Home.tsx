import { useState } from 'react';
import AddTodoDialog from '../components/AddTodoModal';
import Icon from '@mdi/react';
import { mdiPlusBoxMultipleOutline } from '@mdi/js';
import TodoItem from '../components/TodoItem';
import { Todo } from '../hooks/useTodo';

interface PropTypes {
  todos: Todo[];
  addTodo: (title: string, content: string) => Promise<void>;
  updateTodo: (id: number, title: string, content: string) => Promise<void>;
  deleteTodo: (id: number) => Promise<void>;
}

function Home({ todos, addTodo, updateTodo, deleteTodo }: PropTypes) {
  const [showAddTodo, setShowAddTodo] = useState(false);
  const toggleModal = () => setShowAddTodo((prev) => !prev);

  return (
    <>
      <div className={showAddTodo ? '' : 'hidden'}>
        <AddTodoDialog addTodo={addTodo} toggleModal={toggleModal} />
      </div>
      <div className="flex items-center">
        <h1 className="text-3xl font-bold text-slate-100">Todo List</h1>
        <button
          title="Add a todo"
          onClick={toggleModal}
          className="p-4 text-slate-100 hover:text-slate-300"
        >
          <Icon
            path={mdiPlusBoxMultipleOutline}
            size={1.25}
            className="text-inherit"
          />
        </button>
      </div>

      <div className="grid gap-4 mt-4">
        {todos.map((todo) => (
          <TodoItem
            todo={todo}
            deleteTodo={deleteTodo}
            updateTodo={updateTodo}
          />
        ))}
      </div>
    </>
  );
}

export default Home;
