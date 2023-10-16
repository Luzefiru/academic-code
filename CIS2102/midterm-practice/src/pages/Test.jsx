import useAuth from '../context/useAuth';

function Test() {
  const { currentUser } = useAuth();

  return (
    <div>
      <p>current user: {JSON.stringify(currentUser)}</p>
      <br />
    </div>
  );
}

export default Test;
