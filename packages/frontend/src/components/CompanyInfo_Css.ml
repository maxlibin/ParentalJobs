open Emotion

let info = [%css [
  boxShadow ~x:`zero ~y:`zero ~blur:`zero ~spread:(`px 1) (`rgba (0, 0, 0, 0.16));
  position `relative;
  marginTop (`px 30);
  padding4 (`px 40) (`px 20) (`px 20) (`px 20);
  textAlign `center;
]]

let company = [%css [
  fontSize (`px 16);
  fontWeight 700;
]]

let address = [%css [
  fontSize (`px 16);
]]

let button = [%css [
  display `block;
  width (`pct 100.);
]]

let avatar = [%css [
  display `block;
  position `absolute;
  left (`pct 50.);
  marginLeft (`px ~-30);
  top (`px ~-30);
]]
