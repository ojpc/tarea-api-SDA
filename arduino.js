var Board = require('firmata')
var arduino = new Board('/dev/ttyACM0');
var io = require('./io')

arduino.on('ready', function(){
  console.log("Arduino connected");
  arduino.setSamplingInterval(10000);
  arduino.digitalRead(8, function(value) {
    io.emit('temperature', value);
  });
  arduino.digitalRead(9, function(value) {
    io.emit('humidity', value);
  });
})

module.exports = arduino;
