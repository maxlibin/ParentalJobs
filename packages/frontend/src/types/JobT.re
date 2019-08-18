module Form = {
  open Formality;

  type field =
    | Title
    | Category
    | Type
    | Apply
    | Address
    | Url
    | Email
    | Description;

  type state = {
    // email: string,
    title: string,
    category: string,
    type_: string,
    apply: string,
    description: string,
    // category: string,
  };

  type message = string;
  type submissionError = unit;

  module Title_F = {
    let update = (state, value) => {...state, title: value};

    let validator = {
      field: Title,
      strategy: Strategy.OnFirstBlur,
      dependents: None,
      validate: ({title}) =>
        switch (title) {
        | "" => Error("Please add a job title")
        | _ => Ok(Valid)
        },
    };
  };

  module Category_F = {
    let update = (state, value) => {...state, category: value};

    let validator = {
      field: Category,
      strategy: Strategy.OnFirstBlur,
      dependents: None,
      validate: ({category}) =>
        switch (category) {
        | "" => Error("Please choose a category")
        | _ => Ok(Valid)
        },
    };
  };

  module Apply_F = {
    let update = (state, value) => {...state, apply: value};

    let validator = {
      field: Apply,
      strategy: Strategy.OnFirstBlur,
      dependents: None,
      validate: ({apply}) =>
        switch (apply) {
        | "" => Error("Please enter your apply url or email address")
        | _ => Ok(Valid)
        },
    };
  };

  module Description_F = {
    let update = (state, value) => {...state, description: value};

    let validator = {
      field: Description,
      strategy: Strategy.OnFirstBlur,
      dependents: None,
      validate: ({description}) =>
        switch (description) {
        | "" => Error("Please enter some descriptions")
        | _ => Ok(Valid)
        },
    };
  };

  // module EmailField = {
  //   let update = (state, value) => {...state, email: value};

  //   let validator = {
  //     field: Email,
  //     strategy: Strategy.OnFirstSuccessOrFirstBlur,
  //     dependents: None,
  //     validate: ({email}) =>
  //       switch (email) {
  //       | "" => Error("Uh oh error")
  //       | _ => Ok(Valid)
  //       },
  //   };
  // };

  let validators = [
    // EmailField.validator,
    Category_F.validator,
    Title_F.validator,
    Apply_F.validator,
  ];
};

module FormHook = Formality.Make(Form);