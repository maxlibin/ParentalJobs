open Emotion
let hexRed = "ef4f00"
let hexRedHovered = "ef2f00"

let button = [%css [
  borderStyle `none;
  padding2 (`px 10) (`px 20);
  backgroundColor (`hex hexRed);
  color Css.Color.white;
  fontWeight 700;

  hover [
    backgroundColor (`hex hexRedHovered);
  ]
]]