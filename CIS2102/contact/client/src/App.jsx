import {useState, useEffect} from 'react';
import contactService from './services/contacts';
import Entry from './components/Entry';

function App() {
  const [contacts, setContacts] = useState([]);
  const [studentId, setStudentId] = useState('');
  const [name, setName] = useState('');
  const [age, setAge] = useState('');
  const [contactNumber, setContactNumber] = useState('');
  const [course, setCourse] = useState('');

  const handleDelete = async (student_id) => {
    const contactToDelete = contacts.find((c) => c.student_id === student_id);

    if (contactToDelete) {
      try {
      
        await contactService.deleteContact(student_id);
        setContacts(contacts.filter(c => c.student_id !== contactToDelete.student_id));
      } catch(e) {
        window.alert(e.response?.data?.errors[0]?.message)
      }
    }    
  }

  const handleUpdate = async (contact) => {
    try {
      await contactService.updateContact(contact);
      setContacts([...contacts.filter(c => c.student_id !== contact.student_id), contact])
    } catch(e) {
      window.alert(e.response?.data?.errors[0]?.message)
    }
  }

  const handleSubmit = async () => {
    if (studentId && name && age && contactNumber && course) {
      
      try {
        const newContact = await contactService.createContact({student_id: studentId, name, age, contact: contactNumber, course})
        setContacts([...contacts, newContact]);
      } catch(e) {
        window.alert(e.response?.data?.errors[0]?.message)
      }
      
    } else {
      window.alert("Fields must not be empty.");
    }
  }

  const handleChange = (e, setValue) => {
    setValue(e.target.value);
  }

  useEffect(() => {
    const fetchInitialData = async () => {
      const contactsArray = await contactService.getContacts();
      setContacts(contactsArray);
      console.log(contactsArray);
    }

    fetchInitialData();
  }, [])
 
  return (
    <>
      <h1>Contact Form</h1>
      <div>
        <label htmlFor="student_id">Student ID: </label>
        <input id="student_id" value={studentId} onChange={(e) => {handleChange(e, setStudentId)}} />
      </div>
      <div>
        <label htmlFor="name">Name: </label>
        <input id="name" value={name} onChange={(e) => {handleChange(e, setName)}} />
      </div>
      <div>
        <label htmlFor="age">Age: </label>
        <input id="age" value={age} onChange={(e) => {handleChange(e, setAge)}} />
      </div>
      <div>
        <label htmlFor="contact">Contact Number: </label>
        <input id="contact" value={contactNumber} onChange={(e) => {handleChange(e, setContactNumber)}} />
      </div>
      <div>
        <label htmlFor="course">Course: </label>
        <input id="course" value={course} onChange={(e) => {handleChange(e, setCourse)}} />
      </div>
      
      <button onClick={handleSubmit}>Submit</button>
      <hr/>
      <h2>Contact List</h2>
      <ul>
        {contacts.map(c => <Entry key={c.student_key} handleUpdate={handleUpdate} handleDelete={handleDelete} student_id={c.student_id} name={c.name} course={c.course} contact={c.contact} age={c.age} />)}
      </ul>
    </>
  )
}

export default App
