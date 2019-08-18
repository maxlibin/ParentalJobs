open Prelude;
open Formality;

[@react.component]
let make = (~type_) => {
  switch (type_) {
  | Some(Result.Error(message)) =>
    <p className={Cn.make(["text-danger"])}> message->s </p>
  | Some(Ok(Valid | NoValue))
  | None => React.null
  };
};