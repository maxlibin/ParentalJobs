// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");

function handleClick(_event) {
  console.log("clicked!");
  return /* () */0;
}

function App(Props) {
  var message = Props.message;
  return React.createElement("div", {
              onClick: handleClick
            }, message);
}

var make = App;

exports.handleClick = handleClick;
exports.make = make;
/* react Not a pure module */
