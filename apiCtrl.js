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
  socket.on('read', function(msg) {
    $scope.temperatura = msg.temperatura
})
});
sdaApi.controller('humController', function($scope, socket) {
  socket.on('read', function(msg) {
    $scope.humedad = msg.humedad
})
});
