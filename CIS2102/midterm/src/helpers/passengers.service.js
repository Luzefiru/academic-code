import axios from 'axios';

const baseUrl =
  'https://my-json-server.typicode.com/troy1129/jsonplaceholder/passengers';

const getPassengers = async () => {
  const { data } = await axios.get(baseUrl);
  return data;
};

export default { getPassengers };
