open Emotion

let hexRed = "ef4f00"

let container = [%css [
  borderBottom (`px 1) `solid (`hex "eee");
  paddingBottom (`px 60);
]]

let header = [%css [
  textAlign `center;
]]

let title = [%css [
  fontSize (`px 58);
  padding2 (`px 30) (`px 20);
  marginBottom `zero;
  display `inlineBlock;
  color (`hex "333");
  fontWeight 700;
  textTransform `uppercase;
]]

let subTitle = [%css [
  fontSize (`px 18);
  padding2 `zero (`px 20);
  display `block;
  margin3 `zero `auto (`px 30);
  textAlign `center;
  color (`hex "333");
  fontWeight 400;
  maxWidth (`px 920);
  lineHeight (`px 28);
]]

let button = [%css [
  display `inlineBlock;
  borderStyle `none;
  padding2 (`px 10) (`px 20);
  backgroundColor (`hex hexRed);
  color Css.Color.white;
  fontWeight 700;
]]

let jobsList = [%css [
  marginTop (`px 60);
  marginBottom (`px 60);
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

let parentFriendlyjob = [%css [
  backgroundColor (`rgba(255, 137, 32, 0.18));
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