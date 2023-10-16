// Libraries
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
// Hooks
import useAuth from './hooks/useAuth';
// Components
import Navbar from './components/Navbar';
import Footer from './components/Footer';
import Protected from './components/Protected';
// Pages
import Home from './pages/Home';
import LogIn from './pages/LogIn';
import Test from './pages/Test';
import _404 from './pages/_404';

function App() {
  // Global State
  const { currentUser } = useAuth();

  return (
    <div className="flex flex-col h-[100lvh]">
      <Router>
        <Navbar />
        <main>
          <Routes>
            <Route path="/" element={<Protected currentUser={currentUser} />}>
              <Route index element={<Home />} />
            </Route>
            <Route path="/login" element={<LogIn />} />
            <Route path="/test" element={<Test />} />
            <Route path="*" element={<_404 />} />
          </Routes>
        </main>
        <Footer />
      </Router>
    </div>
  );
}

export default App;
