import { useState } from 'react';

export default function TicketForm({ addPassenger }) {
  const [name, setName] = useState('');
  const [id, setId] = useState('');

  const handleInputChange = (e, setFunction) => {
    setFunction(e.target.value);
  };

  const handleSubmit = (e) => {
    e.preventDefault();

    const addWasSuccessful = Number.isInteger(id) && addPassenger({ name, id });

    if (addWasSuccessful) {
      console.log('Successfully addded', { name, id });
      setName('');
      setId('');
    } else {
      console.log('Failed to add, ID taken', { name, id });
    }
  };

  return (
    <>
      <h1 className="pb-8 text-4xl font-bold">New Passenger Form</h1>
      <form
        onSubmit={handleSubmit}
        className="flex flex-col p-6 rounded-lg outline outline-1 w-fit"
      >
        <div className="flex gap-8 pb-2">
          <div className="w-full max-w-xs form-control">
            <label className="label">
              <span className="label-text">What is your name?</span>
            </label>
            <input
              value={name}
              onChange={(e) => handleInputChange(e, setName)}
              required
              type="text"
              placeholder="Name"
              className="w-full max-w-xs input input-bordered"
            />
            <label className="label">
              <span className="label-text-alt">ex. John Doe</span>
            </label>
          </div>
          <div className="w-full max-w-xs form-control">
            <label className="label">
              <span className="label-text">What is your ticket ID number?</span>
            </label>
            <input
              value={id}
              onChange={(e) => handleInputChange(e, setId)}
              required
              type="text"
              placeholder="Ticket ID"
              className="w-full max-w-xs input input-bordered"
            />
            <label className="label">
              <span className="label-text-alt">ex. 123</span>
            </label>
          </div>
        </div>

        <button className="ml-auto btn">
          Add
          <svg
            xmlns="http://www.w3.org/2000/svg"
            className="w-5 h-5"
            fill="none"
            viewBox="0 0 24 24"
            stroke="currentColor"
          >
            <path
              strokeLinecap="round"
              strokeWidth="2"
              d="M19,13H13V19H11V13H5V11H11V5H13V11H19V13Z"
            />
          </svg>
        </button>
      </form>
    </>
  );
}
