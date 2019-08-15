open Prelude;

module Css = Jobs_Css;

type state =
  | Loading
  | Loaded(Jobs_bs.latestJobs)
  | Error(Js.Promise.error);

[@react.component]
let make = () => {
  let (jobs, setJobs) = React.useState(() => Loading);
  React.useEffect0(() => {
    Js.Promise.(
      Api.Jobs.jobs(
        Atdgen_codec_runtime.Decode.decode(Jobs_bs.read_latestJobs),
      )
      |> then_(res => setJobs(_ => Loaded(res))->resolve)
      |> catch(err => setJobs(_ => Error(err))->resolve)
    )
    ->ignore;
    None;
  });

  <div className="container">
    <div className="page-header">
      <div className={Cn.make(["container", Css.jobsList])}>
        <h1 className="page-title"> "Find a Jobs"->s </h1>
        {switch (jobs) {
         | Loading => "Loading..."->s
         | Error(err) => err->stringOfPromiseError->s
         | Loaded(jobs) =>
           <>
             //  <h4 className=Css.title> "Latest jobs"->s </h4>
             <JobsList jobs />
           </>
         }}
      </div>
    </div>
  </div>;
};