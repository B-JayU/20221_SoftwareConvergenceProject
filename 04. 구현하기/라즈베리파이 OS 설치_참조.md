## 라즈베리파이에 OS 설치하는 방법
참고링크 : https://sergeswin.com/1268/

## 모니터, 키보드 없이 사용하는 방법
1. SD 카드에 라즈베리 파이 OS 설치
2. 원격 로그인을 위해 'ssh' 기능 켜기
  - mac os에서는 touch /Volumes/boot/ssh
  - mac os에서는 nano /Volumes/boot/wpa_supplicant.conf
    - ssid : 사용하는 wifi 이름
    - psk = 암호
    - ctrl+o, enter, ctrl + x 누르기
    - 
