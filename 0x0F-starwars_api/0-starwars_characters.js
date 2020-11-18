#!/usr/bin/node

const request = require('request');

if (process.argv.length === 3) {
  const movieURL = 'https://swapi-api.hbtn.io/api/films';
  const movieID = process.argv[2];
  request(`${movieURL}/${movieID}`, function (err, res, body) {
    if (err) {
      console.log(err);
    } else if (res.statusCode === 200) {
      const characters = JSON.parse(body).characters;
      for (let i = 0; i < characters.length; i++) {
        const personURL = characters[i];
        request(personURL, function (perror, pres, pbody) {
          if (perror) {
            console.log(perror);
          } else if (pres.statusCode === 200) {
            console.log(JSON.parse(pbody).name);
          }
        });
      }
    }
  });
}
