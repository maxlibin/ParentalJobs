// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Prelude$Frontend from "../helpers/Prelude.bs.js";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.js";

function Header(Props) {
  var linkTo = function ($$event, path) {
    $$event.preventDefault();
    return ReasonReactRouter.push(path);
  };
  return React.createElement(React.Fragment, undefined, React.createElement("div", {
                  className: "header py-4"
                }, React.createElement("div", {
                      className: "container"
                    }, React.createElement("div", {
                          className: "d-flex"
                        }, React.createElement("a", {
                              className: "header-brand",
                              href: "/",
                              onClick: (function ($$event) {
                                  return linkTo($$event, "/");
                                })
                            }, Prelude$Frontend.s("ParentalJobs")), React.createElement("div", {
                              className: "d-flex order-lg-2 ml-auto"
                            }, React.createElement("ul", {
                                  className: "nav border-0 flex-column flex-lg-row"
                                }, React.createElement("li", {
                                      className: "nav-item"
                                    }, React.createElement("a", {
                                          className: "nav-link",
                                          href: "/jobs",
                                          onClick: (function ($$event) {
                                              return linkTo($$event, "/jobs");
                                            })
                                        }, Prelude$Frontend.s("Find a job"))), React.createElement("li", {
                                      className: "nav-item"
                                    }, React.createElement("a", {
                                          className: "nav-link",
                                          href: "/jobs/test",
                                          onClick: (function ($$event) {
                                              return linkTo($$event, "/job/asd");
                                            })
                                        }, Prelude$Frontend.s("Find a job test")))))))));
}

var make = Header;

export {
  make ,
  
}
/* react Not a pure module */
