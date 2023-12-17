import { useState } from 'react';
import { PostService } from '../services';

function CreatePostModal() {
  const [title, setTitle] = useState('');
  const [content, setContent] = useState('');
  const [error, setError] = useState('');

  const handleClose = () => {
    document.getElementById('create-post').close();
    setTitle('');
    setContent('');
    setError('');
  };

  const handleSubmit = () => {
    // input validation
    if (title === '' || content === '') {
      setError('Error: Title or Content fields must not be empty!');
      return;
    }

    const createNewPost = async () => {
      try {
        const newPost = await PostService.createPost({ title, content });
        console.log(newPost);
        setTitle('');
        setContent('');
        setError('');
        handleClose();
        window.location.reload();
      } catch (e) {
        console.error(e);
        setError('Something went wrong with the server! Check the logs.');
      }
    };
    createNewPost();
  };

  const handleChange = (e, setFn) => {
    setFn(e.target.value);
  };

  return (
    <>
      <button
        className="text-sm btn btn-sm md:btn-md md:text-lg"
        onClick={() => document.getElementById('create-post').showModal()}
      >
        Create Post
      </button>
      <dialog id="create-post" className="modal">
        <div className="w-11/12 max-w-5xl modal-box">
          <h3 className="text-xl font-bold">Create Post</h3>
          <div className="w-full py-4">
            <label className="label">
              <span className="font-semibold label-text">Title</span>
            </label>
            <input
              value={title}
              onChange={(e) => {
                handleChange(e, setTitle);
              }}
              type="text"
              placeholder="An interesting title"
              className="w-full input input-bordered"
            />
            <label className="mt-2 label">
              <span className="font-semibold label-text">Content</span>
            </label>
            <textarea
              value={content}
              onChange={(e) => {
                handleChange(e, setContent);
              }}
              className="w-full textarea textarea-bordered"
              placeholder="Your content goes here"
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
                className="btn btn-primary"
                onClick={() => {
                  handleSubmit();
                }}
              >
                Post
              </button>
            </div>
          </div>
        </div>
      </dialog>
    </>
  );
}

export default CreatePostModal;
