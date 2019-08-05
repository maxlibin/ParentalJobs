open Prelude;

[@react.component]
let make = () => {
  let linkTo = (event, path) => {
    ReactEvent.Mouse.preventDefault(event);

    ReasonReactRouter.push(path);
  };
  <>
    <div className="header py-4">
      <div className="container">
        <div className="d-flex">
          <a
            className="header-brand"
            href="/"
            onClick={event => linkTo(event, "/")}>
            "ParentalJobs"->s
          </a>
        </div>
      </div>
    </div>
    <div className="header collapse d-lg-flex p-0" id="headerMenuCollapse">
      <div className="container">
        <div className="row align-items-center">
          <div className="col-lg order-lg-first">
            <ul className="nav nav-tabs border-0 flex-column flex-lg-row">
              <li className="nav-item">
                <a
                  href="/"
                  className="nav-link"
                  onClick={event => linkTo(event, "/Home")}>
                  <i className="fe fe-home" />
                  "Home"->s
                </a>
              </li>
              <li className="nav-item">
                <a
                  href="/jobs"
                  className="nav-link"
                  onClick={event => linkTo(event, "/jobs")}>
                  <i className="fe fe-box" />
                  "Jobs"->s
                </a>
              </li>
            </ul>
          </div>
        </div>
      </div>
    </div>
  </>;
};