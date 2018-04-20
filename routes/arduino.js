var express = require('express');
var router = express.Router();
var Arduino = require('../board')

router.get('/', function (req, res){
  res.send("arduino");
})

router.get('/:pin/:value', function(req, res){
  Arduino.digitalWrite(req.params.pin, req.params.value);
  res.send({
    pin : req.params.pin,
    value : req.params.value
  })
})

module.exports = router
