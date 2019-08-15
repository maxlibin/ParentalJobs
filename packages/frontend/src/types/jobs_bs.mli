(* Auto-generated from "jobs.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type salary = Jobs_t.salary = {
  salaryFrom: string;
  salaryTo: string;
  salaryType: string
}

type jobOverview = Jobs_t.jobOverview = {
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

type latestJobs = Jobs_t.latestJobs

type jobs = Jobs_t.jobs

type job = Jobs_t.job = {
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

val read_salary :  salary Atdgen_codec_runtime.Decode.t

val write_salary :  salary Atdgen_codec_runtime.Encode.t

val read_jobOverview :  jobOverview Atdgen_codec_runtime.Decode.t

val write_jobOverview :  jobOverview Atdgen_codec_runtime.Encode.t

val read_latestJobs :  latestJobs Atdgen_codec_runtime.Decode.t

val write_latestJobs :  latestJobs Atdgen_codec_runtime.Encode.t

val read_jobs :  jobs Atdgen_codec_runtime.Decode.t

val write_jobs :  jobs Atdgen_codec_runtime.Encode.t

val read_job :  job Atdgen_codec_runtime.Decode.t

val write_job :  job Atdgen_codec_runtime.Encode.t

