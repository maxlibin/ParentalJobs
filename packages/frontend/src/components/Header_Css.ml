open Emotion

let brand = [%css [
  important(color (`hex "ef4f0b"));
  textTransform `uppercase;
  important(fontWeight 900);
]]

let navLink = [%css [
  color (`hex "333");
  fontSize (`px 18);

  hover [
    color (`hex "ef4f00");
  ]
]]