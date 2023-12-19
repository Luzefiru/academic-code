import propTypes from 'prop-types';
import { DeletePostModal, UpdatePostModal, LikePostButton } from './index';
import { PostService } from '../services';
import { RoleEnum } from '../utils';
import { useState } from 'react';

function Post({ id, title, content, likes, authorId, currentUser, likePost }) {
  const [showToast, setShowToast] = useState(false);
  const [toastMessage, setToastMessage] = useState('');
  const [toastTimeout, setToastTimeout] = useState(undefined);

  const userCanEdit =
    currentUser?.role == RoleEnum.ADMIN || authorId == currentUser?.id;

  const toast = (message) => {
    clearTimeout(toastTimeout);

    setShowToast(true);
    setToastMessage(message);

    const t = setTimeout(() => {
      setShowToast(false);
      setToastMessage('');
    }, 4000);

    setToastTimeout(t);
  };

  const handleLike = () => {
    const postLikeToBackend = async () => {
      if (authorId !== currentUser?.id) {
        try {
          const likedPost = await PostService.likePost(id);
          toast(`Successfully liked ${likedPost.title}.`);
          likePost(id);
        } catch (e) {
          console.error(e);
          window.alert(e);
        }
      } else {
        toast('You cannot like your own post!');
      }
    };
    postLikeToBackend();
  };

  return (
    <>
      <div className="mb-12 toast">
        <div
          className={`alert alert-info bg-secondary text-semibold ${
            showToast ? '' : 'hidden'
          } ${showToast ? '' : 'hidden'}`}
        >
          <span>{toastMessage}</span>
        </div>
      </div>
      <div
        data-id={id}
        className="w-[calc(100vw-4rem)] h-full shadow-lg md:w-full card outline outline-1 outline-neutral bg-base-100"
      >
        <div className="card-body">
          <h2 className="mb-2 truncate card-title">{title}</h2>
          <p>{content}</p>
          <div className="flex justify-end gap-4 mt-4">
            {userCanEdit ? (
              <>
                <DeletePostModal id={id} title={title} />
                <UpdatePostModal id={id} title={title} content={content} />
              </>
            ) : (
              ''
            )}
            {currentUser !== null ? (
              <LikePostButton likes={likes} handleLike={handleLike} />
            ) : (
              ''
            )}
          </div>
        </div>
      </div>
    </>
  );
}

Post.propTypes = {
  id: propTypes.number.isRequired,
  title: propTypes.string.isRequired,
  content: propTypes.string.isRequired,
  likes: propTypes.number.isRequired,
  authorId: propTypes.number.isRequired,
  currentUser: propTypes.object,
  likePost: propTypes.func.isRequired,
};

export default Post;
