import Icon from '@mdi/react';
import { mdiHomeEdit } from '@mdi/js';
import { useParams, useNavigate } from 'react-router-dom';
import NotFound from './NotFound';

import { Todo } from '../hooks/useTodo';

interface PropTypes {
  todos: Todo[];
}

function TodoInfo({ todos }: PropTypes) {
  const navigate = useNavigate();

  const { id = '404' } = useParams();
  const todo = todos.find((todo) => todo.id === parseInt(id, 10));

  const goBackToHome = () => {
    navigate('/');
  };

  if (id === '404' || todo === undefined) {
    return <NotFound />;
  }

  return (
    <div>
      <div className="flex items-center">
        <h1 className="text-3xl font-bold text-slate-100">Todo List</h1>
        <button
          onClick={goBackToHome}
          title="Back to home"
          className="p-4 text-slate-100 hover:text-slate-300"
        >
          <Icon path={mdiHomeEdit} size={1.25} className="text-inherit" />
        </button>
      </div>

      <div className="relative grid gap-2 px-4 py-4 mt-4 transition-all rounded-lg bg-slate-200">
        <div className="text-xl font-bold">{todo.title}</div>
        <div className="font-italic">{todo.content}</div>
      </div>
    </div>
  );
}

export default TodoInfo;
