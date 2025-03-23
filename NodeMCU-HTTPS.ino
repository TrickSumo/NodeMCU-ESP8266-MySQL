/* Code Written by Rishi Tiwari
 *  Website:- https://tricksumo.com
 * Use this file if your hosting provider supports HTTPS (SSL/TLS).
*/



#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h> 


#define WIFI_SSID ""            // WIFI SSID here                                   
#define WIFI_PASSWORD ""        // WIFI password here


// Declare global variables which will be uploaded to the server

int val = 1;
int val2 = 99;

String sendval, sendval2, postData;


void setup() {

     
Serial.begin(115200); 
Serial.println("Communication Started \n\n");  
delay(1000);
  

pinMode(LED_BUILTIN, OUTPUT);     // initialize built in led on the board
 


WiFi.mode(WIFI_STA);           
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
Serial.print("Connecting to ");
Serial.print(WIFI_SSID);
while (WiFi.status() != WL_CONNECTED) 
{ Serial.print(".");
    delay(500); }

Serial.println();
Serial.print("Connected to ");
Serial.println(WIFI_SSID);
Serial.print("IP Address is : ");
Serial.println(WiFi.localIP());    //print local IP address

delay(30);
}



void loop() { 

HTTPClient http;    // http object of clas HTTPClient
WiFiClientSecure wclient; // wclient object of clas HTTPClient    
// Disable SSL certificate validation (not secure, but needed if you don't have certificates)
// wclient.setInsecure();  

// Convert integer variables to string
sendval = String(val);  
sendval2 = String(val2);   

 
postData = "sendval=" + sendval + "&sendval2=" + sendval2;

http.begin(wclient, "http://example.com/dbwrite.php");
http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
  
int httpCode = http.POST(postData); 
  
// Print status code
Serial.print("HTTP Response Code: ");
Serial.println(httpCode);

// if connection eatablished then do this
if (httpCode == 200) { 
  Serial.println("Values uploaded successfully."); 
  Serial.println(httpCode); 
  String webpage = http.getString();    // Get html webpage output and store it in a string
  Serial.println(webpage + "\n"); 
}

// if failed to connect then return and restart

else { 
  Serial.println(httpCode); 
  Serial.println("Failed to upload values. \n"); 
  http.end(); 
  return; }


delay(3000); 
digitalWrite(LED_BUILTIN, LOW);
delay(3000);
digitalWrite(LED_BUILTIN, HIGH);

val+=1; val2+=10; // Incrementing value of variables


}
