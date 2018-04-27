var express = require('express')
var bodyParser = require('body-parser')
var morgan = require('morgan')
var mongoose = require('mongoose')

var app = express()

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(morgan('common'));

// --- Mongo Config ---
mongoose.Promise = global.Promise;
mongoose.connect( process.env.MONGODB_URI || "mongodb://localhost:27017/sda");


// var arduino = require('./routes/arduino')
// app.use('/arduino', arduino);

var users = require('./routes/users')
app.use('/users', users)

app.get('/', function (req, res) {
  res.send({
    message : "Hello World"
  })
})

module.exports = app;
