const mongoose = require("mongoose");

mongoose
  .connect("mongodb://localhost:27017/parentalJobs", { useNewUrlParser: true })
  .then(() => console.log("mongodb connection succesful"))
  .catch(err => console.error(err));

const Schema = mongoose.Schema;

/* TODO:
  Need to cleanup the type system, currently using string for all types, not so safe.
*/

const Job = new Schema({
  company: String,
  logoUrl: String,
  jobTitle: String,
  jobId: String,
  address: String,
  employmentType: String,
  seniority: String,
  minExperience: String,
  jobCategories: String,
  salary: {
    salaryFrom: String,
    salaryTo: String,
    salaryType: String
  },
  postedOn: String,
  jobDescription: String,
  requirement: String
});

const JobsModel = mongoose.model("jobs", Job);

export default JobsModel;
