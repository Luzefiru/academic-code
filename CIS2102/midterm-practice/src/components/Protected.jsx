import { Outlet, Navigate } from 'react-router';

function Protected({ currentUser }) {
  return currentUser ? <Outlet /> : <Navigate to="/login" />;
}

export default Protected;
