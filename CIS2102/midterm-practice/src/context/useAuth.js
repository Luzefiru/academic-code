import { useState } from 'react';

export default function useAuth() {
  const [currentUser, setCurrentUser] = useState(null);

  const handleLogIn = ({ username, password }) => {
    console.log(`Logging in ${username} with ${password}`);
    setCurrentUser({ username });
  };

  const handleLogOut = () => {
    setCurrentUser(null);
  };

  return { currentUser, handleLogIn, handleLogOut };
}
