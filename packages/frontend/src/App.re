open Prelude;

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let route = Router.parseUrl(url);

  <div className="page">
    <div className="flex-fill">
      <Header />
      <div className="my-3 my-md-5">
        {switch (route) {
         | Home => <Home />
         | Jobs => <Jobs />
         | Job(id) => <Job id />
         | NotFound => <NotFound />
         }}
      </div>
    </div>
    <Footer />
  </div>;
};