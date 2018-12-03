/*
adapted from Simple Serial Server by Tom Igoe
*/

var SerialPort = require('serialport');		
var	portName =  "/dev/cu.usbmodemHIDGD1";
var express = require('express');
var server = express();	
var robot = require("robotjs");
var myParser = require("body-parser");

// var myPort = new SerialPort(portName, 9600);

// myPort.on('open', showPortOpen);  
// myPort.on('close', showPortClose);
// myPort.on('error', showError); 
// myPort.on('data', readSerialData); 


server.use( myParser.json());
server.listen(8080);   


server.use(myParser.urlencoded({extended : true}));

server.post("/posts", function(request, response) {
  console.log(request.body.data);
});

function showPortOpen() {
  console.log('port open. Data rate: ' + myPort.baudRate);
}

function showPortClose() {
  console.log('port closed.');
}

function showError(error) {
  console.log('Serial port error: ' + error);
}

