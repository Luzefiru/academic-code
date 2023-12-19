import { userStorage } from '../utils';

function LogoutButton() {
  const handleLogout = () => {
    userStorage.logoutUser();
  };

  return (
    <div
      className="font-semibold tooltip tooltip-bottom tooltip-error"
      data-tip="Log Out?"
    >
      <button className="btn btn-square hover:btn-error" onClick={handleLogout}>
        <svg
          xmlns="http://www.w3.org/2000/svg"
          width="20"
          height="20"
          viewBox="0 0 20 20"
        >
          <path
            fill="currentColor"
            fillRule="evenodd"
            d="M3 3a1 1 0 0 0-1 1v12a1 1 0 1 0 2 0V4a1 1 0 0 0-1-1m10.293 9.293a1 1 0 0 0 1.414 1.414l3-3a1 1 0 0 0 0-1.414l-3-3a1 1 0 1 0-1.414 1.414L14.586 9H7a1 1 0 1 0 0 2h7.586z"
            clipRule="evenodd"
          />
        </svg>
      </button>
    </div>
  );
}

export default LogoutButton;
