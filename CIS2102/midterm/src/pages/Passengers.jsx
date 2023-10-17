import TicketForm from '../components/TicketForm';
import PassengerCard from '../components/PassengerCard';

export default function Passengers({
  passengers,
  addPassenger,
  changeDestination,
  destinations,
}) {
  if (passengers.length == 0 || destinations.length == 0) {
    return (
      <span className="absolute transform -translate-x-1/2 -translate-y-1/2 loading loading-bars loading-lg top-1/2 left-1/2"></span>
    );
  }

  return (
    <div className="flex flex-col mx-24 my-8">
      <TicketForm addPassenger={addPassenger} />
      <div className="py-6">
        <h1 className="pb-8 mt-8 text-4xl font-bold">Passenger Queue</h1>
        <div className="grid grid-cols-5 gap-12">
          {passengers
            .filter((p) => p.destination == '')
            .map((p) => (
              <PassengerCard
                key={p.id}
                passenger={p}
                destinations={destinations}
                changeDestination={changeDestination}
              />
            ))}
        </div>
      </div>
    </div>
  );
}
