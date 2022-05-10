#include <Wire.h> // i2c 통신을 위한 라이브러리 불러오기
#include <Adafruit_MLX90614.h>  // 비접촉식 온도측정센서 라이브러리 불러오기
#include <LiquidCrystal_I2C.h>  // lcd 1602 i2c용 라이브러리
LiquidCrystal_I2C lcd(0x3F,16,2);  // 접근주소: 0x3F or 0x27
 

void setup() {
  Serial.begin(9600);
  lcd.init();  // lcd 초기화
  lcd.backLight();  // 백라이트 켜기
  mlx.begin();  // mlx 모듈을 읽기 시작
}

void loop() {
  String strTemp = String("");
  strTemp += (int)(mlx.readObjectTmpC());  // 주변 온도를 읽습니다.
  lcd.setCursor(2,0);  // 2행 0열
  lcd.print("Temperature");  // Temprature 표시
  lcd.setCursir(6, 1);  // 6행 1열
  lcd.print(strTemp);  // 측정 온도 표시
  lcd.setCursor(8, 1);  // 8행 1열
  lcd.print("'c");  // 온도 단위 표시  
}
