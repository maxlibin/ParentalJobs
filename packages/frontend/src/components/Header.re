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
          <div className="d-flex order-lg-2 ml-auto">
            <ul className="nav border-0 flex-column flex-lg-row">
              <li className="nav-item">
                <a
                  href="/jobs"
                  onClick={event => linkTo(event, "/jobs")}
                  className="nav-link">
                  "Find a job"->s
                </a>
              </li>

              <li className="nav-item">
                <a
                  href="/jobs/test"
                  onClick={event => linkTo(event, "/job/asd")}
                  className="nav-link">
                  "Find a job test"->s
                </a>
              </li>
            </ul>
          </div>
        </div>
      </div>
    </div>
  </>;
};