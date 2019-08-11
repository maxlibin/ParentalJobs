open Emotion
let hexRed = "ef4f00"

let topFooter = [%css [
  important(backgroundColor (`hex ("333")));
  important(padding2 (`px 60) `zero);
]]

let title = [%css [
  fontSize (`px 32);
  fontWeight 700;
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