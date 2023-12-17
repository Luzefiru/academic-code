import { CreatePostModal } from './index';
import { useState, useEffect } from 'react';

function Navbar() {
  const [isDark, setisDark] = useState(
    JSON.parse(localStorage.getItem('isDark'))
  );
  useEffect(() => {
    localStorage.setItem('isDark', JSON.stringify(isDark));
  }, [isDark]);

  return (
    <div className="sticky top-0 z-50 px-4 mb-8 shadow-sm navbar bg-base-100">
      <div className="navbar-start">
        <a className="flex items-center justify-center text-2xl btn btn-ghost">
          <svg
            className="md:w-6 md:h-6 w-8 h-8 pt-[0.125rem]"
            viewBox="0 0 256 205"
            version="1.1"
            xmlns="http://www.w3.org/2000/svg"
            xmlnsXlink="http://www.w3.org/1999/xlink"
            preserveAspectRatio="xMidYMid"
          >
            <g>
              <path
                d="M27.008,53.504 L2.368,93.824 C0.768,96.32 0,99.264 0,102.4 C0,105.536 0.768,108.48 2.368,111.04 L59.712,204.8 L119.424,204.8 L27.008,53.504 L27.008,53.504 Z M59.712,0 L33.92,42.112 L63.808,91.008 L119.488,0 L59.712,0 L59.712,0 Z M228.992,151.296 L253.632,110.976 C255.232,108.48 256,105.536 256,102.4 C256,99.264 255.232,96.32 253.632,93.76 L196.288,0 L136.576,0 L228.992,151.296 L228.992,151.296 Z M196.288,204.8 L222.08,162.688 L192.192,113.792 L136.512,204.8 L196.288,204.8 L196.288,204.8 Z"
                fill="currentColor"
              ></path>
            </g>
          </svg>
          <span className="hidden md:inline">Inbound Relay</span>
        </a>
      </div>
      <div className="flex gap-2 navbar-end md:gap-4">
        <CreatePostModal />
        <button className="btn btn-sm md:btn-md btn-square">
          <label className="swap swap-rotate">
            <input
              type="checkbox"
              className="theme-controller"
              value="night"
              checked={isDark}
              onChange={() => setisDark(!isDark)}
            />
            <svg
              className="w-5 h-5 fill-current swap-on"
              xmlns="http://www.w3.org/2000/svg"
              viewBox="0 0 24 24"
            >
              <path d="M5.64,17l-.71.71a1,1,0,0,0,0,1.41,1,1,0,0,0,1.41,0l.71-.71A1,1,0,0,0,5.64,17ZM5,12a1,1,0,0,0-1-1H3a1,1,0,0,0,0,2H4A1,1,0,0,0,5,12Zm7-7a1,1,0,0,0,1-1V3a1,1,0,0,0-2,0V4A1,1,0,0,0,12,5ZM5.64,7.05a1,1,0,0,0,.7.29,1,1,0,0,0,.71-.29,1,1,0,0,0,0-1.41l-.71-.71A1,1,0,0,0,4.93,6.34Zm12,.29a1,1,0,0,0,.7-.29l.71-.71a1,1,0,1,0-1.41-1.41L17,5.64a1,1,0,0,0,0,1.41A1,1,0,0,0,17.66,7.34ZM21,11H20a1,1,0,0,0,0,2h1a1,1,0,0,0,0-2Zm-9,8a1,1,0,0,0-1,1v1a1,1,0,0,0,2,0V20A1,1,0,0,0,12,19ZM18.36,17A1,1,0,0,0,17,18.36l.71.71a1,1,0,0,0,1.41,0,1,1,0,0,0,0-1.41ZM12,6.5A5.5,5.5,0,1,0,17.5,12,5.51,5.51,0,0,0,12,6.5Zm0,9A3.5,3.5,0,1,1,15.5,12,3.5,3.5,0,0,1,12,15.5Z" />
            </svg>
            <svg
              className="w-5 h-5 fill-current swap-off"
              xmlns="http://www.w3.org/2000/svg"
              viewBox="0 0 24 24"
            >
              <path d="M21.64,13a1,1,0,0,0-1.05-.14,8.05,8.05,0,0,1-3.37.73A8.15,8.15,0,0,1,9.08,5.49a8.59,8.59,0,0,1,.25-2A1,1,0,0,0,8,2.36,10.14,10.14,0,1,0,22,14.05,1,1,0,0,0,21.64,13Zm-9.5,6.69A8.14,8.14,0,0,1,7.08,5.22v.27A10.15,10.15,0,0,0,17.22,15.63a9.79,9.79,0,0,0,2.1-.22A8.11,8.11,0,0,1,12.14,19.73Z" />
            </svg>
          </label>
        </button>
      </div>
    </div>
  );
}

export default Navbar;
