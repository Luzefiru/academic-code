import { useNavigate } from 'react-router-dom';

export default function Home() {
  const navigate = useNavigate();

  return (
    <>
      <div className="">
        <div
          className="min-h-screen hero"
          style={{
            backgroundImage:
              'url(https://daisyui.com/images/stock/photo-1507358522600-9f71e620c44e.jpg)',
          }}
        >
          <div className="hero-overlay bg-opacity-60"></div>
          <div className="text-center text-white hero-content">
            <div className="max-w-2xl">
              <h1 className="mb-5 text-5xl font-bold">
                Giving you full control over your passenger data.
              </h1>
              <p className="mb-5">
                MyBus is a revolutionary application that allows you to
                seamlessly track data from the comfort of your mobile device. We
                cover routes from Cebu to Lapu-Lapu and more.
              </p>
              <button
                onClick={() => {
                  navigate('/passengers');
                }}
                className="btn btn-primary"
              >
                Get Started
              </button>
            </div>
          </div>
        </div>
      </div>
    </>
  );
}
