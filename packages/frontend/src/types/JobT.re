module Form = {
  open Formality;

  type field =
    | Title
    | Category
    | Type
    | Apply
    | Url
    | Description
    | Email
    | Name
    | Statement
    | Website
    | More
    | Address;

  type state = {
    title: string,
    category: string,
    type_: string,
    apply: string,
    description: string,
    email: string,
    name: string,
    statement: string,
    website: string,
    more: string,
    address: string,
  };

  type message = string;
  type submissionError = unit;

  module Title_F = {
    let update = (state, value) => {...state, title: value};

    let validator = {
      field: Title,
      strategy: Strategy.OnSubmit,
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
      strategy: Strategy.OnSubmit,
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
      strategy: Strategy.OnSubmit,
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
      strategy: Strategy.OnSubmit,
      dependents: None,
      validate: ({description}) =>
        switch (description) {
        | "" => Error("Please enter some descriptions")
        | _ => Ok(Valid)
        },
    };
  };

  module Email_F = {
    let update = (state, value) => {...state, email: value};

    let validator = {
      field: Email,
      strategy: Strategy.OnSubmit,
      dependents: None,
      validate: ({email}) =>
        switch (email) {
        | "" => Error("Please enter company's email")
        | _ => Ok(Valid)
        },
    };
  };

  module Name_F = {
    let update = (state, value) => {...state, name: value};

    let validator = {
      field: Name,
      strategy: Strategy.OnSubmit,
      dependents: None,
      validate: ({name}) =>
        switch (name) {
        | "" => Error("Please enter company's name")
        | _ => Ok(Valid)
        },
    };
  };

  module Address_F = {
    let update = (state, value) => {...state, address: value};

    let validator = {
      field: Address,
      strategy: Strategy.OnSubmit,
      dependents: None,
      validate: ({address}) =>
        switch (address) {
        | "" => Error("Please enter company's address")
        | _ => Ok(Valid)
        },
    };
  };

  module Statement_F = {
    let update = (state, value) => {...state, statement: value};

    let validator = {
      field: Statement,
      strategy: Strategy.OnSubmit,
      dependents: None,
      validate: ({statement}) =>
        switch (statement) {
        | "" => Error("Please enter company's statement")
        | _ => Ok(Valid)
        },
    };
  };

  module Website_F = {
    let update = (state, value) => {...state, website: value};

    let validator = {
      field: Website,
      strategy: Strategy.OnSubmit,
      dependents: None,
      validate: ({website}) =>
        switch (website) {
        | "" => Error("Please enter your company's website")
        | _ => Ok(Valid)
        },
    };
  };

  module More_F = {
    let update = (state, value) => {...state, more: value};

    let validator = {
      field: More,
      strategy: Strategy.OnSubmit,
      dependents: None,
      validate: ({more}) =>
        switch (more) {
        | "" => Error("Please tell us more about your company")
        | _ => Ok(Valid)
        },
    };
  };

  let validators = [
    Category_F.validator,
    Title_F.validator,
    Apply_F.validator,
    Description_F.validator,
    Email_F.validator,
    Name_F.validator,
    Address_F.validator,
    Statement_F.validator,
    Website_F.validator,
    More_F.validator,
  ];
};

module FormHook = Formality.Make(Form);