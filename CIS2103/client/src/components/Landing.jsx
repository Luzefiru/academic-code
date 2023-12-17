import { useNavigate } from 'react-router-dom';

function Landing() {
  const navigate = useNavigate();
  return (
    <>
      <div className="">
        <div
          className="min-h-[calc(100vh-5rem)] hero"
          style={{
            backgroundImage:
              'url(https://images.unsplash.com/photo-1511447333015-45b65e60f6d5?q=80&w=2155&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D)',
          }}
        >
          <div className="bg-opacity-40 hero-overlay"></div>
          <div className="text-center text-white hero-content">
            <div className="max-w-2xl">
              <h1 className="mb-5 text-2xl font-bold lg:text-5xl">
                Anonymous Posting
                <br />
                Made Easy
              </h1>
              <p className="mb-5">
                Inbound Relay is your one-stop-shop for anonymous posting. Share
                your thoughts and opinions with the world in a fast-paced
                message board. Create an account now and join hundreds of other
                users in the global communication pipeline!
              </p>
              <button
                onClick={() => {
                  navigate('/');
                }}
                className="text-xl font-semibold btn btn-primary"
              >
                Let&apos;s Go!
              </button>
            </div>
          </div>
        </div>
      </div>
    </>
  );
}

export default Landing;
