open Prelude;
open JobT;

module Css = Jobs_Css;

[@react.component]
let make = () => {
  let form =
    FormHook.useForm(
      ~initialState=
        Form.{
          category: "",
          title: "",
          type_: "fullTime",
          apply: "",
          description: "",
          email: "",
          name: "",
          address: "",
          statement: "",
          website: "",
          more: "",
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
        <form
          className="mt-8"
          onSubmit={form.submit->Formality.Dom.preventDefault}>
          <h4> "First, tell us about the position"->s </h4>
          <div className="row mt-4">
            <div className="form-group col-md-6">
              <label> <strong> "Job title"->s </strong> </label>
              <input
                className="form-control form-control-lg"
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
            <div className="form-group col-md-6">
              <label> <strong> "Category"->s </strong> </label>
              <input
                className="form-control form-control-lg"
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
          </div>
          <div className="row mt-4">
            <div className="form-group col-md-6">
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
            <div className="form-group col-md-6">
              <label> <strong> "Apply url"->s </strong> </label>
              <input
                className="form-control form-control-lg"
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
          </div>
          <div className="row mt-4">
            <div className="form-group col-sm-12">
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
              <FormErrorMsg type_={form.result(Description)} />
            </div>
          </div>
          <h4 className="mt-6"> "Tell us about the your company"->s </h4>
          <div className="row mt5">
            <div className="form-group col-md-6">
              <label> <strong> "Name"->s </strong> </label>
              <input
                className="form-control form-control-lg"
                value={form.state.name}
                disabled={form.submitting}
                onBlur={_ => form.blur(Name)}
                onChange={event =>
                  form.change(
                    Name,
                    Form.Name_F.update(
                      form.state,
                      event->ReactEvent.Form.target##value,
                    ),
                  )
                }
              />
              <FormErrorMsg type_={form.result(Name)} />
            </div>
            <div className="form-group col-md-6">
              <label> <strong> "Company statement"->s </strong> </label>
              <input
                className="form-control form-control-lg"
                value={form.state.statement}
                disabled={form.submitting}
                onBlur={_ => form.blur(Statement)}
                onChange={event =>
                  form.change(
                    Statement,
                    Form.Statement_F.update(
                      form.state,
                      event->ReactEvent.Form.target##value,
                    ),
                  )
                }
              />
              <FormErrorMsg type_={form.result(Statement)} />
            </div>
          </div>
          <div className="row mt-4">
            <div className="form-group col-md-6">
              <label> <strong> "Website"->s </strong> </label>
              <input
                className="form-control form-control-lg"
                value={form.state.website}
                disabled={form.submitting}
                onBlur={_ => form.blur(Website)}
                onChange={event =>
                  form.change(
                    Website,
                    Form.Website_F.update(
                      form.state,
                      event->ReactEvent.Form.target##value,
                    ),
                  )
                }
              />
              <FormErrorMsg type_={form.result(Website)} />
            </div>
            <div className="form-group col-md-6">
              <label> <strong> "Email"->s </strong> </label>
              <input
                className="form-control form-control-lg"
                value={form.state.email}
                disabled={form.submitting}
                onBlur={_ => form.blur(Email)}
                onChange={event =>
                  form.change(
                    Email,
                    Form.Email_F.update(
                      form.state,
                      event->ReactEvent.Form.target##value,
                    ),
                  )
                }
              />
              <FormErrorMsg type_={form.result(Email)} />
            </div>
          </div>
          <div className="mt-4 form-group">
            <label> <strong> "Address"->s </strong> </label>
            <input
              className="form-control form-control-lg"
              value={form.state.address}
              disabled={form.submitting}
              onBlur={_ => form.blur(Address)}
              onChange={event =>
                form.change(
                  Address,
                  Form.Address_F.update(
                    form.state,
                    event->ReactEvent.Form.target##value,
                  ),
                )
              }
            />
            <FormErrorMsg type_={form.result(Address)} />
          </div>
          <div className="mt-4 form-group">
            <label>
              <strong> "Tell us more about your company"->s </strong>
            </label>
            <textarea
              className="form-control"
              rows=5
              value={form.state.more}
              disabled={form.submitting}
              onBlur={_ => form.blur(More)}
              onChange={event =>
                form.change(
                  More,
                  Form.More_F.update(
                    form.state,
                    event->ReactEvent.Form.target##value,
                  ),
                )
              }
            />
            <FormErrorMsg type_={form.result(More)} />
          </div>
          <button className="btn btn-info btn-lg" disabled={form.submitting}>
            (form.submitting ? "Submitting..." : "Submit")->React.string
          </button>
        </form>
      </div>
    </div>
  </div>;
};