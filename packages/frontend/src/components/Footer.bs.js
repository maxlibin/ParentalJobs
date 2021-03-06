// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Cn from "re-classnames/src/Cn.bs.js";
import * as React from "react";
import * as Prelude$Frontend from "../helpers/Prelude.bs.js";
import * as Footer_Css$Frontend from "./Footer_Css.bs.js";

function Footer(Props) {
  return React.createElement(React.Fragment, undefined, React.createElement("footer", {
                  className: Cn.make(/* :: */[
                        "footer",
                        /* :: */[
                          Footer_Css$Frontend.topFooter,
                          /* [] */0
                        ]
                      ])
                }, React.createElement("div", {
                      className: "container"
                    }, React.createElement("div", {
                          className: "row align-items-center flex-row-reverse"
                        }, React.createElement("div", {
                              className: "col-12 mt-3 mt-lg-0 text-left"
                            }, React.createElement("h2", {
                                  className: Footer_Css$Frontend.title
                                }, Prelude$Frontend.s("ParentalJob")), React.createElement("button", {
                                  className: Footer_Css$Frontend.button
                                }, Prelude$Frontend.s("Post a job for $79!")))))), React.createElement("footer", {
                  className: "footer"
                }, React.createElement("div", {
                      className: "container"
                    }, React.createElement("div", {
                          className: "row align-items-center flex-row-reverse"
                        }, React.createElement("div", {
                              className: "col-12 col-lg-auto mt-3 mt-lg-0 text-center"
                            }, Prelude$Frontend.s("Copyright 2019 ParentalJobs"))))));
}

var Css = 0;

var make = Footer;

export {
  Css ,
  make ,
  
}
/* react Not a pure module */
