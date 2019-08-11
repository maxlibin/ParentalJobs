open Prelude;

module Css = CompanyInfo_Css;

[@react.component]
let make = (~className=?, ~address, ~company, ~logo=?) => {
  <div className={Cn.make([Css.info, className->Cn.unpack])}>
    <Avatar className=Css.avatar ?logo company />
    <h3 className=Css.company> company->s </h3>
    {switch (address) {
     | _ when address != "" => <p className=Css.address> address->s </p>
     | _ => RR.null
     }}
    <ApplyBtn className=Css.button />
  </div>;
};