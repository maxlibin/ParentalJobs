module RR = {
  include ReasonReact;

  let list = item => item->List.toArray->ReasonReact.array;
};

let s = RR.string;

[@bs.send]
external stringOfPromiseError: Js.Promise.error => string = "toString";

module Router = {
  type t =
    | Home
    | Jobs
    | Job(string)
    | NotFound;

  let parseUrl = (url: ReasonReactRouter.url) =>
    switch (url.path) {
    | [] => Home
    | ["job", id] => Job(id)
    | ["jobs"] => Jobs
    | _ => NotFound
    };

  let unwrap =
    fun
    | Jobs => "jobs"
    | Job(_) => "job"
    | Home => "home"
    | _ => "NotFound";
};

let linkTo = (path, event) => {
  event->ReactEvent.Mouse.preventDefault;
  path->ReasonReactRouter.push;
};