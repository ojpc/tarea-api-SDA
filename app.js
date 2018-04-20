var express = require('express')
var bodyParser = require('body-parser')
var morgan = require('morgan')
var app = express()

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(morgan('common'));

var arduino = require('./routes/arduino')

app.use('/arduino', arduino);

app.get('/', function (req, res) {
  res.send(req.ejemplo)
})

module.exports = app;
