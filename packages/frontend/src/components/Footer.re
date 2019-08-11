open Prelude;

module Css = Footer_Css;

[@react.component]
let make = () =>
  <>
    <footer className={Cn.make(["footer", Css.topFooter])}>
      <div className="container">
        <div className="row align-items-center flex-row-reverse">
          <div className="col-12 mt-3 mt-lg-0 text-left">
            <h2 className=Css.title> "ParentalJob"->s </h2>
            <button className=Css.button> "Post a job for $79!"->s </button>
          </div>
        </div>
      </div>
    </footer>
    <footer className="footer">
      <div className="container">
        <div className="row align-items-center flex-row-reverse">
          <div className="col-12 col-lg-auto mt-3 mt-lg-0 text-center">
            "Copyright 2019 ParentalJobs"->s
          </div>
        </div>
      </div>
    </footer>
  </>;