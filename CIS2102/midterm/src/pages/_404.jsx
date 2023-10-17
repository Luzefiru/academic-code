import { Link } from 'react-router-dom';

function _404() {
  return (
    <div className="p-12">
      <h1 className="text-3xl font-bold">404: Page Not Found</h1>
      <p className="pt-6">Make sure you are using the correct links.</p>
      <div className="pt-6">
        <Link to="/" className="mt-6 link link-accent">
          Back to home?
        </Link>
      </div>
    </div>
  );
}

export default _404;
