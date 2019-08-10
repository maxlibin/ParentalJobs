open Prelude;
module Css = Home_Css;

type state =
  | Loading
  | Loaded(Jobs_bs.jobs);

[@react.component]
let make = () => {
  let (jobs, setJobs) = React.useState(() => Loading);

  React.useEffect0(() => {
    Js.Promise.(
      Api.Jobs.latest(Atdgen_codec_runtime.Decode.decode(Jobs_bs.read_jobs))
      |> then_(res => setJobs(_ => Loaded(res))->resolve)
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
          <button className=Css.button> "Post a job for free!"->s </button>
        </div>
      </div>
    </div>
    <div className={Cn.make(["container", Css.jobsList])}>
      {switch (jobs) {
       | Loading => "Loading..."->s
       | Loaded(jobs) =>
         <ul>
           {jobs
            ->List.mapWithIndex(
                (index, {company, jobTitle, employmentType, jobCategories}) =>
                <li key={index->string_of_int} className=Css.job>
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