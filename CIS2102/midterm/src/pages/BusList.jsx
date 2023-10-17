import Sales from '../components/Sales';
import PassengerCard from '../components/PassengerCard';

function BusList({ passengers, destinations, changeDestination }) {
  const getPriceOfDestination = (destinationName) => {
    return (
      destinations.find((d) => d.destination == destinationName)?.price ?? 0
    );
  };

  const sales = passengers
    .map((p) => getPriceOfDestination(p.destination))
    .reduce((prev, cur) => prev + cur, 0);

  if (passengers.length == 0 || destinations.length == 0) {
    return (
      <span className="absolute transform -translate-x-1/2 -translate-y-1/2 loading loading-bars loading-lg top-1/2 left-1/2"></span>
    );
  }

  return (
    <div className="flex flex-col mx-24 my-8">
      <Sales sales={sales} />

      <div className="py-6">
        <h1 className="pb-8 text-4xl font-bold">
          Bus 1 <i>(Cebu - Mandaue)</i>
        </h1>
        <div className="grid grid-cols-5 gap-12">
          {passengers
            .filter(
              (p) => p.destination == 'Cebu' || p.destination == 'Mandaue'
            )
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

      <div className="py-6">
        <h1 className="pb-8 text-4xl font-bold">
          Bus 2 <i>(Lilo-an - Lapu-Lapu)</i>
        </h1>
        <div className="grid grid-cols-5 gap-12">
          {passengers
            .filter(
              (p) => p.destination == 'Lilo-an' || p.destination == 'Lapu-Lapu'
            )
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

      <div className="py-6">
        <h1 className="pb-8 text-4xl font-bold">
          Bus 3 <i>(Consolacion - Talisay)</i>
        </h1>
        <div className="grid grid-cols-5 gap-12">
          {passengers
            .filter(
              (p) =>
                p.destination == 'Consolacion' || p.destination == 'Talisay'
            )
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

export default BusList;
