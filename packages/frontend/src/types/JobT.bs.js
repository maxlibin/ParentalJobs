// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Block from "bs-platform/lib/es6/block.js";
import * as Formality__Form from "re-formality/src/Formality__Form.bs.js";

function update(state, value) {
  return /* record */[
          /* title */value,
          /* category */state[/* category */1],
          /* type_ */state[/* type_ */2],
          /* apply */state[/* apply */3],
          /* description */state[/* description */4],
          /* email */state[/* email */5],
          /* name */state[/* name */6],
          /* statement */state[/* statement */7],
          /* website */state[/* website */8],
          /* more */state[/* more */9],
          /* address */state[/* address */10]
        ];
}

function validator_003(param) {
  if (param[/* title */0] === "") {
    return /* Error */Block.__(1, ["Please add a job title"]);
  } else {
    return /* Ok */Block.__(0, [/* Valid */0]);
  }
}

var validator = /* record */[
  /* field : Title */0,
  /* strategy : OnSubmit */4,
  /* dependents */undefined,
  validator_003
];

var Title_F = /* module */[
  /* update */update,
  /* validator */validator
];

function update$1(state, value) {
  return /* record */[
          /* title */state[/* title */0],
          /* category */value,
          /* type_ */state[/* type_ */2],
          /* apply */state[/* apply */3],
          /* description */state[/* description */4],
          /* email */state[/* email */5],
          /* name */state[/* name */6],
          /* statement */state[/* statement */7],
          /* website */state[/* website */8],
          /* more */state[/* more */9],
          /* address */state[/* address */10]
        ];
}

function validator_003$1(param) {
  if (param[/* category */1] === "") {
    return /* Error */Block.__(1, ["Please choose a category"]);
  } else {
    return /* Ok */Block.__(0, [/* Valid */0]);
  }
}

var validator$1 = /* record */[
  /* field : Category */1,
  /* strategy : OnSubmit */4,
  /* dependents */undefined,
  validator_003$1
];

var Category_F = /* module */[
  /* update */update$1,
  /* validator */validator$1
];

function update$2(state, value) {
  return /* record */[
          /* title */state[/* title */0],
          /* category */state[/* category */1],
          /* type_ */state[/* type_ */2],
          /* apply */value,
          /* description */state[/* description */4],
          /* email */state[/* email */5],
          /* name */state[/* name */6],
          /* statement */state[/* statement */7],
          /* website */state[/* website */8],
          /* more */state[/* more */9],
          /* address */state[/* address */10]
        ];
}

function validator_003$2(param) {
  if (param[/* apply */3] === "") {
    return /* Error */Block.__(1, ["Please enter your apply url or email address"]);
  } else {
    return /* Ok */Block.__(0, [/* Valid */0]);
  }
}

var validator$2 = /* record */[
  /* field : Apply */3,
  /* strategy : OnSubmit */4,
  /* dependents */undefined,
  validator_003$2
];

var Apply_F = /* module */[
  /* update */update$2,
  /* validator */validator$2
];

function update$3(state, value) {
  return /* record */[
          /* title */state[/* title */0],
          /* category */state[/* category */1],
          /* type_ */state[/* type_ */2],
          /* apply */state[/* apply */3],
          /* description */value,
          /* email */state[/* email */5],
          /* name */state[/* name */6],
          /* statement */state[/* statement */7],
          /* website */state[/* website */8],
          /* more */state[/* more */9],
          /* address */state[/* address */10]
        ];
}

function validator_003$3(param) {
  if (param[/* description */4] === "") {
    return /* Error */Block.__(1, ["Please enter some descriptions"]);
  } else {
    return /* Ok */Block.__(0, [/* Valid */0]);
  }
}

var validator$3 = /* record */[
  /* field : Description */5,
  /* strategy : OnSubmit */4,
  /* dependents */undefined,
  validator_003$3
];

var Description_F = /* module */[
  /* update */update$3,
  /* validator */validator$3
];

function update$4(state, value) {
  return /* record */[
          /* title */state[/* title */0],
          /* category */state[/* category */1],
          /* type_ */state[/* type_ */2],
          /* apply */state[/* apply */3],
          /* description */state[/* description */4],
          /* email */value,
          /* name */state[/* name */6],
          /* statement */state[/* statement */7],
          /* website */state[/* website */8],
          /* more */state[/* more */9],
          /* address */state[/* address */10]
        ];
}

function validator_003$4(param) {
  if (param[/* email */5] === "") {
    return /* Error */Block.__(1, ["Please enter company's email"]);
  } else {
    return /* Ok */Block.__(0, [/* Valid */0]);
  }
}

var validator$4 = /* record */[
  /* field : Email */6,
  /* strategy : OnSubmit */4,
  /* dependents */undefined,
  validator_003$4
];

var Email_F = /* module */[
  /* update */update$4,
  /* validator */validator$4
];

function update$5(state, value) {
  return /* record */[
          /* title */state[/* title */0],
          /* category */state[/* category */1],
          /* type_ */state[/* type_ */2],
          /* apply */state[/* apply */3],
          /* description */state[/* description */4],
          /* email */state[/* email */5],
          /* name */value,
          /* statement */state[/* statement */7],
          /* website */state[/* website */8],
          /* more */state[/* more */9],
          /* address */state[/* address */10]
        ];
}

