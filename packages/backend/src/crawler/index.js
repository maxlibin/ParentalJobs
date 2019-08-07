const puppeteer = require("puppeteer");
const cheerio = require("cheerio");

let urlPage = 0;
const maxPage = 50; // temp...

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

  const goToUrl = async urlPage => {
    try {
      if (urlPage === maxPage) {
        await browser.close();
        return;
      }

      const url = `https://www.mycareersfuture.sg/search?sortBy=new_posting_date&page=${urlPage}`;

      await page.goto(url, { waitUntil: "networkidle0" });

      const bodyHTML = await page.evaluate(() => document.body.innerHTML);
      const getUrlList = getUrlsAsList(bodyHTML);

      goToUrl(urlPage + 1);
    } catch (err) {
      console.log(err);
    }
  };

  await goToUrl(0);
})();
