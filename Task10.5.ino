#include <Wire.h> 

const int ADDR = 0x68;

void setup() {
  Wire.begin();  
  Serial.begin(9600); 
  Wire.beginTransmission(ADDR); 
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);  
}

void loop() {
  int16_t GZ = GyroZ();
  float GZ_dps = GZ/131.0;
  Serial.print("Yaw:");
  Serial.print(GZ_dps);
  Serial.println("");
  delay(500);  
}

int16_t GyroZ() {
  Wire.beginTransmission(ADDR);  
  Wire.write(0x47);
  Wire.endTransmission(false);  
  Wire.requestFrom(ADDR,2,true);
  int high=Wire.read();  
  int low=Wire.read();  
  int16_t GZ=(high<<8) | low;
  return GZ;
}