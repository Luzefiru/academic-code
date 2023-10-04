import { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { Todo } from '../hooks/useTodo';
import EditTodoModal from './EditTodoModal';
import Icon from '@mdi/react';
import { mdiCheckBold, mdiNoteEditOutline } from '@mdi/js';

interface Props {
  todo: Todo;
  deleteTodo: (id: number) => void;
  updateTodo: (id: number, title: string, content: string) => void;
}

export default function TodoItem({ todo, deleteTodo, updateTodo }: Props) {
  const navigate = useNavigate();

  const [isHovering, setIsHovering] = useState(false);
  const [showEditTodo, setEditTodo] = useState(false);

  const toggleModal = () => setEditTodo((prev) => !prev);

  const overlayVisibility = isHovering ? '' : 'hidden';

  const showButtons = () => {
    setIsHovering((prev) => !prev);
  };

  const handleMarkAsDone = () => {
    deleteTodo(todo.id);
  };

  const handleEditTodo = () => {
    toggleModal();
  };

  const handleClick = () => {
    navigate(`/todo/${todo.id}`);
  };

  return (
    <>
      <div className={showEditTodo ? '' : 'hidden'}>
        <EditTodoModal
          todo={todo}
          updateTodo={updateTodo}
          toggleModal={toggleModal}
        />
      </div>
      <div
        onClick={handleClick}
        onMouseEnter={showButtons}
        onMouseLeave={showButtons}
        className="relative grid gap-2 px-4 py-4 rounded-lg bg-slate-200 hover:scale-[1.005] hover:shadow hover:shadow-slate-400 transition-all cursor-pointer"
      >
        <div className="text-xl font-bold">{todo.title}</div>
        <div className="font-italic">{todo.content}</div>
        <div
          className={`absolute flex justify-end items-center  pr-[5%] xl:pr-[2.5%] rounded-lg z-50 h-full w-full ${overlayVisibility}`}
        >
          <div className="flex gap-4">
            <button
              onClick={handleEditTodo}
              title="Edit Todo"
              className="p-2 transition-all duration-75 border-4 rounded-lg border-slate-600 text-slate-600 hover:shadow-xl hover:border-amber-500 hover:bg-amber-500 hover:text-white"
            >
              <Icon path={mdiNoteEditOutline} size={1.1} />
            </button>
            <button
              onClick={handleMarkAsDone}
              title="Mark Todo as Done"
              className="p-2 transition-all duration-75 border-4 rounded-lg hover:shadow-xl border-slate-600 text-slate-600 hover:border-green-500 hover:bg-green-500 hover:text-white"
            >
              <Icon path={mdiCheckBold} size={1.1} />
            </button>
          </div>
        </div>
      </div>
    </>
  );
}
