# Parental Jobs

### Web:
Clone the project to your local folder:

The project is structured into 2 parts

```
| packages - frontend
| pacakges - backend
```
Since we are using yarn workspace, you can install the web project with:

```
yarn install
```
in the root folder, this will install node_modules into root folder and alias to `packages/*` so that you don't have to go into each folder to install, and start by

```
yarn dev
```

Open your browser with port 3000, `http://localhost:3000`


## Frontend:

Frontend is using ReasonReact / ReasonML

## Backend:

Backend currently using NodeJs + Mongo,

### Start a MongoDB Server

Download the right MongoDB version from MongoDB
Create a database directory (in this case under /data).
Install and start a mongod process.
mongod --dbpath=/data

You should see the mongod process start up and print some status information.

### Crawler:

Crawler will crawl `skillfuture website` recusivly using puppeteer(for js execution), currently set to total crawl page to 50.

```
yarn crawl
```

Crawler is written in nodejs using puppeteer, might not be most effective way, but it does the job that crawls js executed site, for now.

Tried on local machine 30mins for 2000 js executed pages. should probably should setup some clustering for the crawler.

