#include <Motor.h>
#include <Arduino.h>
#include <WebServer.h>
#include <WiFi.h>

/*
*
*
*
*
*
*/
const char* ssid = "LOG";
const char *password = "ECE528_LOG";
WebServer server(80);

const char WebPage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Robot Control</title>
    <style>
        html, body
        {
            height:100%;
            margin:0;
            padding:0;
            font-family: Arial, sans-serif;

        }
        body
        {
            background-image:url("9895435.png");
            background-size:cover;
            background-position:center;
            background-attachment:fixed;
            background-repeat: no-repeat;
            color: black;
            text-align: center;
            margin-top: 100px;
        }
        button 
        {
            width: 120px;
            height: 60px;
            font-size: 20px;
            margin: 10px;
            cursor: pointer;
        }
        .row
        {
            margin: 15px;
        }
        img
        {
            width: 200px;
            margin-bottom: 20px;
            height:auto;
        }
        button
        {
            width:120px;
            height:60px;
            font-size:20px;
            cursor: pointer;
            margin:10px;
        }
    </style>
</head>
<body>

    <h1>LOG Robot Controller</h1>
    <img src="csun_logo.png">

    <div class="row">
        <button onclick="sendCmd('forward')">Forward</button>
    </div>
    <div class="row">
        <button onclick="sendCmd('left')">Left</button>
        <button onclick="sendCmd('stop')">Stop</button>
        <button onclick="sendCmd('right')">Right</button>
    </div>
    <div class="row">
        <button onclick="sendCmd('back')">Backward</button>
    </div>

    <script>
        function sendCmd(cmd) {
            fetch(`/cmd?move=${cmd}`)
                .catch(err => console.log("Command failed", err));
        }
    </script>

</body>
</html>
)rawliteral";

void loadWEB_UI_LOG()
{
  server.send_P(200, "text/html", WebPage);
}
void control_LOG_Robot()
{
  if(server.hasArg("move"))
  {
    String cmd = server.arg("move");

    if (cmd == "forward")
    {
      Motor_Forward(180);
    }
    else if (cmd == "backward")
    {
      Motor_Backward(180);
    }
    else if (cmd == "left")
    {
      Motor_Left(180);
    }
    else if(cmd == "right")
    {
      Motor_Right(180);
    }
    else if (cmd == "stop")
    {
      Motor_Stop();
    }
    server.send(200,"text/plain", "OK");
  }
}

void setup()
{
  Serial.begin(115200);

  // Initialize motors
  MotorA();
  MotorB();
  MotorC();
  MotorD();

  // ---- ESP32 ACCESS POINT MODE ----
  const char* ssid = "LOG";
  const char* password = "ECE528_LOG";

  WiFi.softAP(ssid, password);           // ESP32 creates its own WiFi
  Serial.println("Access Point Started!");
  Serial.print("Connect to WiFi: ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());       // Usually 192.168.4.1

  // ---- Web Routes ----
  server.on("/", loadWEB_UI_LOG);
  server.on("/cmd", control_LOG_Robot);

  // Start server
  server.begin();
  Serial.println("HTTP Server Started");
}


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
