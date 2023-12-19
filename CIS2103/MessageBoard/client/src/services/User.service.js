import axios from 'axios';
import { userStorage } from '../utils';
const baseUrl = 'http://localhost:5136/user';

const UserService = (() => {
  const loginUser = async ({ username, password }) => {
    const args = '?' + new URLSearchParams({ username, password }).toString();
    const { data } = await axios.post(`${baseUrl}/login` + args);
    userStorage.loginUser(data);
    window.location.reload();
  };

  const logoutUser = () => {
    userStorage.logoutUser();
    window.location.reload();
  };

  return { loginUser, logoutUser };
})();

export default UserService;
