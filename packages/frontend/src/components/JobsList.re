open Prelude;

module Css = JobsList_Css;

[@react.component]
let make = (~jobs: Jobs_bs.latestJobs) => {
  <ul className=Css.jobsListWrapper>
    {jobs
     ->List.map(
         (
           {
             _id as id,
             company,
             jobTitle,
             employmentType,
             jobCategories,
             parentsFriendly,
           },
         ) =>
         <li
           key=id
           className={Cn.make([
             Css.job,
             Css.parentFriendlyjob->Cn.ifTrue(parentsFriendly),
           ])}
           onClick={event => {j|/job/$id|j}->linkTo(event)}>
           <Avatar className=Css.avatar company />
           <div>
             <span className=Css.company> company->s </span>
             <h3 className=Css.jobTitle> jobTitle->s </h3>
             <cite className=Css.category>
               <span> jobCategories->s </span>
             </cite>
           </div>
           <div className=Css.employmentType>
             <span> employmentType->s </span>
           </div>
         </li>
       )
     ->RR.list}
  </ul>;
};