/*
adapted from Simple Serial Server by Tom Igoe
*/

var SerialPort = require('serialport');		
var	portName =  "/dev/cu.usbmodem143101";
var express = require('express');
var server = express();	
var robot = require("robotjs");

var myPort = new SerialPort(portName, 9600);

myPort.on('open', showPortOpen);  
myPort.on('close', showPortClose);
myPort.on('error', showError); 
myPort.on('data', readSerialData); 


server.use('/',express.static('public')); 
server.listen(8080);   

function showPortOpen() {
  console.log('port open. Data rate: ' + myPort.baudRate);
}

function readSerialData(data) {
  console.log(data[0], data[1]);
  // let x = Number(data[0]);
  // let y = Number(data[1]);
  // robot.moveMouse(x, y);
}

function showPortClose() {
  console.log('port closed.');
}

function showError(error) {
  console.log('Serial port error: ' + error);
}

// ------------------------ Server function
function sendData(request) {
  // print out the fact that a client HTTP request came in to the server:
  console.log("Got a client request, sending them the data.");
  // respond to the client request with the latest serial string:
  request.respond(serialData);
}
