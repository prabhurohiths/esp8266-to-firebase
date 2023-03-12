// #define FIREBASE_HOST "prabhusrohith-default-rtdb.firebaseio.com"  
// #define FIREBASE_AUTH "IVzo5cSDhBflUPhdJlNttrZczmb2COrzU0DFtKBz"  
// #define WIFI_SSID "Rohini-2.4G"
// #define WIFI_PASSWORD "prabhugalu"

#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>                         
#define FIREBASE_HOST "prabhusrohith-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "IVzo5cSDhBflUPhdJlNttrZczmb2COrzU0DFtKB" 
#define WIFI_SSID "Rohini-2.4G"                                              
#define WIFI_PASSWORD "prabhugalu"                                      
// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;
// Declare global variable to store value
int val=0;
void setup() {
  Serial.begin(115200);                                   
  // Select the same baud rate if you want to see the data on Serial Monitor
  Serial.println("Serial communication started\n\n");           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                    
  //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());//print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);// connect to firebase
  Firebase.reconnectWiFi(true);
  delay(1000);
}
void loop() 
{ 
 val = random(0,100);
// Firebase Error Handling And Writing Data At Specifed Path**********************************************
if (Firebase.pushInt(firebaseData, "/VaahiUsers", val))
{ 
               Serial.println("Storingdata Uploaded Successfully");
               Serial.print("Val = ");
               Serial.println(val);
               Serial.println("\n");
               delay(1000);
}
else {        
    Serial.println(firebaseData.errorReason());
  }


if (Firebase.setInt(firebaseData, "/Monitoringdata", val))//  to set only one value
{ 
               // On successful Write operation, function returns 1  
               Serial.println("Monitoringdata Uploaded Successfully");
               Serial.print("Val = ");
               Serial.println(val);
               Serial.println("\n");
               delay(1000);
}
else {        
    Serial.println(firebaseData.errorReason());
  }
}