function validator_003$5(param) {
  if (param[/* name */6] === "") {
    return /* Error */Block.__(1, ["Please enter company's name"]);
  } else {
    return /* Ok */Block.__(0, [/* Valid */0]);
  }
}

var validator$5 = /* record */[
  /* field : Name */7,
  /* strategy : OnSubmit */4,
  /* dependents */undefined,
  validator_003$5
];

var Name_F = /* module */[
  /* update */update$5,
  /* validator */validator$5
];

function update$6(state, value) {
  return /* record */[
          /* title */state[/* title */0],
          /* category */state[/* category */1],
          /* type_ */state[/* type_ */2],
          /* apply */state[/* apply */3],
          /* description */state[/* description */4],
          /* email */state[/* email */5],
          /* name */state[/* name */6],
          /* statement */state[/* statement */7],
          /* website */state[/* website */8],
          /* more */state[/* more */9],
          /* address */value
        ];
}

function validator_003$6(param) {
  if (param[/* address */10] === "") {
    return /* Error */Block.__(1, ["Please enter company's address"]);
  } else {
    return /* Ok */Block.__(0, [/* Valid */0]);
  }
}

var validator$6 = /* record */[
  /* field : Address */11,
  /* strategy : OnSubmit */4,
  /* dependents */undefined,
  validator_003$6
];

var Address_F = /* module */[
  /* update */update$6,
  /* validator */validator$6
];

function update$7(state, value) {
  return /* record */[
          /* title */state[/* title */0],
          /* category */state[/* category */1],
          /* type_ */state[/* type_ */2],
          /* apply */state[/* apply */3],
          /* description */state[/* description */4],
          /* email */state[/* email */5],
          /* name */state[/* name */6],
          /* statement */value,
          /* website */state[/* website */8],
          /* more */state[/* more */9],
          /* address */state[/* address */10]
        ];
}

function validator_003$7(param) {
  if (param[/* statement */7] === "") {
    return /* Error */Block.__(1, ["Please enter company's statement"]);
  } else {
    return /* Ok */Block.__(0, [/* Valid */0]);
  }
}

var validator$7 = /* record */[
  /* field : Statement */8,
  /* strategy : OnSubmit */4,
  /* dependents */undefined,
  validator_003$7
];

var Statement_F = /* module */[
  /* update */update$7,
  /* validator */validator$7
];

function update$8(state, value) {
  return /* record */[
          /* title */state[/* title */0],
          /* category */state[/* category */1],
          /* type_ */state[/* type_ */2],
          /* apply */state[/* apply */3],
          /* description */state[/* description */4],
          /* email */state[/* email */5],
          /* name */state[/* name */6],
          /* statement */state[/* statement */7],
          /* website */value,
          /* more */state[/* more */9],
          /* address */state[/* address */10]
        ];
}

function validator_003$8(param) {
  if (param[/* website */8] === "") {
    return /* Error */Block.__(1, ["Please enter your company's website"]);
  } else {
    return /* Ok */Block.__(0, [/* Valid */0]);
  }
}

var validator$8 = /* record */[
  /* field : Website */9,
  /* strategy : OnSubmit */4,
  /* dependents */undefined,
  validator_003$8
];

var Website_F = /* module */[
  /* update */update$8,
  /* validator */validator$8
];

function update$9(state, value) {
  return /* record */[
          /* title */state[/* title */0],
          /* category */state[/* category */1],
          /* type_ */state[/* type_ */2],
          /* apply */state[/* apply */3],
          /* description */state[/* description */4],
          /* email */state[/* email */5],
          /* name */state[/* name */6],
          /* statement */state[/* statement */7],
          /* website */state[/* website */8],
          /* more */value,
          /* address */state[/* address */10]
        ];
}

function validator_003$9(param) {
  if (param[/* more */9] === "") {
    return /* Error */Block.__(1, ["Please tell us more about your company"]);
  } else {
    return /* Ok */Block.__(0, [/* Valid */0]);
  }
}

var validator$9 = /* record */[
  /* field : More */10,
  /* strategy : OnSubmit */4,
  /* dependents */undefined,
  validator_003$9
];

var More_F = /* module */[
  /* update */update$9,
  /* validator */validator$9
];

var validators_001 = /* :: */[
  validator,
  /* :: */[
    validator$2,
    /* :: */[
      validator$3,
      /* :: */[
        validator$4,
        /* :: */[
          validator$5,
          /* :: */[
            validator$6,
            /* :: */[
              validator$7,
              /* :: */[
                validator$8,
                /* :: */[
                  validator$9,
                  /* [] */0
                ]
              ]
            ]
          ]
        ]
      ]
    ]
  ]
];

var validators = /* :: */[
  validator$1,
  validators_001
];

var Form = /* module */[
  /* Title_F */Title_F,
  /* Category_F */Category_F,
  /* Apply_F */Apply_F,
  /* Description_F */Description_F,
  /* Email_F */Email_F,
  /* Name_F */Name_F,
  /* Address_F */Address_F,
  /* Statement_F */Statement_F,
  /* Website_F */Website_F,
  /* More_F */More_F,
  /* validators */validators
];

var FormHook = Formality__Form.Make([validators]);

export {
  Form ,
  FormHook ,
  
}
/* FormHook Not a pure module */
