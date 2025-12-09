// Motor Control functions for all four motors
#include <Motor.h> 
// Functions for Arduino Layout/structure
#include <Arduino.h>
// Used for the HTTP Server and will handle the robot commands
#include <WebServer.h>
// Enabling the Wi-Fi Feature that ESP32 has
#include <WiFi.h>
// Using the FS (File System) and SPIFFS to store and access images for the webpage
#include "FS.h"
#include "SPIFFS.h"

const char* ssid = "LOG";
const char *password = "ECE528_LOG";
// Creates HTTP Server on port 80 which is the standard web browser port
// This server is where we will have the movement commands and control webpage
WebServer server(80);

const char WebPage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>ESP32 Robot Control</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <style>
        :root {
            --btn-bg: rgba(255, 255, 255, 0.85);
            --btn-bg-hover: #ffe0e0;
            --btn-bg-active: #e53935;
            --panel-bg: rgba(255, 255, 255, 0.92);
            --accent: #b71c1c;
            --text-dark: #222;
        }

        html, body {
            margin: 0;
            padding: 0;
            height: 100%;
            font-family: Arial, sans-serif;
        }

        body {
            background-image: url("9895435.png");
            background-size: cover;
            background-position: center;
            background-attachment: fixed;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .container {
            background: var(--panel-bg);
            padding: 25px 35px;
            border-radius: 16px;
            text-align: center;
            box-shadow: 0 10px 25px rgba(0,0,0,0.3);
            width: 90%;
            max-width: 420px;
        }

        /* -------------------------------------------
           CAMERA FEED CSS (COMMENTED OUT SAFELY)
        ---------------------------------------------

        img {
            max-width: 100%;
            height: auto;
        }

        .camera-box {
            margin-bottom: 20px;
        }

        .camera-box h2 {
            margin: 0 0 10px 0;
            font-size: 20px;
            color: var(--accent);
        }

        #camFeed {
            width: 100%;
            max-width: 400px;
            border-radius: 12px;
            box-shadow: 0 5px 15px rgba(0,0,0,0.35);
        }

        --------------------------------------------- */

        h1 {
            color: var(--accent);
            margin-bottom: 5px;
            font-size: 26px;
        }

        img {
            max-width: 150px;
            height: auto;
            margin-bottom: 20px;
        }

        .row {
            margin: 12px 0;
            display: flex;
            justify-content: center;
            gap: 10px;
        }

        button {
            width: 120px;
            height: 60px;
            font-size: 18px;
            border-radius: 10px;
            border: 1px solid #444;
            background: var(--btn-bg);
            cursor: pointer;
            font-weight: 600;
            transition: 0.15s ease;
        }

        button:hover {
            background: var(--btn-bg-hover);
            transform: translateY(-2px);
            box-shadow: 0 4px 10px rgba(0,0,0,0.2);
        }

        button.active {
            background: var(--btn-bg-active);
            color: white;
            box-shadow: 0 3px 10px rgba(0,0,0,0.3);
        }

        .status {
            margin-top: 12px;
            font-size: 15px;
            color: var(--text-dark);
        }
    </style>
</head>

<body>
<div class="container">

    <!-- ---------------------------------------------------
         CAMERA HTML BLOCK (COMMENTED OUT)
    --------------------------------------------------------
    
    <div class="camera-box">
        <h2>Live Camera</h2>
        <img id="camFeed" src="" alt="Camera Feed">
    </div>

    -------------------------------------------------------- -->

    <h1>LOG Robot Controller</h1>
    <img src="/csun_logo.png" alt="CSUN Logo">

    <div class="row">
        <button data-cmd="f">Forward</button>
    </div>

    <div class="row">
        <button data-cmd="l">Left</button>
        <button data-cmd="s">Stop</button>
        <button data-cmd="r">Right</button>
    </div>

    <div class="row">
        <button data-cmd="b">Backward</button>
    </div>

    <div class="status" id="status">Ready.</div>

</div>

<script>
    const statusEl = document.getElementById("status");
    const buttons = document.querySelectorAll("button[data-cmd]");

    function setActiveButton(cmd) {
        buttons.forEach(btn => {
            if (btn.dataset.cmd === cmd) btn.classList.add("active");
            else btn.classList.remove("active");
        });
    }

    async function sendCmd(cmd) {
        setActiveButton(cmd);
        statusEl.innerHTML = "Sending: " + cmd + "...";

        try {
            const response = await fetch("/cmd?move=" + cmd);
            if (!response.ok) throw new Error("HTTP Error");

            statusEl.innerHTML = "Sent: " + cmd;
        } catch (err) {
            statusEl.innerHTML = "Failed to send command.";
        }
    }

    buttons.forEach(btn => {
        btn.addEventListener("click", () => sendCmd(btn.dataset.cmd));
    });
</script>

</body>
</html>
)rawliteral";
/*
* @brief Sends the main HTML webpage stored in PROMEM (Program Memory)
* to the user's browser when they connect to the ESP32
* This function is called when the root URL "/" is accessed.
* Loads the Webpage variable  containing the HTML/CSS/JS layout for the robot controller interface.
*/
void loadWEB_UI_LOG()
{
  server.send_P(200, "text/html", WebPage);
}
/*
* @brief Handles the movement commands sent from the webpage buttons.
* 
* The Webpage sends a GET request to  the following characters
* 'f' is Forward 
* 'b' is Backward
* 'l' is Left
* 'r' is Right
* 's' is Stop
* 
* The function reads the value, extracts the first character, and performs the motor movement.
* So once recognized, the motors will move, if it doesn't then it prints "Uknown Command" to Serial Monitor.
*/
void control_LOG_Robot()
{
  if(server.hasArg("move"))
  {
    String cmd = server.arg("move");
    char ControlIt = cmd.charAt(0);
    switch(ControlIt)
    {
      case 'f':
      {
        Motor_Forward(180);
        break;
      }
      case 'b':
      {
        Motor_Backward(180);
        break;
      }
      case 'l':
      {
        Motor_Left(180);
        break;
      }
      case 'r':
      {
        Motor_Right(180);
        break;
      }
      case 's':
      {
        Motor_Stop();
        break;
      }
      default:
      {
        Serial.println("Unknown command");
        break;
      }
    }
    server.send(200, "text/plain", "OK");
  }
}
/*
* @brief Initializes the ESP32 robot system, motors, Wi-Fi Access Point, SPIFFS file storage, and HTTP Web Server.
*/
void setup()
{
  // Baud Rate is set to 115200
  Serial.begin(115200);
  // Initializing Motors A,B,C, and D.
  MotorA();
  MotorB();
  MotorC();
  MotorD();
  //creating an independent Wi-Fi Network using ssid = "LOG", and password "ECE528_LOG"
  // This allows any device such as phones/laptop to directly connect to the robot and acces the control webpage.
  // const char such as ssid is the title for the Network that we will look for in the Wi-Fi Networks
  // password char is the password we need to enter to access our Local Web Server
  const char* ssid = "LOG";
  const char* password = "ECE528_LOG";
  // ESP32 creates its own Wi-Fi Network
  WiFi.softAP(ssid, password);   
  Serial.println("Access Point Started!");
  Serial.print("Connect to WiFi: ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  // ESP32 IP address is 192.168.4.1
  // WiFi.softAPIP returns an IP address which will act as the local web server
  Serial.println(WiFi.softAPIP());       
  // Mount SPIFFS for images
  if (!SPIFFS.begin(true))
  {
    Serial.println("SPIFFS Mount Failed");
  }
  // server.serveStatic exposes the image files to the browser such as csun_logo and 9895435 to load onto the webpage
  // and ESP32 will provide them from SPIFFS
  server.serveStatic("/csun_logo.png", SPIFFS, "/csun_logo.png");
  server.serveStatic("/9895435.png", SPIFFS, "/9895435.png");
  //  "/" => Loads the HTML Interface with the program memory 
  server.on("/", loadWEB_UI_LOG);
  // "/cmd" => receives robot movements commands such as (f,b,l,r,s)
  server.on("/cmd", control_LOG_Robot);
  // Starts the web server or activates the HTTP Server so that it can respond to any requests from any connected device.
  server.begin();
  Serial.println("HTTP Server Started");
}
/*
* @brief Handles incoming HTTP user requests
*
* This causes the Web Server to be responsive for Button Presses, Movement Commands, and etc.
*
* Motor Speed Adjusment was for testing
*/
void loop() {
  // AdjustMotorA_Speed();
  // AdjustMotorB_Speed();
  // AdjustMotorC_Speed();
  // AdjustMotorD_Speed();

  // Motor_Forward(180);
  // delay(2000);
  // Motor_Forward(0);
  // delay(1000);

  server.handleClient();
}
