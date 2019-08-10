open Prelude;

module Css = Avatar_Css;

let randomBgColor = () => {
  let colors = [
    "#f74b4b",
    "#1988ff",
    "#f7bc4b",
    "#e64bf7",
    "#29d400",
    "#d47700",
    "#ce5baf",
    "#5bce8f",
    "#5a4ba7",
    "#d26666",
  ];

  colors
  ->List.get(Js.Math.random_int(0, colors->List.length) - 1)
  ->Option.getWithDefault("#f74b4b");
};

[@react.component]
let make = (~className=?, ~company, ~logo=?) => {
  <span
    className={Cn.make([Css.avatar, className->Cn.unpack])}
    style={ReactDOMRe.Style.make(~backgroundColor=randomBgColor(), ())}>
    {switch (logo) {
     | None =>
       <span className=Css.name>
         {(company->String.get(0) |> String.make(1))->s}
       </span>
     | Some(src) => <img src alt=company />
     }}
  </span>;
};