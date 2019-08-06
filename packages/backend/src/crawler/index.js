const puppeteer = require("puppeteer");
const cheerio = require("cheerio");

let urlPage = 0;
const maxPage = 50; // temp...

(async () => {
  const browser = await puppeteer.launch({
    headless: false
  });

  const page = await browser.newPage();

  const goToUrl = async urlPage => {
    if (urlPage === maxPage) {
      await browser.close();

      return;
    }

    const url = `https://www.mycareersfuture.sg/search?sortBy=new_posting_date&page=${urlPage}`;

    await page.goto(url, { waitUntil: "networkidle0" });
    goToUrl(urlPage + 1);
  };

  await goToUrl(0);
  // let bodyHTML = await page.evaluate(() => document.body.innerHTML);

  // console.log(bodyHTML);
  // await page.screenshot({ path: "example.png" });

  // await browser.close();
})();
