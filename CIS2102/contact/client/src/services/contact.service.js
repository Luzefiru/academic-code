import axios from 'axios';

const getContacts = async () => {
  const { data } = await axios.get('http://localhost:3000/contact');

  return data;
};

const createContact = async ({ student_id, name, age, contact, course }) => {
  const { data } = await axios.post('http://localhost:3000/contact', {
    student_id,
    name,
    age,
    contact,
    course,
  });

  return data;
};

const deleteContact = async (id) => {
  await axios.delete(`http://localhost:3000/contact/${id}`);
};

const updateContact = async (contact) => {
  await axios.put(`http://localhost:3000/contact/${contact.id}`, contact);
};

const exports = { getContacts, createContact, deleteContact, updateContact };

export default exports;
