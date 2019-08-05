module RR = {
  include ReasonReact;

  let list = item => item->List.toArray->ReasonReact.array;
};

let s = RR.string;

module Router = {
  type t =
    | Home
    | Jobs;

  let wrap = urlPath => {
    switch (urlPath) {
    | ["jobs", ...rest] => Jobs
    | _ => Home
    };
  };
};