const express = require('express');
const path = require('path');

const app = express();

app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));

app.post('/login', (req, res) => {
    console.log(req.body);
    console.log(req.headers);

    // shows in server
    console.log("Login Successfully!")

    res.send({message: "Success"});
});

app.listen(8080, () => {
    console.log("Server Started and Continuously running...");
})