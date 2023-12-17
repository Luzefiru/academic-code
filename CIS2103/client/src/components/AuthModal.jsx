import { useState } from 'react';
import { UserService } from '../services';

function AuthModal() {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');

  const handleClose = () => {
    document.getElementById('login-user').close();
    setUsername('');
    setPassword('');
    setError('');
  };

  const handleSubmit = () => {
    // input validation
    if (username === '' || password === '') {
      setError('Error: username or Password fields must not be empty!');
      return;
    }

    const loginUser = async () => {
      try {
        await UserService.loginUser({
          username,
          password,
        });
        setUsername('');
        setPassword('');
        setError('');
        handleClose();
        window.location.reload();
      } catch (e) {
        console.error(e);
        setError('Wrong username or password.');
      }
    };
    loginUser();
  };

  const handleChange = (e, setFn) => {
    setFn(e.target.value);
  };

  return (
    <>
      <button
        className="text-sm btn btn-sm btn-secondary md:btn-md md:text-lg"
        onClick={() => document.getElementById('login-user').showModal()}
      >
        Login
      </button>
      <dialog id="login-user" className="modal">
        <div className="w-4/12 max-w-5xl modal-box">
          <h3 className="text-xl font-bold">Welcome to Inbound Relay</h3>
          <div className="w-full py-4">
            <label className="label">
              <span className="font-semibold label-text">Username</span>
            </label>
            <input
              value={username}
              onChange={(e) => {
                handleChange(e, setUsername);
              }}
              type="text"
              placeholder="Your username"
              className="w-full input input-bordered"
            />
            <label className="label">
              <span className="font-semibold label-text">Password</span>
            </label>
            <input
              value={password}
              onChange={(e) => {
                handleChange(e, setPassword);
              }}
              type="password"
              placeholder="Your password"
              className="w-full input input-bordered"
            />
          </div>
          {error !== '' && <p className="font-semibold text-error">{error}</p>}
          <div className="modal-action">
            <div className="flex gap-4" method="dialog">
              {/* if there is a button, it will close the modal */}
              <button className="font-bold btn" onClick={() => handleClose()}>
                Cancel
              </button>
              <button
                className="btn btn-secondary"
                onClick={() => {
                  handleSubmit();
                }}
              >
                Login
              </button>
            </div>
          </div>
        </div>
      </dialog>
    </>
  );
}

export default AuthModal;
