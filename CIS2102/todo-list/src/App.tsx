import { useState } from 'react';
import useTodo from './hooks/useTodo';
import Todo from './components/TodoItem';
import AddTodoDialog from './components/AddTodoModal';
import Icon from '@mdi/react';
import { mdiPlusBoxMultipleOutline } from '@mdi/js';

function App() {
  const { todos, addTodo, updateTodo, deleteTodo } = useTodo();
  const [showAddTodo, setShowAddTodo] = useState(false);

  const toggleModal = () => setShowAddTodo((prev) => !prev);

  return (
    <>
      <div className={showAddTodo ? '' : 'hidden'}>
        <AddTodoDialog addTodo={addTodo} toggleModal={toggleModal} />
      </div>
      <div className="pt-16 px-32 bg-slate-950 h-[100vh] gap-4">
        <div className="flex items-center">
          <h1 className="text-3xl font-bold text-slate-100">Todo List</h1>
          <button
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

        <div className="p-6 pl-0 border-2 rounded border-slate-500">
          {todos.map((todo) => (
            <Todo todo={todo} deleteTodo={deleteTodo} updateTodo={updateTodo} />
          ))}
        </div>
      </div>
    </>
  );
}

export default App;
