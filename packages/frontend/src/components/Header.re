open Prelude;

module Css = Header_Css;

[@react.component]
let make = () => {
  <>
    <div className="header py-4">
      <div className="container">
        <div className="d-flex">
          <a
            className={Cn.make(["header-brand", Css.brand])}
            href="/"
            onClick={event => "/"->linkTo(event)}>
            "ParentalJobs"->s
          </a>
          <div className="d-flex order-lg-2 ml-auto">
            <ul className="nav border-0 flex-column flex-lg-row">
              <li className="nav-item">
                <a
                  href="/jobs"
                  onClick={event => "/jobs"->linkTo(event)}
                  className={Cn.make(["nav-link", Css.navLink])}>
                  "Find a job"->s
                </a>
              </li>
            </ul>
          </div>
        </div>
      </div>
    </div>
  </>;
};