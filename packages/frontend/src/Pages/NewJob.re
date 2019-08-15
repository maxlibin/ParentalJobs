open Prelude;

module Css = Jobs_Css;

module LoginForm = {
  open Formality;

  type field =
    | Email
    | Password;

  type state = {
    email: string,
    password: string,
  };

  type message = string;
  type submissionError = unit;

  module EmailField = {
    let update = (state, value) => {...state, email: value};

    let validator = {
      field: Email,
      strategy: Strategy.OnFirstSuccessOrFirstBlur,
      dependents: None,
      validate: ({email}) =>
        switch (email) {
        | "" => Error("Uh oh error")
        | _ => Ok(Valid)
        },
    };
  };

  module PasswordField = {
    let update = (state, value) => {...state, password: value};

    let validator = {
      field: Password,
      strategy: Strategy.OnFirstBlur,
      dependents: None,
      validate: ({password}) =>
        switch (password) {
        | "" => Error("Uh oh error")
        | _ => Ok(Valid)
        },
    };
  };

  let validators = [EmailField.validator, PasswordField.validator];
};

module LoginFormHook = Formality.Make(LoginForm);

[@react.component]
let make = () => {
  let form =
    LoginFormHook.useForm(
      ~initialState=LoginForm.{email: "", password: ""},
      ~onSubmit=(state, form) => {
        Js.log2("Submitted with:", state);
        Js.Global.setTimeout(
          () => {
            form.notifyOnSuccess(None);
            form.reset->Js.Global.setTimeout(3000)->ignore;
          },
          500,
        )
        ->ignore;
      },
    );

  <div className="container">
    <div className="page-header">
      <div className={Cn.make(["container", Css.jobsList])}>
        <h1 className="page-title"> "Find a Jobs"->s </h1>
        <form onSubmit={form.submit->Formality.Dom.preventDefault}>
          <input
            value={form.state.email}
            disabled={form.submitting}
            onBlur={_ => form.blur(Email)}
            onChange={event =>
              form.change(
                Email,
                LoginForm.EmailField.update(
                  form.state,
                  event->ReactEvent.Form.target##value,
                ),
              )
            }
          />
          {switch (form.result(Email)) {
           | Some(Error(message)) =>
             <div className={Cn.make(["form-message", "failure"])}>
               message->React.string
             </div>
           | Some(Ok(Valid | NoValue))
           | None => React.null
           }}
          <input
            value={form.state.password}
            disabled={form.submitting}
            onBlur={_ => form.blur(Password)}
            onChange={event =>
              form.change(
                Password,
                LoginForm.PasswordField.update(
                  form.state,
                  event->ReactEvent.Form.target##value,
                ),
              )
            }
          />
          {switch (form.result(Password)) {
           | Some(Error(message)) =>
             <div className={Cn.make(["form-message", "failure"])}>
               message->React.string
             </div>
           | Some(Ok(Valid | NoValue))
           | None => React.null
           }}
          <button disabled={form.submitting}>
            (form.submitting ? "Submitting..." : "Submit")->React.string
          </button>
        </form>
      </div>
    </div>
  </div>;
};