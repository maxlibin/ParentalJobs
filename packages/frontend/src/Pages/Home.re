open Prelude;

module Css = Home_Css;

[@react.component]
let make = () => {
  <div className={Cn.make(["container", Css.container])}>
    <div className=Css.header>
      <h1 className=Css.title> "Parental friendly jobs"->s </h1>
      <h3 className=Css.subTitle>
        "Parental job is the largest parents friendly work community in the world. We aggregate jobs from everywhere so you don't have to search around."
        ->s
      </h3>
      <button className=Css.button> "Post a job for free!"->s </button>
    </div>
  </div>;
};