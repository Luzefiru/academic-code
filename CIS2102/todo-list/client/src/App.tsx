import useTodo from './hooks/useTodo';

import { BrowserRouter, Routes, Route } from 'react-router-dom';
import Home from './pages/Home';
import Todo from './pages/TodoInfo';
import NotFound from './pages/NotFound';

function App() {
  const todoHelper = useTodo();

  return (
    <>
      <div className="px-8 pt-12 lg:px-32">
        <BrowserRouter basename="/academic-code">
          <Routes>
            <Route path="/" element={<Home {...todoHelper} />} />
            <Route
              path="/todo/:id"
              element={<Todo todos={todoHelper.todos} />}
            />
            <Route path="*" element={<NotFound />} />
          </Routes>
        </BrowserRouter>
      </div>
    </>
  );
}

export default App;
