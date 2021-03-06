open Prelude;

module Css = Job_Css;

type state =
  | Loading
  | Loaded(Jobs_bs.job)
  | Error(Js.Promise.error);

[@react.component]
let make = (~id) => {
  let (job, setJob) = React.useState(() => Loading);
  React.useEffect0(() => {
    Js.Promise.(
      id->Api.Jobs.job(Atdgen_codec_runtime.Decode.decode(Jobs_bs.read_job))
      |> then_(res => setJob(_ => Loaded(res))->resolve)
      |> catch(err => setJob(_ => Error(err))->resolve)
    )
    ->ignore;
    None;
  });

  <div className="container">
    <div className="row">
      {switch (job) {
       | Loading => "Loading..."->s
       | Error(err) => err->stringOfPromiseError->s
       | Loaded({
           company,
           jobTitle,
           address,
           employmentType,
           seniority,
           minExperience,
           jobCategories,
           //  salary,
           postedOn,
           jobDescription,
           requirement,
         }) =>
         <>
           <div className="col-md-8">
             <div className=Css.contentWrapper>
               <span className=Css.postDate> postedOn->s </span>
               <h1 className=Css.jobTitle> jobTitle->s </h1>
               <p className=Css.tags>
                 <span className=Css.tag> employmentType->s </span>
                 <span className=Css.tag> seniority->s </span>
                 {switch (minExperience) {
                  | _ when minExperience != "" =>
                    <span className=Css.tag> minExperience->s </span>
                  | _ => RR.null
                  }}
                 <span className=Css.tag> jobCategories->s </span>
               </p>
               <div
                 className=Css.content
                 dangerouslySetInnerHTML={"__html": jobDescription}
               />
               <div
                 className=Css.content
                 dangerouslySetInnerHTML={"__html": requirement}
               />
             </div>
             <ApplyBtn />
             <div className=Css.quality>
               <h4>
                 "Help us maintain the quality of jobs posted on We Work Remotely."
                 ->s
               </h4>
               <p> "Is this job parents friendly?"->s </p>
               <a className=Css.letusKnow href="mailTo:me@maxlibin.com">
                 "Let us know"->s
               </a>
             </div>
           </div>
           <div className="col-md-4"> <CompanyInfo address company /> </div>
         </>
       }}
    </div>
  </div>;
};