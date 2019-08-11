open Emotion

let content = [%css [
  select "p" [
    fontSize (`px 16);
    lineHeight (`px 24);  
  ];

  select ".brand-sec" [
    fontSize (`px 24);
    fontWeight 700;
  ]
]]

let postDate = [%css [
  display `block;
  marginBottom (`px 12);
]]

let jobTitle = [%css [
  display `block;
  fontSize (`px 28);
  marginBottom (`px 20);
]]

let companyName = [%css [
  display `block;
  fontSize (`px 14);
  marginBottom (`px 20);
]]

let tags = [%css [
  marginBottom (`px 30);
  borderBottom (`px 1) `solid (`hex "eee");
  paddingBottom (`px 30);
]]

let tag = [%css [
  display `inlineBlock;
  backgroundColor (`hex "ef4f00");
  color Css.Color.white;
  padding2 (`px 3) (`px 10);
  marginRight (`px 10);
]]