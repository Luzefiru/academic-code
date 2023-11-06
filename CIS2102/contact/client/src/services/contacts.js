import axios from 'axios';

const getContacts = async () => {
    const {data} = await axios.get('http://localhost:3001/api/contacts/');

    return data;
}

const createContact = async ({student_id, name, age, contact, course}) => {
    const {data} = await axios.post('http://localhost:3001/api/contacts/', {student_id, name, age, contact, course});

    return data[0];
}

const deleteContact = async (student_id) => {
    await axios.delete('http://localhost:3001/api/contacts/' + student_id);
}

const updateContact = async (contact) => {
    await axios.put('http://localhost:3001/api/contacts', contact);
}

const exports = {getContacts, createContact, deleteContact, updateContact}

export default exports;

