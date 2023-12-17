import { useState } from 'react';
import propTypes from 'prop-types';
import { PostService } from '../services';

function UpdatePostModal({ id, title, content }) {
  const [newTitle, setNewTitle] = useState(title);
  const [newContent, setNewContent] = useState(content);
  const [error, setError] = useState('');

  const handleClose = () => {
    document.getElementById(`edit-${id}`).close();
    setNewTitle(title);
    setNewContent(content);
    setError('');
  };

  const handleSubmit = () => {
    // input validation
    if (newTitle === '' || newContent === '') {
      setError('Error: Title or Content fields must not be empty!');
      return;
    }

    const editPost = async () => {
      try {
        const editedPost = await PostService.updatePost({
          id,
          title: newTitle,
          content: newContent,
        });
        console.log(editedPost);
        setError('');
        handleClose();
        window.location.reload();
      } catch (e) {
        console.error(e);
        setError('Something went wrong with the server! Check the logs.');
      }
    };
    editPost();
  };

  const handleChange = (e, setFn) => {
    setFn(e.target.value);
  };

  return (
    <>
      <button
        className="btn btn-square btn-outline"
        onClick={() => document.getElementById(`edit-${id}`).showModal()}
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
            d="M16.862 4.487l1.687-1.688a1.875 1.875 0 112.652 2.652L10.582 16.07a4.5 4.5 0 01-1.897 1.13L6 18l.8-2.685a4.5 4.5 0 011.13-1.897l8.932-8.931zm0 0L19.5 7.125M18 14v4.75A2.25 2.25 0 0115.75 21H5.25A2.25 2.25 0 013 18.75V8.25A2.25 2.25 0 015.25 6H10"
          />
        </svg>
      </button>

      <dialog id={`edit-${id}`} className="modal">
        <div className="w-11/12 max-w-5xl modal-box">
          <h3 className="text-xl font-bold">Edit Post</h3>
          <div className="w-full py-4">
            <label className="label">
              <span className="font-semibold label-text">Title</span>
            </label>
            <input
              value={newTitle}
              onChange={(e) => {
                handleChange(e, setNewTitle);
              }}
              type="text"
              placeholder="Type here"
              className="w-full input input-bordered"
            />
            <label className="mt-2 label">
              <span className="font-semibold label-text">Content</span>
            </label>
            <textarea
              value={newContent}
              onChange={(e) => {
                handleChange(e, setNewContent);
              }}
              className="w-full textarea textarea-bordered"
              placeholder="Bio"
            ></textarea>
          </div>
          {error !== '' && <p className="font-semibold text-error">{error}</p>}
          <div className="modal-action">
            <div className="flex gap-4" method="dialog">
              {/* if there is a button, it will close the modal */}
              <button className="font-bold btn" onClick={() => handleClose()}>
                Cancel
              </button>
              <button
                className="btn btn-secondary"
                onClick={() => {
                  handleSubmit();
                }}
              >
                Edit
              </button>
            </div>
          </div>
        </div>
      </dialog>
    </>
  );
}

UpdatePostModal.propTypes = {
  id: propTypes.number.isRequired,
  title: propTypes.string.isRequired,
  content: propTypes.string.isRequired,
};

export default UpdatePostModal;
