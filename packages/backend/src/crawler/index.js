const puppeteer = require("puppeteer");
const cheerio = require("cheerio");

let urlPage = 0;
const maxPage = 5; // TODO:
const domain = "https://www.mycareersfuture.sg";
let defaultUrl = page =>
  `${domain}/search?sortBy=new_posting_date&page=${page}`;

(async () => {
  const browser = await puppeteer.launch({
    headless: false
  });

  const page = await browser.newPage();

  const getUrlsAsList = bodyHTML => {
    let urls = [];
    const $ = cheerio.load(bodyHTML);

    $(".card-list div[id^=job-card] a").each((index, ele) =>
      urls.push($(ele).attr("href"))
    );

    return urls;
  };

  const getContentRec = async (urlList, page, urlPage) => {
    if (urlPage === urlList.length) {
      await page.close();

      return;
    }

    const url = `${domain}${urlsList[urlPage]}`;
    const nextPage = urlPage + 1;

    await page.goto(url, { waitUntil: "networkidle0" });

    getContentRec(urlList, page, nextPage);
  };

  const getUrlsContent = async urlsList => {
    const page = await browser.newPage();

    getContentRec(urlsList, page, 0);
  };

  const goToUrlRec = async (url, urlPage) => {
    try {
      if (urlPage === maxPage) {
        await browser.close();
        return;
      }

      await page.goto(url, { waitUntil: "networkidle0" });

      const bodyHTML = await page.evaluate(() => document.body.innerHTML);
      const urlList = getUrlsAsList(bodyHTML);

      getUrlsContent(urlList);

      const nextPage = urlPage + 1;
      goToUrlRec(defaultUrl(nextPage), nextPage);
    } catch (err) {
      console.log(err);
    }
  };

  await goToUrlRec(defaultUrl(0), 0);
})();
