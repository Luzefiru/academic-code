import axios from 'axios';
const baseUrl = 'http://localhost:5136/blogs';

const PostService = (() => {
  const getPosts = async () => {
    const { data } = await axios.get(baseUrl);
    return data;
  };

  const createPost = async ({ title, content }) => {
    const { data } = await axios.post(baseUrl, { title, content });
    return data;
  };

  const deletePost = async (id) => {
    await axios.delete(`${baseUrl}/${id}`);
    return;
  };

  const updatePost = async ({ id, title, content }) => {
    const { data } = await axios.put(`${baseUrl}/${id}`, { title, content });
    return data;
  };

  return { getPosts, createPost, deletePost, updatePost };
})();

export default PostService;
