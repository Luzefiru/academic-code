const router = require('express').Router();
const sequelize = require('../util/db');

sequelize.query(`
  CREATE TABLE IF NOT EXISTS contacts (
    student_id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    age INTEGER NOT NULL,
    contact TEXT NOT NULL,
    course TEXT NOT NULL
  );
`);

router.get('/', async (_, res) => {
    const [results] = await sequelize.query(`
        SELECT * FROM contacts;
    `)

    res.status(200).json(results);
})

router.post('/', async (req, res) => {
    const {student_id, name, age, contact, course} = req.body;

    try {
        const [_, rowsAffected] = await sequelize.query(`
            INSERT INTO contacts (student_id, name, age, contact, course)
            VALUES (:student_id, :name, :age, :contact, :course)
        `, {replacements: {student_id, name, age, contact, course}})
        const [newContact] = await sequelize.query(`SELECT * FROM contacts WHERE student_id = :student_id`, {replacements: {student_id}})
        res.status(201).json(newContact)
    } catch(e) {
        res.status(400).json(e);
    }
})

router.delete('/:student_id', async (req, res) => {
    const student_id = req.params.student_id;
    
        const [existingContact] = await sequelize.query(`SELECT * FROM contacts WHERE student_id = :student_id`, {replacements: {student_id}})

        if (existingContact.length !== 0) {
            const result = await sequelize.query(`
                DELETE FROM contacts
                WHERE student_id = :student_id
            `, {replacements: {student_id}})
            
            res.status(204).json(result)
        } else {
            res.status(400).json(e);        
        }
})

router.put('/', async (req, res) => {
    const {student_id, name, age, contact, course} = req.body;

    try {
        const [existingContact] = await sequelize.query(`SELECT * FROM contacts WHERE student_id = :student_id`, {replacements: {student_id}})

        if (existingContact.length !== 0) {
            const [_, rowsAffected] = await sequelize.query(`
            UPDATE contacts
            SET student_id = :student_id, name = :name, age = :age, contact = :contact, course = :course
            WHERE student_id = :student_id
            `, {replacements: {student_id, name, age, contact, course}})

            const [newContact] = await sequelize.query(`SELECT * FROM contacts WHERE student_id = :student_id`, {replacements: {student_id}})
            res.status(202).json(newContact);
        } else {
            return res.status(400).json({error: 'does not exist'});
        }
    } catch(e) {
        return res.status(400).json(e);
    }
})

module.exports = router;