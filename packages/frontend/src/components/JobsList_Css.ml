open Emotion

let jobsListWrapper = [%css [
  paddingLeft `zero;
]]

let job = [%css [
  backgroundColor (`rgba(3, 3, 3, 0.02));
  margin `zero;
  listStyleType `none;
  padding (`px 20);
  marginBottom (`px 20);
  borderLeft (`px 5) `solid (`hex "d4d4d4");
  display `flex;
  flexWrap `wrap;
  alignItems `center;
  position `relative;

  select "div:first-of-type" [
    flex (`some(1., 1., `auto));
  ];

  hover [
    backgroundColor (`rgba(3, 3, 3, 0.04));
    cursor `pointer;
  ];

  media "(max-width: 768px)" [
    paddingTop (`px 40);
    marginBottom (`px 60);
  ];
]]

let avatar = [%css [
  display `block;
  position `absolute;
  right (`px ~-30);

  media "(max-width: 768px)" [
    right (`pct 50.);
    marginRight (`px ~-30);
    top (`px ~-30);
  ];
]]

let parentFriendlyjob = [%css [
  backgroundColor (`rgba(255, 137, 32, 0.18));
  borderLeft (`px 5) `solid (`rgba(255, 137, 32, 0.8888));

  hover [
    backgroundColor (`rgba(255, 137, 32, 0.28));
    borderLeft (`px 5) `solid (`rgba(255, 137, 32, 0.9888));
  ];
]]

let company =  [%css [
  display `block;
  fontSize (`px 16);
  marginBottom (`px 8);
]]

let jobTitle = [%css [
  display `block;
  fontSize (`px 24);
  marginBottom (`px 12);
]]

let category = [%css [
  fontStyle `normal;
]]

let employmentType = [%css [
  marginLeft `auto;
  fontSize (`px 16);
  fontWeight 700;
  marginRight (`px 50);

  media "(max-width: 768px)" [
    display `block;
    marginTop (`px 20);
    width (`pct 100.);
  ];
]]