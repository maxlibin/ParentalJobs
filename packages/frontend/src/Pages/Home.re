open Prelude;

module Css = Home_Css;

[@react.component]
let make = () => {
  React.useEffect0(() => {
    Api.Jobs.latest(Js.log)->ignore;
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
      <ul> <li className=Css.job> ""->s </li> </ul>
    </div>
  </>;
};