import { useState } from 'react';

const useInput = (str?: string) => {
  const [value, setValue] = useState(str ? str : '');

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
