var sdaApi = angular.module('sdaApi', ['btford.socket-io', 'ngRoute']);
sdaApi.config(['$routeProvider', function ($routeProvider) {
    $routeProvider
        .when('/', {
            templateUrl : 'index.html',
            controller  : 'mainController'
        })
        .when('/temperature', {
            templateUrl : 'views/temperature.html',
            controller  : 'tempController'
        })
        .when('/humidity', {
            templateUrl : 'views/humidity.html',
            controller  : 'humController'
        });
}]);

sdaApi.factory('socket', function (socketFactory) {
  var myIoSocket = io.connect();
  mySocket = socketFactory({
    ioSocket: myIoSocket
  });
  return mySocket;
});

sdaApi.controller('mainController', function($scope, socket) {

});
sdaApi.controller('tempController', function($scope, socket) {
  socket.on('temperature', function(msg) {
    $scope.temperature = msg.temperature
})
});
sdaApi.controller('humController', function($scope, socket) {
  socket.on('humidity', function(msg) {
    $scope.humidity = msg.humidity
})
});
