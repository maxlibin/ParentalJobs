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
          <button className=Css.button onClick={"/job/new"->linkTo}>
            "Post a job for $179!"->s
          </button>
        </div>
      </div>
    </div>
    <div className={Cn.make(["container", Css.jobsList])}>
      {switch (jobs) {
       | Loading => "Loading..."->s
       | Error(err) => err->stringOfPromiseError->s
       | Loaded(jobs) =>
         <>
           <h4 className=Css.title> "Latest jobs"->s </h4>
           <JobsList jobs />
         </>
       }}
    </div>
  </>;
};