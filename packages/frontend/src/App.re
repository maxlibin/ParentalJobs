open Prelude;

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let (route, setRoute) = React.useState(() => Router.Home);

  React.useEffect1(
    () => {
      setRoute(_ => url.path->Router.wrap);
      None;
    },
    [|url.path|],
  );

  <div className="page">
    <div className="flex-fill">
      <Header />
      <div className="my-3 my-md-5">
        {switch (route) {
         | Jobs => <Jobs />
         | _ => <Home />
         }}
      </div>
    </div>
    <Footer />
  </div>;
};