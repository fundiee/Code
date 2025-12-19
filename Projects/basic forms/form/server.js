const express = require('express');
const path = require('path');

const app = express();

app.use(express.json());
// When someone requests localhost:8080/, serve files from the public folder to browser
app.use(express.static(path.join(__dirname, 'public')));

app.post('/login', (req, res) => {
    console.log("Username: ", req.body.username);
    console.log("Password: ", req.body.password);
    console.log("Content-Type: ", req.headers['content-type']);

    res.send({message: "Success"});
});

app.listen(8080, () => {
    console.log("Server Started and Continuously running...");
})