/*
  Let's watch the inheritance graph when an async callback
  launches an async callback.
*/

var fs = require("fs");

fs.readFile("/tmp/foo", function(){
  console.log("APP: Level 1");
  fs.readFile("/tmp/foo", function(){
    console.log("APP: Bottomed out");
  });
});

//Start reading from stdin so we don't exit.
process.stdin.resume();
