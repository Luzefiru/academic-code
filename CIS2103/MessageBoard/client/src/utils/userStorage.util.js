// A helper to validate a user to save to localStorage
const isValid = (user) => {
  if (
    !user ||
    typeof user.id !== 'number' ||
    typeof user.userName !== 'string' ||
    typeof user.role !== 'number'
  ) {
    return false; // User is not properly defined or has incorrect types
  }

  if (user.role < 0 || user.role > 2) {
    // Valid roles are 0, 1, 2
    return false;
  }

  return true;
};

// Allows the saving & retrieving of user data inside local storage for authentication purposes.
const userStorage = {
  getUser: () => {
    const user = localStorage.getItem('currentUser');
    return user ? JSON.parse(user) : null;
  },

  loginUser: (userToLogin) => {
    if (isValid(userToLogin)) {
      localStorage.setItem('currentUser', JSON.stringify(userToLogin));
    } else {
      throw new Error('Invalid user data.');
    }
  },

  logoutUser: () => {
    localStorage.removeItem('currentUser');
    window.location.reload();
  },
};

export default userStorage;
