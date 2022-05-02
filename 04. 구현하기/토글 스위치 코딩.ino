#include <Servo.h>

int motor = 6;  // 서보모터 핀번호
int value;      // 원형 토글스위치의 값
int angle = 0;  // 서보모터 각도
Servo servo;

void setup() {
  Serial.begin(9600);  // 시리얼 통신, 속도는 9600
  servo.attach(motor);  //모터 시작
  pinMode(motor, OUTPUT);  //모터 출력
}

void loop() {
  value = digitalRead(A0);  // 토글 스위치의 값 읽기
  //Serial.println(value)

  if(value == HIGH){  // 토글 스위치의 값이 on 일 때
    if(angle > 180){  // 서보모터의 각도 값이 180 이상일 
      delay(10);  // 180에서 더이상 증가하지 못하도록 delay
    }else{  // 서보모터의 각도 값이 180 이하일때
      angle++;  // 각도 값 1씩 증가
      servo.write(angle); // 서보모터 돌려주기
      }
  }else{  // 토글 스위치의 값이 off 일 때 
    if(angle < 0){  // 서보모터의 각도 값이 0도 이하로 내려갈 때
        delay(10);  // 0도에서 더이상 감소하지 못하도록 delay 넣어주기
      }else{  // 서보모터의 각도 값이 0 이상일 때
        angle--;  // 각도 값 1씩 감소
        servo.write(angle);  // 서보모터 돌려주기
      }
    }
    //Serial.pintln(angle);
    delay(10);  // 급격한 서보모터의 움직임을 제한하기 위한 delay값
}
