import propTypes from 'prop-types';
import { DeletePostModal, UpdatePostModal } from './index';

function Post({ id, title, content }) {
  return (
    <div
      data-id={id}
      className="w-[calc(100vw-4rem)] h-full shadow-lg md:w-full card outline outline-1 outline-neutral bg-base-100"
    >
      <div className="card-body">
        <h2 className="mb-2 truncate card-title">{title}</h2>
        <p>{content}</p>
        <div className="flex justify-end gap-4 mt-4">
          <DeletePostModal id={id} title={title} />
          <UpdatePostModal id={id} title={title} content={content} />
        </div>
      </div>
    </div>
  );
}

Post.propTypes = {
  id: propTypes.number.isRequired,
  title: propTypes.string.isRequired,
  content: propTypes.string.isRequired,
};

export default Post;
