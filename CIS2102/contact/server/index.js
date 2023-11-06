const { PORT } = require('./util/config');

const express = require('express');
const app = express();
require('express-async-errors');
app.use(express.json());
app.use(require('cors')());

const contactRouter = require('./controllers/contacts.controller'); 
app.use('/api/contacts', contactRouter);

app.listen(PORT, () => {
    console.log("Server is now listening on port " + PORT);
})