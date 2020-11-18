#!/usr/bin/node

const request = require('request');
let characters = [];

function displayNames () {
  if (process.argv.length === 3) {
    const movieURL = 'https://swapi-api.hbtn.io/api/films';
    const movieID = process.argv[2];
    request(`${movieURL}/${movieID}`, async function (error, response, body) {
      if (error) {
        console.log(error);
      } else if (response.statusCode === 200) {
        characters = JSON.parse(body).characters;
        for (let i = 0; i < characters.length; i++) {
          const personURL = characters[i];
          const syncResponse = await syncRequest(personURL);
          console.log(syncResponse);
        }
      }
    });
  }
}

const syncRequest = function (url) {
  return new Promise((resolve, reject) => {
    request(url, function (error, response, body) {
      if (error) {
        return reject(error);
      } else if (response) {
        return resolve(JSON.parse(body).name);
      }
    });
  });
};

displayNames();
