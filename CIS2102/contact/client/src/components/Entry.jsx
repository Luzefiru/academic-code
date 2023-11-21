import { useState } from 'react';

export default function Entry({
  id,
  student_id,
  name,
  course,
  contact,
  age,
  handleDelete,
  handleUpdate,
}) {
  const [isUpdating, setIsUpdating] = useState(false);
  const [newStudentId, setStudentId] = useState(student_id);
  const [newName, setName] = useState(name);
  const [newAge, setAge] = useState(age);
  const [newContactNumber, setContactNumber] = useState(contact);
  const [newCourse, setCourse] = useState(course);

  const handleChange = (e, setValue) => {
    setValue(e.target.value);
  };

  const handleSubmit = () => {
    handleUpdate({
      id,
      student_id,
      name: newName,
      age: newAge,
      contact: newContactNumber,
      course: newCourse,
    });
    setIsUpdating((prev) => !prev);
  };

  if (isUpdating) {
    return (
      <form>
        <h3>Contact Form</h3>
        <div>
          <label htmlFor="student_id">Student ID: </label>
          <input
            disabled
            id="student_id"
            value={newStudentId}
            onChange={(e) => {
              handleChange(e, setStudentId);
            }}
          />
        </div>
        <div>
          <label htmlFor="name">Name: </label>
          <input
            id="name"
            value={newName}
            onChange={(e) => {
              handleChange(e, setName);
            }}
          />
        </div>
        <div>
          <label htmlFor="age">Age: </label>
          <input
            id="age"
            value={newAge}
            onChange={(e) => {
              handleChange(e, setAge);
            }}
          />
        </div>
        <div>
          <label htmlFor="contact">Contact Number: </label>
          <input
            id="contact"
            value={newContactNumber}
            onChange={(e) => {
              handleChange(e, setContactNumber);
            }}
          />
        </div>
        <div>
          <label htmlFor="course">Course: </label>
          <input
            id="course"
            value={newCourse}
            onChange={(e) => {
              handleChange(e, setCourse);
            }}
          />
        </div>

        <button onClick={handleSubmit}>Submit</button>
      </form>
    );
  }

  return (
    <li>
      <div>
        {student_id}
        <br></br>
        {name}
        <br></br>
        {course}
        <br></br>
        {contact}
        <br></br>
        {age}
      </div>
      <div style={{ display: 'flex', gap: '8px', marginTop: '8px' }}>
        <button
          onClick={() => {
            handleDelete(student_id);
          }}
        >
          Delete
        </button>
        <button
          style={{ backgroundColor: 'gold' }}
          onClick={() => {
            setIsUpdating((prev) => !prev);
          }}
        >
          Update
        </button>
      </div>
    </li>
  );
}
