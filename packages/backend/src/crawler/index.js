const puppeteer = require("puppeteer");
const cheerio = require("cheerio");

import JobsModel from "../db/Jobs";

let startPage = 0;
const maxPage = 100; // TODO: dynamic...
const domain = "https://www.mycareersfuture.sg";
let defaultUrl = page =>
  `${domain}/search?sortBy=new_posting_date&page=${page}`;

(async () => {
  const browser = await puppeteer.launch({
    headless: true
  });

  const page = await browser.newPage();

  const processBodyHTML = bodyHTML => {
    const $ = cheerio.load(bodyHTML);
    /* 
      TODO: 
        Send everything to data and process in another clean data process...
        For now just try to grab data first.
    */
    return {
      company: $("div[data-cy='company-hire-info__company']").text(),
      jobTitle: $("#job_title").text(),
      jobId: $("div[data-cy='info__jobpostid--span']").text(),
      address: $("#address a").text(),
      employmentType: $("#employment_type").text(),
      seniority: $("#seniority").text(),
      minExperience: $("#min_experience").text(),
      jobCategories: $("#job-categories").text(),
      salary: {
        salaryFrom: $(".salary_range .dib:nth-child(1)").text(),
        salaryTo: $(".salary_range .dib:nth-child(2)").text(),
        salaryType: $(".salary_type").text()
      },
      postedOn: $("#last_posted_date").text(),
      jobDescription: $("#job_description").html(), // TODO: Need to clean up data, currently on frontend side dangerouslySetInnerHTML
      requirement: $("#requirements").html() // TOOD: Need to  clean up data, currently on frontend side dangerouslySetInnerHTML
    };
  };

  const insertToDB = (data = {}) => {
    if (!data) return;

    const Job = new JobsModel(data);
    Job.save(data);
  };

  const saveToDB = bodyHTML => process => insert => insert(process(bodyHTML));

  const getContentRec = async (urlList, page, urlPage) => {
    if (!urlList || urlPage === urlList.length) {
      await page.close();

      return;
    }

    const url = `${domain}${urlList[urlPage]}`;
    const nextPage = urlPage + 1;

    await page.goto(url, { waitUntil: "networkidle0" });
    const bodyHTML = await page.content();

    saveToDB(bodyHTML)(processBodyHTML)(insertToDB);
    getContentRec(urlList, page, nextPage);
  };

  const getUrlsContent = async urlsList => {
    const page = await browser.newPage();

    getContentRec(urlsList, page, 0);
  };

  const getUrlsAsList = bodyHTML => {
    let urls = [];
    const $ = cheerio.load(bodyHTML);

    $(".card-list div[id^=job-card] a").each((index, ele) =>
      urls.push($(ele).attr("href"))
    );

    return urls;
  };

  const goToUrlRec = async (url, urlPage) => {
    try {
      if (urlPage === maxPage) {
        await page.close();
        return;
      }

      await page.goto(url, { waitUntil: "networkidle0" });

      const bodyHTML = await page.content();
      const urlList = getUrlsAsList(bodyHTML);

      getUrlsContent(urlList);

      const nextPage = urlPage + 1;
      goToUrlRec(defaultUrl(nextPage), nextPage);
    } catch (err) {
      console.log(err);
    }
  };

  await goToUrlRec(defaultUrl(startPage), startPage);
})();
