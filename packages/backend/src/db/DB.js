const mongoose = require("mongoose");

mongoose
  .connect("mongodb://localhost:27017/parentalJobs", { useNewUrlParser: true })
  .then(() => console.log("mongodb connection succesful"))
  .catch(err => console.error(err));

const Schema = mongoose.Schema;

const Job = new Schema({
  test: String
});

const JobsModel = mongoose.model("jobs", Job);

JobsModel.find({}, function(err, docs) {
  console.log(docs);
});
