var express = require("express");
var router = express.Router();

import JobsModal from "../db/jobs";

const defaultLimit = 20; // users per page

router.get("/", function(req, res) {
  res.send("nothing");
});

router.get("/jobs", function(req, res) {
  let { skip, limit } = req.query;
  limit = (limit ? limit : defaultLimit) - 0;
  skip = (skip ? skip : 0) - 0;

  JobsModal.find({}, null, { skip, limit }, (err, docs) => {
    res.status(200).json(docs);
  });
});

router.get("/job/:id", function(req, res) {
  JobsModal.findOne({ _id: req.params.id }, (err, docs) => {
    res.status(200).json(docs);
  });
});

router.get("/jobs/latest", function(req, res) {
  JobsModal.find({}, null, { skip: 0, limit: defaultLimit }, (err, docs) => {
    res.status(200).json(docs);
  });
});

export default router;
