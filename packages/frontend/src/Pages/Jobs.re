open Prelude;

module Css = Jobs_Css;

let limit = 20;
let jobsQuery = (skip, limit) => {j|?skip=$(skip)&limit=$(limit)|j};

type jobs =
  | Loading
  | Loaded(Jobs_bs.latestJobs)
  | Error(Js.Promise.error);

type state = {
  jobs,
  currentPage: int,
};

type action =
  | SetCurrentPage(int)
  | SetJobs(jobs);

let initialState = {jobs: Loading, currentPage: 1};

let reducer = (state, action) => {
  switch (action) {
  | SetCurrentPage(currentPage) => {...state, currentPage}
  | SetJobs(jobs) => {...state, jobs}
  };
};

[@react.component]
let make = () => {
  let ({jobs, currentPage}, dispatch) =
    React.useReducer(reducer, initialState);
  Js.log(
    "/api/jobs"
    ++ jobsQuery(currentPage == 1 ? 0 : currentPage * limit, limit),
  );
  React.useEffect1(
    () => {
      Js.Promise.(
        Api.Jobs.jobs(
          "/api/jobs"
          ++ jobsQuery(currentPage == 1 ? 0 : currentPage * limit, limit),
        )
        |> then_(res => dispatch @@ SetJobs(Loaded(res)) |> resolve)
        |> catch(err => dispatch @@ SetJobs(Error(err)) |> resolve)
      )
      ->ignore;
      None;
    },
    [|currentPage|],
  );

  <div className="container">
    <div className="page-header">
      <div className={Cn.make(["container", Css.jobsList])}>
        <h1 className="page-title"> "Find a Jobs"->s </h1>
        {switch (jobs) {
         | Loading => "Loading..."->s
         | Error(err) => err->stringOfPromiseError->s
         | Loaded(jobs) =>
           <>
             <JobsList jobs />
             /* TODO: temp add a pagination */
             <div className="dataTables_wrapper no-footer">
               <div className="dataTables_paginate paging_simple_numbers">
                 <span>
                   {currentPage < 3
                      ? {
                        <>
                          {[1, 2, 3, 4]
                           ->List.map(item =>
                               <a
                                 key={item->string_of_int}
                                 onClick={_ =>
                                   dispatch @@ SetCurrentPage(item)
                                 }
                                 className={Cn.make([
                                   "paginate_button",
                                   "current"->Cn.ifTrue(currentPage == item),
                                 ])}>
                                 {item->string_of_int->s}
                               </a>
                             )
                           ->RR.list}
                        </>;
                      }
                      : <>
                          <a
                            onClick={_ =>
                              dispatch @@ SetCurrentPage(currentPage - 2)
                            }
                            className={Cn.make([
                              "paginate_button",
                              "current"->Cn.ifTrue(currentPage == 1),
                            ])}>
                            {(currentPage - 2)->string_of_int->s}
                          </a>
                          <a
                            onClick={_ =>
                              dispatch @@ SetCurrentPage(currentPage - 1)
                            }
                            className={Cn.make(["paginate_button"])}>
                            {(currentPage - 1)->string_of_int->s}
                          </a>
                          <a
                            onClick={_ =>
                              dispatch @@ SetCurrentPage(currentPage)
                            }
                            className={Cn.make([
                              "paginate_button",
                              "current",
                            ])}>
                            {currentPage->string_of_int->s}
                          </a>
                          <a
                            onClick={_ =>
                              dispatch @@ SetCurrentPage(currentPage + 1)
                            }
                            className={Cn.make(["paginate_button"])}>
                            {(currentPage + 1)->string_of_int->s}
                          </a>
                        </>}
                 </span>
               </div>
             </div>
           </>
         }}
      </div>
    </div>
  </div>;
};