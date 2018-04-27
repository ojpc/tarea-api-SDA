var mongoose = require('mongoose');
// var bcrypt   = require('bcrypt-nodejs');

var userSchema = mongoose.Schema({
  name : {type : String, required: true},
  email : {type : String, required: true},
  password : {type: String, required: true},
  bio : {type: String}
});

userSchema.statics.findUser = function(req, res, next){
  console.log(req.body.name || req.params.name)
  mongoose.model('User').findOne({name : req.body.name || req.params.name}, function(err, user){
    if(err){
      next(err)
    }
    else {
      console.log(user)
      req.user = user
      next();
    }
  })
}

// userSchema.methods.generateHash = function(password) {
//     return bcrypt.hashSync(password, bcrypt.genSaltSync(8), null);
// };

module.exports = mongoose.model('User', userSchema);
