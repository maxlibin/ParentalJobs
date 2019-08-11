open Emotion

let content = [%css [
  marginRight (`px 60);
  select "p, li" [
    fontSize (`px 18);
    fontWeight 300;
    lineHeight (`px 24);  
    marginBottom (`px 16);
  ];

  select "ul" [
    marginBottom (`px 24);
  ];

  select ".brand-sec" [
    fontSize (`px 22);
    fontWeight 700;
  ]
]]

let contentWrapper = [%css [
  borderBottom (`px 1) `solid (`hex "eee");
  marginBottom (`px 30);
  paddingBottom (`px 30);
]]

let postDate = [%css [
  display `block;
  marginBottom (`px 12);
]]

let jobTitle = [%css [
  display `block;
  fontSize (`px 28);
  fontWeight 700;
  marginBottom (`px 20);
]]

let companyName = [%css [
  display `block;
  fontSize (`px 14);
  marginBottom (`px 20);
]]

let tags = [%css [
  marginBottom (`px 20);
  borderBottom (`px 1) `solid (`hex "eee");
  paddingBottom (`px 30);
]]

let tag = [%css [
  display `inlineBlock;
  backgroundColor (`hex "0088ec");
  color Css.Color.white;
  padding2 (`px 3) (`px 10);
  marginRight (`px 10);
  marginBottom (`px 10);
]]

let quality = [%css [
  boxShadow ~x:`zero ~y:`zero ~blur:`zero ~spread:(`px 1) (`rgba (0, 0, 0, 0.16));
  position `relative;
  marginTop (`px 30);
  marginBottom (`px 30);
  padding4 (`px 40) (`px 20) (`px 20) (`px 20);
  textAlign `left;
]]

let letusKnow = [%css [
  border (`px 1) `solid (`hex "ccc");
  padding2 (`px 10) (`px 20);
  color (`hex "333");
  marginTop (`px 10);
  display `inlineBlock;

  hover [
    textDecoration `none;
  ]
]]