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
  postedOn: string;
  parentsFriendly: bool
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

let write_salary = (
  Atdgen_codec_runtime.Encode.make (fun (t : salary) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"salaryFrom"
          t.salaryFrom
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"salaryTo"
          t.salaryTo
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"salaryType"
          t.salaryType
      ]
    )
  )
)
let read_salary = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          salaryFrom =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "salaryFrom"
            ) json;
          salaryTo =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "salaryTo"
            ) json;
          salaryType =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "salaryType"
            ) json;
      } : salary)
    )
  )
)
let write_jobOverview = (
  Atdgen_codec_runtime.Encode.make (fun (t : jobOverview) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"_id"
          t._id
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"company"
          t.company
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"jobTitle"
          t.jobTitle
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"employmentType"
          t.employmentType
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"seniority"
          t.seniority
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"minExperience"
          t.minExperience
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"jobCategories"
          t.jobCategories
        ;
          Atdgen_codec_runtime.Encode.field
            (
            write_salary
            )
          ~name:"salary"
          t.salary
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"postedOn"
          t.postedOn
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.bool
            )
          ~name:"parentsFriendly"
          t.parentsFriendly
      ]
    )
  )
)
let read_jobOverview = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          _id =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "_id"
            ) json;
          company =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "company"
            ) json;
          jobTitle =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "jobTitle"
            ) json;
          employmentType =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "employmentType"
            ) json;
          seniority =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "seniority"
            ) json;
          minExperience =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "minExperience"
            ) json;
          jobCategories =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "jobCategories"
            ) json;
          salary =
            Atdgen_codec_runtime.Decode.decode
            (
              read_salary
              |> Atdgen_codec_runtime.Decode.field "salary"
            ) json;
          postedOn =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "postedOn"
            ) json;
          parentsFriendly =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.bool
              |> Atdgen_codec_runtime.Decode.field "parentsFriendly"
            ) json;
      } : jobOverview)
    )
  )
)
let write__1 = (
  Atdgen_codec_runtime.Encode.list (
    write_jobOverview
  )
)
let read__1 = (
  Atdgen_codec_runtime.Decode.list (
    read_jobOverview
  )
)
let write_latestJobs = (
  write__1
)
let read_latestJobs = (
  read__1
)
let write_jobs = (
  write__1
)
let read_jobs = (
  read__1
)
let write_job = (
  Atdgen_codec_runtime.Encode.make (fun (t : job) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"_id"
          t._id
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"company"
          t.company
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"jobTitle"
          t.jobTitle
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"jobId"
          t.jobId
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"address"
          t.address
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"employmentType"
          t.employmentType
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"seniority"
          t.seniority
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"minExperience"
          t.minExperience
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"jobCategories"
          t.jobCategories
        ;
          Atdgen_codec_runtime.Encode.field
            (
            write_salary
            )
          ~name:"salary"
          t.salary
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"postedOn"
          t.postedOn
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"jobDescription"
          t.jobDescription
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"requirement"
          t.requirement
      ]
    )
  )
)
let read_job = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          _id =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "_id"
            ) json;
          company =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "company"
            ) json;
          jobTitle =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "jobTitle"
            ) json;
          jobId =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "jobId"
            ) json;
          address =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "address"
            ) json;
          employmentType =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "employmentType"
            ) json;
          seniority =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "seniority"
            ) json;
          minExperience =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "minExperience"
            ) json;
          jobCategories =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "jobCategories"
            ) json;
          salary =
            Atdgen_codec_runtime.Decode.decode
            (
              read_salary
              |> Atdgen_codec_runtime.Decode.field "salary"
            ) json;
          postedOn =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "postedOn"
            ) json;
          jobDescription =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "jobDescription"
            ) json;
          requirement =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "requirement"
            ) json;
      } : job)
    )
  )
)
