// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_List = require("bs-platform/lib/js/belt_List.js");
var Api$Snapee = require("../helpers/Api.bs.js");
var Prelude$Snapee = require("../helpers/Prelude.bs.js");
var Users_bs$Snapee = require("../dataTypes/users_bs.bs.js");
var Atdgen_codec_runtime = require("@ahrefs/bs-atdgen-codec-runtime/src/atdgen_codec_runtime.bs.js");

function Analytics(Props) {
  var match = React.useState((function () {
          return /* Loading */0;
        }));
  var setUsers = match[1];
  var users = match[0];
  React.useEffect((function () {
          var partial_arg = Atdgen_codec_runtime.Decode[/* decode */1];
          Api$Snapee.Fetch[/* get */0]("/api/users", (function (param) {
                    return partial_arg(Users_bs$Snapee.read_users, param);
                  })).then((function (users) {
                  return Promise.resolve(Curry._1(setUsers, (function (param) {
                                    return /* Loaded */[users];
                                  })));
                }));
          return undefined;
        }), ([]));
  return React.createElement("div", {
              className: "container"
            }, React.createElement("div", {
                  className: "page-header"
                }, React.createElement("h1", {
                      className: "page-title"
                    }, Prelude$Snapee.s("Analytics"))), React.createElement("div", {
                  className: "row row-cards row-deck"
                }, React.createElement("div", {
                      className: "col-12"
                    }, React.createElement("div", {
                          className: "card"
                        }, React.createElement("div", {
                              className: "table-responsive"
                            }, React.createElement("table", {
                                  className: "table table-hover table-outline table-vcenter text-nowrap card-table"
                                }, React.createElement("thead", undefined, React.createElement("tr", undefined, React.createElement("th", {
                                              className: "text-center w-1"
                                            }, React.createElement("i", {
                                                  className: "icon-people"
                                                })), React.createElement("th", undefined, Prelude$Snapee.s("User")), React.createElement("th", undefined, Prelude$Snapee.s("Usage")))), React.createElement("tbody", undefined, users ? Prelude$Snapee.RR[/* list */9](Belt_List.mapWithIndex(users[0], (function (index, user) {
                                                  return React.createElement("tr", {
                                                              key: String(index)
                                                            }, React.createElement("td", {
                                                                  className: "text-center"
                                                                }, React.createElement("div", {
                                                                      className: "avatar d-block"
                                                                    }, React.createElement("span", {
                                                                          className: "avatar-status bg-green"
                                                                        }))), React.createElement("td", undefined, React.createElement("div", undefined, Prelude$Snapee.s(user[/* fullname */0])), React.createElement("div", {
                                                                      className: "small text-muted"
                                                                    }, Prelude$Snapee.s("Created date: " + user[/* createdate */1].toString()))), React.createElement("td", undefined, React.createElement("div", {
                                                                      className: "clearfix"
                                                                    }, React.createElement("div", {
                                                                          className: "float-left"
                                                                        }, React.createElement("strong", undefined, Prelude$Snapee.s("42%"))), React.createElement("div", {
                                                                          className: "float-right"
                                                                        }, React.createElement("small", {
                                                                              className: "text-muted"
                                                                            }, Prelude$Snapee.s("Jun 11, 2019 - Jul 10, 2019")))), React.createElement("div", {
                                                                      className: "progress progress-xs"
                                                                    }, React.createElement("div", {
                                                                          className: "progress-bar bg-yellow",
                                                                          role: "progressbar"
                                                                        }))));
                                                }))) : null)))))));
}

var make = Analytics;

exports.make = make;
/* react Not a pure module */
