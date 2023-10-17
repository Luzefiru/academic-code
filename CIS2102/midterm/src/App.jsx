// Libraries
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
// Hooks
import { useEffect, useState } from 'react';
// Components
import { ToastContainer, toast } from 'react-toastify';
import 'react-toastify/dist/ReactToastify.css';
import Navbar from './components/Navbar';
import Footer from './components/Footer';
// Pages
import Home from './pages/Home';
import Passengers from './pages/Passengers';
import BusList from './pages/BusList';
import _404 from './pages/_404';
// Services
import passengersService from './helpers/passengers.service';
import destinationsService from './helpers/destinations.service';

function App() {
  const [passengers, setPassengers] = useState([]);
  const [destinations, setDestinations] = useState([]);

  const addPassenger = ({ name, id }) => {
    const passengerAlreadyExists = passengers.find((p) => p.id == id);

    if (passengerAlreadyExists) {
      toast.error(`Passenger with ID ${id} already exists!`, {
        position: 'bottom-right',
        autoClose: 5000,
        hideProgressBar: false,
        closeOnClick: true,
        pauseOnHover: true,
        draggable: true,
        progress: undefined,
        theme: 'colored',
      });
      return false;
    }

    setPassengers([...passengers, { name, id, destination: '' }]);

    toast.success(`Successfully added ${name}, #${id} to queue!`, {
      position: 'bottom-right',
      autoClose: 5000,
      hideProgressBar: false,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: true,
      progress: undefined,
      theme: 'colored',
    });

    return true;
  };

  const changeDestination = ({ id, destination }) => {
    const { name } = passengers.find((p) => p.id == id);
    setPassengers([
      ...passengers.filter((p) => p.id != id),
      { name, id, destination },
    ]);

    toast.info(`${name} is going to ${destination}.`, {
      position: 'bottom-right',
      autoClose: 5000,
      hideProgressBar: false,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: true,
      progress: undefined,
      theme: 'colored',
    });
  };

  useEffect(() => {
    const getData = async () => {
      const passengers = await passengersService.getPassengers();
      const destinations = await destinationsService.getDestinations();
      setPassengers(passengers);
      setDestinations(destinations);
    };
    getData();
  }, []);

  return (
    <>
      <div className="flex flex-col h-screen overflow-x-hidden">
        <Router>
          <Navbar />
          <main>
            <Routes>
              <Route
                path="/"
                element={
                  <Home passengers={passengers} destinations={destinations} />
                }
              />
              <Route
                path="/passengers"
                element={
                  <Passengers
                    passengers={passengers}
                    addPassenger={addPassenger}
                    changeDestination={changeDestination}
                    destinations={destinations}
                  />
                }
              />
              <Route
                path="/bus-list"
                element={
                  <BusList
                    passengers={passengers}
                    changeDestination={changeDestination}
                    destinations={destinations}
                  />
                }
              />
              <Route path="*" element={<_404 />} />
            </Routes>
          </main>
          <Footer />
        </Router>
      </div>
      <ToastContainer
        position="top-center"
        autoClose={5000}
        hideProgressBar={false}
        newestOnTop={false}
        closeOnClick
        rtl={false}
        pauseOnFocusLoss
        draggable
        pauseOnHover
        theme="colored"
      />
    </>
  );
}

export default App;
