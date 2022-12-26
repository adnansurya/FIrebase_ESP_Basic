#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define FIREBASE_HOST "surveypopulation-45c8a-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "fG5G5pzZ4tKlKu8j25fYNdqkBR9mBot6TtSHzgsY"
#define WIFI_SSID "CS BIZNET 2.4G"
#define WIFI_PASSWORD "micelbocel123"

FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  //memulai menghubungkan ke wifi router  
  Serial.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    
    delay(500);    
    Serial.print("."); //status saat mengkoneksikan
  }
  Serial.println("Connected!");

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  String datanya = getStrData("/teks");


  Serial.print("DATANYA : ");
  Serial.println(datanya);  

}

void loop() {
  // put your main code here, to run repeatedly:

}

String getStrData(String fbDir){
   
  String resultStr;
  if (Firebase.getString(firebaseData, fbDir)) {   
         
      if(firebaseData.dataType() == "string"){        
        resultStr = firebaseData.stringData();
      }else{
        resultStr = "unknown";
      }
    }else{      
      resultStr = firebaseData.errorReason();     
    }
  return resultStr;
}
