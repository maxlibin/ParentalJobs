module RR = {
  include ReasonReact;

  let list = item => item->List.toArray->ReasonReact.array;
};

let s = RR.string;

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