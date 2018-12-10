/*
adapted from Simple Serial Server by Tom Igoe
*/

var SerialPort = require('serialport');		
var	portName =  "/dev/cu.usbmodemHIDGD1";
var express = require('express');
var server = express();	
var myParser = require("body-parser");
let myPort;

let opened = false;

open();

server.use( myParser.json());
server.listen(8080);   

server.use(myParser.urlencoded({extended : true}));

server.post("/posts", function(request, response) {
  if (myPort) {
    console.log(request.body.data);
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
}

function showPortClose() {
  console.log('port closed.');
  opened = false;
  open();
}

function showError(error) {
  console.log('Serial port error: ' + error);
}
/*
adapted from Simple Serial Server by Tom Igoe
*/

var SerialPort = require('serialport');		
var	portName =  "/dev/cu.usbmodemHIDGD1";
var express = require('express');
var server = express();	
var myParser = require("body-parser");
let myPort;

let opened = false;

open();

server.use( myParser.json());
server.listen(8080);   

server.use(myParser.urlencoded({extended : true}));

server.post("/posts", function(request, response) {
  if (myPort) {
    console.log(request.body.data);
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
}

function showPortClose() {
  console.log('port closed.');
  opened = false;
  open();
}

function showError(error) {
  console.log('Serial port error: ' + error);
}
