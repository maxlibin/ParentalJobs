open Emotion

let avatar = [%css [
  width (`px 60);
  height (`px 60);
  border (`px 3) `solid Css.Color.white;
  backgroundColor (`hex "f3f3f3");
  borderRadius (`pct 50.);
  color Css.Color.white;
]]

let name = [%css [
  fontSize (`px 32);
  fontWeight 700;
  display `flex;
  width (`pct 100.);
  height (`pct 100.);
  alignItems `center;
  justifyContent `center;
]]
