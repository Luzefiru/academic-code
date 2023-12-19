import './App.css';
import { Navbar, Footer, PostGrid, Landing } from './components';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';

function App() {
  return (
    <Router>
      <Navbar />
      <Routes>
        <Route
          index
          element={
            <div className="App">
              <PostGrid />
            </div>
          }
        />
        <Route path="home" element={<Landing />} />
      </Routes>
      <Footer />
    </Router>
  );
}

export default App;
