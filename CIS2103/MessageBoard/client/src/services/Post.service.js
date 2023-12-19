import axios from 'axios';
import { userStorage } from '../utils';
const baseUrl = 'http://localhost:5136/blogs';

const PostService = (() => {
  const getPosts = async () => {
    const { data } = await axios.get(baseUrl);
    return data.sort((a, b) =>
      a.likes < b.likes ? 1 : a.likes > b.likes ? -1 : 0
    );
  };

  const createPost = async (obj) => {
    const currentUser = userStorage.getUser();
    const args = '?' + new URLSearchParams(obj).toString();
    const { data } = await axios.post(baseUrl + args, {
      ...currentUser,
    });
    return data;
  };

  const deletePost = async (id) => {
    const currentUser = userStorage.getUser();
    await axios.delete(`${baseUrl}/${id}?userId=${currentUser.id}`);
    return;
  };

  const updatePost = async ({ id, title, content }) => {
    const currentUser = userStorage.getUser();
    const args = '?' + new URLSearchParams({ title, content }).toString();
    const { data } = await axios.put(`${baseUrl}/${id}` + args, {
      ...currentUser,
    });
    return data;
  };

  const likePost = async (id) => {
    const currentUser = userStorage.getUser();
    const { data } = await axios.post(`${baseUrl}/${id}/like`, {
      ...currentUser,
    });
    return data;
  };

  return { getPosts, createPost, deletePost, updatePost, likePost };
})();

export default PostService;
