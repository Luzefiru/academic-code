import propTypes from 'prop-types';
import { DeletePostModal, UpdatePostModal, LikePostButton } from './index';
import { RoleEnum } from '../utils';

function Post({ id, title, content, likes, authorId, currentUser }) {
  const userCanEdit =
    currentUser?.role == RoleEnum.ADMIN || authorId == currentUser?.id;
  return (
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
          {currentUser !== null ? <LikePostButton id={id} likes={likes} /> : ''}
        </div>
      </div>
    </div>
  );
}

Post.propTypes = {
  id: propTypes.number.isRequired,
  title: propTypes.string.isRequired,
  content: propTypes.string.isRequired,
  likes: propTypes.number.isRequired,
  authorId: propTypes.number.isRequired,
  currentUser: propTypes.object,
};

export default Post;
