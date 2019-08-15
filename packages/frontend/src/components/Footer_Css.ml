open Emotion
let hexRed = "ef4f00"

let topFooter = [%css [
  important(backgroundColor (`hex ("333")));
  important(padding2 (`px 60) `zero);
]]

let title = [%css [
  fontSize (`px 22);
  fontWeight 900;
  textTransform `uppercase;
]]

let button = [%css [
  display `inlineBlock;
  borderStyle `none;
  padding2 (`px 10) (`px 20);
  backgroundColor (`hex hexRed);
  color Css.Color.white;
  fontWeight 700;
]]