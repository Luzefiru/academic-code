import axios from 'axios';

const baseUrl =
  'https://my-json-server.typicode.com/troy1129/jsonplaceholder/destinations';

const getDestinations = async () => {
  const { data } = await axios.get(baseUrl);
  return data;
};

export default { getDestinations };
