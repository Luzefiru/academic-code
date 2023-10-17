export default function PassengerCard({
  passenger,
  destinations,
  changeDestination,
}) {
  const { name, id, destination } = passenger;

  const handleChangeDestination = (id, newDestination) => {
    console.log(id, newDestination);
    changeDestination({ id, destination: newDestination });
    document.activeElement.blur();
  };

  const colorClasses = {
    '': 'card bg-neutral text-neutral-content',
    Cebu: 'card bg-primary text-primary-content',
    Mandaue: 'card bg-primary text-primary-content',
    'Lilo-an': 'card bg-secondary text-secondary-content',
    'Lapu-Lapu': 'card bg-secondary text-secondary-content',
    Consolacion: 'card bg-accent text-accent-content',
    Talisay: 'card bg-accent text-accent-content',
  };

  return (
    <>
      <div className={colorClasses[destination]}>
        <div className="p-6 card-body">
          <h2 className="card-title">
            {name}, #{id}{' '}
          </h2>
          {destination != '' ? (
            <div className="badge badge-outline">{destination}</div>
          ) : (
            ''
          )}
          <div className="justify-end card-actions">
            <div className="dropdown dropdown-right dropdown-end">
              <label tabIndex={0} className="m-1 btn">
                Move
              </label>
              <ul
                tabIndex={0}
                className="dropdown-content z-[1] menu p-2 shadow bg-base-100 rounded-box w-52"
              >
                {destinations.map((d) => (
                  <li key={d.id}>
                    <button
                      onClick={() => {
                        handleChangeDestination(id, d.destination);
                      }}
                    >
                      {d.destination}
                    </button>
                  </li>
                ))}
              </ul>
            </div>
          </div>
        </div>
      </div>
    </>
  );
}
