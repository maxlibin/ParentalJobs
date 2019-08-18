open Prelude;
open JobT;

module Css = Jobs_Css;

[@react.component]
let make = () => {
  let form =
    FormHook.useForm(
      ~initialState=
        Form.{
          // email: "",
          category: "",
          title: "",
          type_: "fullTime",
          apply: "",
          description: "",
        },
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
        <h1 className="page-title text-center">
          <strong>
            "Posting a Jobs has been much easier with ParentalJobs"->s
          </strong>
        </h1>
        <p className="text-center">
          "For every job you posted, with pledge to be parents friendly, we contribute 5% to foundations to need help."
          ->s
        </p>
        <form
          className="mt-8"
          onSubmit={form.submit->Formality.Dom.preventDefault}>
          <h4> "First, tell us about the position"->s </h4>
          <div className="mt-5 form-group">
            <label> <strong> "Job title"->s </strong> </label>
            <input
              className="form-control"
              value={form.state.title}
              disabled={form.submitting}
              onBlur={_ => form.blur(Title)}
              onChange={event =>
                form.change(
                  Title,
                  Form.Title_F.update(
                    form.state,
                    event->ReactEvent.Form.target##value,
                  ),
                )
              }
            />
            <FormErrorMsg type_={form.result(Title)} />
          </div>
          <div className="mt-5 form-group">
            <label> <strong> "Category"->s </strong> </label>
            <input
              className="form-control"
              value={form.state.category}
              disabled={form.submitting}
              onBlur={_ => form.blur(Category)}
              onChange={event =>
                form.change(
                  Category,
                  Form.Category_F.update(
                    form.state,
                    event->ReactEvent.Form.target##value,
                  ),
                )
              }
            />
            <FormErrorMsg type_={form.result(Category)} />
          </div>
          <div className="mt-5 form-group">
            <div className="form-label">
              <strong> "Job type"->s </strong>
            </div>
            <label
              className="custom-control custom-radio custom-control-inline">
              <input
                type_="radio"
                className="custom-control-input"
                value="fullTime"
                checked={form.state.type_ == "fullTime"}
                name="type"
                onChange={event =>
                  form.change(
                    Type,
                    Form.Category_F.update(
                      form.state,
                      event->ReactEvent.Form.target##value,
                    ),
                  )
                }
              />
              <span className="custom-control-label"> "Full time"->s </span>
            </label>
            <label
              className="custom-control custom-radio custom-control-inline">
              <input
                type_="radio"
                className="custom-control-input"
                value="Contact"
                checked={form.state.type_ == "contact"}
                name="type"
                onChange={event =>
                  form.change(
                    Type,
                    Form.Category_F.update(
                      form.state,
                      event->ReactEvent.Form.target##value,
                    ),
                  )
                }
              />
              <span className="custom-control-label"> "Contact"->s </span>
            </label>
          </div>
          <div className="mt-5 form-group">
            <label> <strong> "Apply url"->s </strong> </label>
            <input
              className="form-control"
              value={form.state.apply}
              disabled={form.submitting}
              onBlur={_ => form.blur(Apply)}
              onChange={event =>
                form.change(
                  Apply,
                  Form.Apply_F.update(
                    form.state,
                    event->ReactEvent.Form.target##value,
                  ),
                )
              }
            />
            <FormErrorMsg type_={form.result(Apply)} />
          </div>
          <div className="mt-5 form-group">
            <label> <strong> "Job description"->s </strong> </label>
            <textarea
              className="form-control"
              rows=5
              value={form.state.description}
              disabled={form.submitting}
              onBlur={_ => form.blur(Description)}
              onChange={event =>
                form.change(
                  Description,
                  Form.Description_F.update(
                    form.state,
                    event->ReactEvent.Form.target##value,
                  ),
                )
              }
            />
            <FormErrorMsg type_={form.result(Apply)} />
          </div>
          <button className="btn btn-primary" disabled={form.submitting}>
            (form.submitting ? "Submitting..." : "Submit")->React.string
          </button>
        </form>
      </div>
    </div>
  </div>;
};