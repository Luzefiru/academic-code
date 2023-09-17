import useInput from '../hooks/useInput';

interface Props {
  addTodo: (title: string, content: string) => void;
  toggleModal: () => void;
}

export default function AddTodoDialog({ addTodo, toggleModal }: Props) {
  const [title, clearTitle, handleTitleChange] = useInput();
  const [content, clearContent, handleContentChange] = useInput();

  const clearForm = () => {
    clearTitle();
    clearContent();
  };

  const closeModal = () => {
    toggleModal();
  };

  const handleAddTodo = () => {
    addTodo(title, content);
    clearForm();
    closeModal();
  };

  const handleCancelAdd = () => {
    clearForm();
    closeModal();
  };

  return (
    <>
      <div
        onClick={closeModal}
        className="z-30 bg-slate-950 opacity-50 absolute w-[100vw] h-[100vh]"
      />
      <div className="shadow-lg shadow-slate-700 rounded-xl absolute top-[50%] left-[50%] translate-x-[-50%] translate-y-[-50%] z-40 grid gap-2 py-8 px-16 bg-slate-100">
        <h2 className="pb-4 text-3xl font-bold justify-self-center text-slate-900">
          Add New Todo
        </h2>

        <div className="grid">
          <div className="font-medium text-slate-600">
            Title <span className="text-red-500">*</span>
          </div>
          <input
            className="px-2 py-[0.25rem] rounded-lg border-2 border-neutral-300"
            value={title}
            onChange={handleTitleChange}
          ></input>
        </div>
        <div className="grid gap-2">
          <div className="font-medium text-slate-600">
            Content <span className="text-red-500">*</span>
          </div>
          <textarea
            className="px-2 py-[0.25rem] rounded-lg border-2 border-neutral-300"
            value={content}
            onChange={handleContentChange}
          ></textarea>
        </div>

        <div className="flex gap-4 py-4">
          <button
            className="px-6 py-2 font-medium hover:text-red-500 "
            onClick={handleCancelAdd}
          >
            Cancel
          </button>
          <button
            className="px-6 py-2 font-medium text-white bg-green-600 rounded-lg shadow hover:bg-green-800"
            onClick={handleAddTodo}
          >
            Add Todo
          </button>
        </div>
      </div>
    </>
  );
}
