(* Auto-generated from "jobs.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type salary = { salaryFrom: string; salaryTo: string; salaryType: string }

type jobOverview = {
  _id: string;
  company: string;
  jobTitle: string;
  employmentType: string;
  seniority: string;
  minExperience: string;
  jobCategories: string;
  salary: salary;
  postedOn: string
}

type latestJobs = jobOverview list

type jobs = jobOverview list

type job = {
  _id: string;
  company: string;
  jobTitle: string;
  jobId: string;
  address: string;
  employmentType: string;
  seniority: string;
  minExperience: string;
  jobCategories: string;
  salary: salary;
  postedOn: string;
  jobDescription: string;
  requirement: string
}
