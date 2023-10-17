import { NavLink } from 'react-router-dom';

function Navbar() {
  return (
    <nav className="navbar bg-base-100">
      <div className="flex-1">
        <NavLink to="/" className="text-xl normal-case btn btn-ghost">
          MyBus
        </NavLink>
      </div>
      <div className="flex-none">
        <ul className="gap-4 px-1 menu menu-horizontal">
          <li>
            <NavLink to="/passengers">Passengers</NavLink>
          </li>
          <li>
            <NavLink to="/bus-list">Bus List</NavLink>
          </li>
        </ul>
      </div>
    </nav>
  );
}

export default Navbar;
