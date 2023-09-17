import { useState } from 'react';

const useInput = () => {
  const [value, setValue] = useState('');

  const handleChange = (
    e: React.ChangeEvent<HTMLInputElement | HTMLTextAreaElement>
  ) => {
    setValue(e.target.value);
  };

  const clear = () => {
    setValue('');
  };

  return [value, clear, handleChange] as const;
};

export default useInput;
