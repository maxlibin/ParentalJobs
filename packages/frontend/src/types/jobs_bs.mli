(* Auto-generated from "jobs.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type salary = Jobs_t.salary = {
  salaryFrom: string;
  salaryTo: string;
  salaryType: string option
}

type job = Jobs_t.job = {
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

type jobs = Jobs_t.jobs

val read_salary :  salary Atdgen_codec_runtime.Decode.t

val write_salary :  salary Atdgen_codec_runtime.Encode.t

val read_job :  job Atdgen_codec_runtime.Decode.t

val write_job :  job Atdgen_codec_runtime.Encode.t

val read_jobs :  jobs Atdgen_codec_runtime.Decode.t

val write_jobs :  jobs Atdgen_codec_runtime.Encode.t

