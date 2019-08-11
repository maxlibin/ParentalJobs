open Prelude;

module Css = NotFound_Css;

[@react.component]
let make = () => {
  <div className={Cn.make(["container", Css.container])}>
    <h1> "Page not found"->s </h1>
    <p> "The page you requested was not found."->s </p>
  </div>;
};