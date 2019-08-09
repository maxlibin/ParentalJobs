module Fetch = {
  let get = (url, decode) => {
    Js.Promise.(
      Fetch.fetchWithInit(url, Fetch.RequestInit.make(~method_=Get, ()))
      |> then_(Fetch.Response.json)
      |> then_(json => json |> decode |> resolve)
    );
  };
};

module Jobs = {
  let latest = decode => Fetch.get("/api/jobs/latest", decode);
};