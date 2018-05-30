var express = require('express');
var router = express.Router();


router.get('/', function(req, res, next){
  res.render('index.ejs');

});

router.get('/temperature', function(req, res, next){
  res.render('temperature.ejs');
});

router.get('/humidity', function(req, res, next){
  res.render('humidity.ejs');
});

module.exports = router
