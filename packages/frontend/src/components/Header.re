open Prelude;

[@react.component]
let make = () => {
  <>
    <div className="header py-4">
      <div className="container">
        <div className="d-flex">
          <a
            className="header-brand"
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
                  className="nav-link">
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