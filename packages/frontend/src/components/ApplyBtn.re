open Prelude;

module Css = ApplyBtn_Css;

[@react.component]
let make = (~className=?) => {
  <button className={Cn.make([Css.button, className->Cn.unpack])}>
    "Apply for this position"->s
  </button>;
};