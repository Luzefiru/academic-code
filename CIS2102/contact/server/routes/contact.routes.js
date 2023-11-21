const router = require('express').Router();
const { db } = require('../config');

router.get('/', (_, res, next) => {
  const sql = `SELECT * FROM contact`;
  db.query(sql, (e, results) => {
    if (e) {
      return next(e);
    }

    res.status(200).json(results);
  });
});

router.post('/', (req, res, next) => {
  const { student_id, name, age, contact, course } = req.body;

  const sql = `
    INSERT INTO contact (student_id, name, age, contact, course)
    VALUES (?, ?, ?, ?, ?)
  `;

  db.query(
    sql,
    [student_id, name, age, contact, course],
    (e, results, fields) => {
      if (e) {
        return next(e);
      }

      db.query(
        `SELECT * FROM contact WHERE id = ?`,
        [results.insertId],
        (e, results) => {
          if (e) {
            return next(e);
          }

          res.status(201).json(results[0]);
        }
      );
    }
  );
});

router.put('/:id', (req, res, next) => {
  const { id } = req.params;
  const { student_id, name, age, contact, course } = req.body;
  const sql = `
    UPDATE contact
    SET student_id = ?, name = ?, age = ?, contact = ?, course = ?
    WHERE id = ?
  `;

  db.query(sql, [student_id, name, age, contact, course, id], (e, results) => {
    if (e) {
      return next(e);
    }

    db.query(`SELECT * FROM contact WHERE id = ?`, [id], (e, results) => {
      if (e) {
        return next(e);
      }

      res.status(200).json(results[0]);
    });
  });
});

router.delete('/:id', (req, res, next) => {
  const { id } = req.params;
  const sql = `
    DELETE FROM contact
    WHERE id = ?
  `;

  db.query(sql, [id], (e, results) => {
    if (e) {
      return next(e);
    }

    res.status(204).end();
  });
});

module.exports = router;
