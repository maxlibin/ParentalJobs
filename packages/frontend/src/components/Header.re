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
  </>;
};