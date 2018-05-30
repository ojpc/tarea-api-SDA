var app = angular.module("rt-sensor", ['btford.socket-io']);

app.factory('socket', function (socketFactory) {
  var myIoSocket = io.connect();
  mySocket = socketFactory({
    ioSocket: myIoSocket
  });
  console.log(mySocket)
  return mySocket;
});

app.controller("temperatureController", function($scope, socket) {

  socket.on('temperature', function(msg) {
    $scope.temperature = msg
  })

})

app.controller("humidityController", function($scope, socket) {

  socket.on('humidity', function(msg) {
    $scope.humidity = msg
  })

})
