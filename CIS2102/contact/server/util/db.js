const { Sequelize } = require('sequelize');
const { POSTGRES_DB, POSTGRES_USER, POSTGRES_PASSWORD } = require('./config');

const sequelize = new Sequelize(POSTGRES_DB, POSTGRES_USER, POSTGRES_PASSWORD, {
  host: 'localhost',
  port: 5432,
  dialect: 'postgres',
});

(async () => {
  try {
    await sequelize.authenticate();
    console.log('Connected to DB.');
  } catch (e) {
    console.log('Unable to connect to DB.', e);
  }
})();

module.exports = sequelize;
