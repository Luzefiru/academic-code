import { useState } from 'react';
import propTypes from 'prop-types';
import { PostService } from '../services';

function DeletePostModal({ id, title }) {
  const [error, setError] = useState('');

  const handleClose = () => {
    document.getElementById(`delete-${id}`).close();
    setError('');
  };

  const handleSubmit = () => {
    const deletePost = async () => {
      try {
        await PostService.deletePost(id);
        setError('');
        handleClose();
        window.location.reload();
      } catch (e) {
        console.error(e);
        setError('Something went wrong with the server! Check the logs.');
      }
    };
    deletePost();
  };

  return (
    <>
      <button
        className="btn btn-error btn-square btn-outline"
        onClick={() => document.getElementById(`delete-${id}`).showModal()}
      >
        <svg
          xmlns="http://www.w3.org/2000/svg"
          fill="none"
          viewBox="0 0 24 24"
          strokeWidth={1.5}
          stroke="currentColor"
          className="w-6 h-6"
        >
          <path
            strokeLinecap="round"
            strokeLinejoin="round"
            d="M14.74 9l-.346 9m-4.788 0L9.26 9m9.968-3.21c.342.052.682.107 1.022.166m-1.022-.165L18.16 19.673a2.25 2.25 0 01-2.244 2.077H8.084a2.25 2.25 0 01-2.244-2.077L4.772 5.79m14.456 0a48.108 48.108 0 00-3.478-.397m-12 .562c.34-.059.68-.114 1.022-.165m0 0a48.11 48.11 0 013.478-.397m7.5 0v-.916c0-1.18-.91-2.164-2.09-2.201a51.964 51.964 0 00-3.32 0c-1.18.037-2.09 1.022-2.09 2.201v.916m7.5 0a48.667 48.667 0 00-7.5 0"
          />
        </svg>
      </button>
      <dialog id={`delete-${id}`} className="modal">
        <div className="w-11/12 max-w-5xl modal-box">
          <h3 className="text-xl font-bold">Delete Post</h3>
          <p className="mt-4 text-lg">
            Are you sure you want to delete post{' '}
            <em className="font-bold">&quot;{title}&quot;</em> ?
          </p>
          {error !== '' && <p className="font-semibold text-error">{error}</p>}
          <div className="modal-action">
            <div className="flex gap-4" method="dialog">
              {/* if there is a button, it will close the modal */}
              <button className="font-bold btn" onClick={() => handleClose()}>
                Cancel
              </button>
              <button
                className="btn btn-error"
                onClick={() => {
                  handleSubmit();
                }}
              >
                Delete
              </button>
            </div>
          </div>
        </div>
      </dialog>
    </>
  );
}

DeletePostModal.propTypes = {
  id: propTypes.number.isRequired,
  title: propTypes.string.isRequired,
};

export default DeletePostModal;
