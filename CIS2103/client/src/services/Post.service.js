import axios from 'axios';
const baseUrl = 'http://localhost:5136/blogs';

const mockUser = {
  id: 3,
  userName: 'admin',
  password: 'admin12345',
  role: 2,
};

const PostService = (() => {
  const getPosts = async () => {
    const { data } = await axios.get(baseUrl);
    return data;
  };

  const createPost = async (obj) => {
    const args = '?' + new URLSearchParams(obj).toString();
    const { data } = await axios.post(baseUrl + args, {
      ...mockUser,
    });
    return data;
  };

  const deletePost = async (id) => {
    await axios.delete(`${baseUrl}/${id}?userId=${mockUser.id}`);
    return;
  };

  const updatePost = async ({ id, title, content }) => {
    const args = '?' + new URLSearchParams({ title, content }).toString();
    const { data } = await axios.put(`${baseUrl}/${id}` + args, {
      ...mockUser,
    });
    return data;
  };

  return { getPosts, createPost, deletePost, updatePost };
})();

export default PostService;
