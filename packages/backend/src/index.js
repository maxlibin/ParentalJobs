import express from "express";
import bodyParser from "body-parser";
import path from "path";

import api from "./api/api";

const port = 5000;
const app = express();

app.use(bodyParser.json());

app.use("/api", api);

app.get("*", (req, res) => {
  res.sendFile(path.resolve(__dirname, "../../frontend/src/index.html"));
});

app.listen(port, () => console.log(`Example app listening on port ${port}!`));
