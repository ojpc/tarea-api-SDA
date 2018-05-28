app.config(['$routeProvider', function ($routeProvider) {
    $routeProvider
        .when('/temperature', {
            templateUrl : 'views/temperature.html',
            controller  : 'tempController'
        })
        .when('/humidity', {
            templateUrl : 'views/humidity.html',
            controller  : 'humController'
        });
}]);
