open Prelude;

[@react.component]
let make = (~id) =>
  <div className="container">
    <div className="page-header">
      <h1 className="page-title"> {("Job" ++ id)->s} </h1>
    </div>
  </div>;