open Prelude;
module Css = Home_Css;

type state =
  | Loading
  | Loaded(Jobs_bs.latestJobs)
  | Error(Js.Promise.error);

[@react.component]
let make = () => {
  let (jobs, setJobs) = React.useState(() => Loading);

  React.useEffect0(() => {
    Js.Promise.(
      Api.Jobs.latest(
        Atdgen_codec_runtime.Decode.decode(Jobs_bs.read_latestJobs),
      )
      |> then_(res => setJobs(_ => Loaded(res))->resolve)
      |> catch(err => setJobs(_ => Error(err))->resolve)
    )
    ->ignore;
    None;
  });

  <>
    <div className=Css.container>
      <div className="container">
        <div className=Css.header>
          <h1 className=Css.title> "Parents friendly jobs"->s </h1>
          <h3 className=Css.subTitle>
            "Parental job is the largest parents friendly work community in the
          world. We aggregate jobs from everywhere so you don't have to search around everywhere."
            ->s
          </h3>
          <button className=Css.button> "Post a job for $79!"->s </button>
        </div>
      </div>
    </div>
    <div className={Cn.make(["container", Css.jobsList])}>
      {switch (jobs) {
       | Loading => "Loading..."->s
       | Error(err) => err->stringOfPromiseError->s
       | Loaded(jobs) =>
         <ul>
           {jobs
            ->List.map(
                (
                  {
                    _id as id,
                    company,
                    jobTitle,
                    employmentType,
                    jobCategories,
                  },
                ) =>
                <li
                  key=id
                  className=Css.job
                  onClick={event => {j|/job/$id|j}->linkTo(event)}>
                  <Avatar className=Css.avatar company />
                  <div>
                    <span className=Css.company> company->s </span>
                    <h3 className=Css.jobTitle> jobTitle->s </h3>
                    <cite className=Css.category>
                      <span> jobCategories->s </span>
                    </cite>
                  </div>
                  <div className=Css.employmentType>
                    <span> employmentType->s </span>
                  </div>
                </li>
              )
            ->RR.list}
         </ul>
       }}
    </div>
  </>;
};