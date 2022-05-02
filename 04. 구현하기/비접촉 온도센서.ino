/*
 * 예제138-2
 * TM1637을 추가해서 온도센서의 값을 FND에 시각화해보자!
 * TM1637의 CLK는 D2에 연결했고 DIO는 D3에 연결했다!
 */

#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Arduino.h>
#include <TM1637Display.h>

#define CLK 2
#define DIO 3

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
TM1637Display display(CLK, DIO);
float temp;
int index = 0;

void setup() {
  Serial.begin(9600);

  Serial.println("Adafruit MLX90614 test");  
  display.setBrightness(0x0f);
  mlx.begin();  
}

void loop() {
  //데이터 누적..
  temp += mlx.readObjectTempC();
  index++;
  //0 1 2 3 4 (5)
  if(index >= 5){
    //결과출력
    temp = temp/5;
    Serial.println(temp);
                       //숫자,     ,길이,위치
    display.showNumberDec((int)temp, true, 2, 0); //정수부분
    display.showNumberDec((int)(temp*100) % 100, true, 2, 2); //소수점부분
    temp = 0;
    index =0;
  }
  /*
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
*/
  delay(500);
}
