/*
adapted from Simple Serial Server by Tom Igoe
*/

var SerialPort = require('serialport');		
var	portName =  "/dev/cu.usbmodemHIDGD1";
var express = require('express');
var server = express();	
var myParser = require("body-parser");
let myPort;
const say = require('say');
let opened = false;

open();

server.use( myParser.json());
server.listen(8080);   

server.use(myParser.urlencoded({extended : true}));

let cost = 0;

server.post("/posts", function(request, response) {
  if (myPort) {
    console.log(request.body.data);
    cost++;
    say.speak(`you just made this website ${cost} cents`);
    myPort.write('x');
  }
});

function open() {
  myPort = new SerialPort(portName, 9600);
  myPort.on('open', showPortOpen);  
  myPort.on('close', showPortClose);
  myPort.on('error', showError); 

  if (!opened) {
    setTimeout(function() {
      if (!opened) {
        open();
      }
    }, 2000);
  }
}

function showPortOpen() {
  console.log('port open. Data rate: ' + myPort.baudRate);
  opened = true;
  myPort.flush();
}

function showPortClose() {
  console.log('port closed.');
  opened = false;
  open();
  cost = 0;
}

function showError(error) {
  console.log('Serial port error: ' + error);
}