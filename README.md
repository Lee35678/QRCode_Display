# QRCode_Display

LilyGO T-Display-S3 화면에 문자열을 QR 코드로 그려 주는 PlatformIO 예제

## 개요

TFT_eSPI 기반 QR 코드 라이브러리(QRcode_eSPI)를 사용해, 코드에 넣어 둔 문자열을 QR 코드로 만들어 보드 내장 화면에 한 번 표시합니다. 문자열을 일반 텍스트, URL, Wi-Fi 접속 정보 형식으로 바꿔 넣을 수 있도록 예시가 주석으로 남아 있습니다. 작성 시기는 2024년 10월입니다(커밋 기록 기준).

## 하드웨어

- 보드: LilyGO T-Display-S3 (`board = lilygo-t-display-s3`, ESP32-S3, 화면 내장)
- 출력: 보드 내장 TFT 화면
- 외부 배선 없음

## 동작 방식

1. `setup()`
   - `display.begin()`으로 화면을 초기화하고 `qrcode.init()`으로 QR 코드 출력기를 준비합니다.
   - `msg` 문자열로 `qrcode.create(msg)`를 호출해 QR 코드를 화면에 그립니다.
2. `loop()`: 비어 있습니다. 화면은 처음 그린 상태로 유지됩니다.

`msg`에 넣을 수 있는 형식(코드 주석의 예시 기준):

| 용도 | 형식 |
|------|------|
| 텍스트 | `Hello World!` |
| URL | `https://google.com/` |
| Wi-Fi (암호 없음) | `WIFI:S:<SSID>;;;;` |
| Wi-Fi (암호 있음) | `WIFI:S:<SSID>;T:<암호 방식>;P:<비밀번호>;;` |

## 개발 환경

| 항목 | 값 |
|------|----|
| 도구 | PlatformIO |
| 플랫폼 | `espressif32` |
| 프레임워크 | `arduino` |
| 빌드 플래그 | `-DARDUINO_USB_CDC_ON_BOOT=1` |
| 라이브러리 | `bodmer/TFT_eSPI @ ^2.5.22`, `yoprogramo/QRcodeDisplay @ ^2.1.0`, `yoprogramo/QRcode_eSPI @ ^2.0.0` |
| 모니터 속도 | `monitor_speed = 115200` (코드에서 시리얼은 사용하지 않음) |

## 빌드 및 업로드

1. `src/main.cpp`의 `msg` 값을 원하는 문자열로 바꿉니다. Wi-Fi 형식을 쓸 때는 SSID와 비밀번호를 본인 환경에 맞게 넣습니다.
2. 빌드 후 업로드합니다.

```bash
pio run -t upload
```

## 폴더 구조

```
QRCode_Display/
├── platformio.ini
└── src/
    └── main.cpp
```

## 참고

- QR 코드는 `setup()`에서 한 번만 만들기 때문에, 내용을 바꾸려면 코드를 고쳐 다시 업로드해야 합니다.
- TFT_eSPI의 T-Display-S3용 화면 설정은 이 저장소에 포함되어 있지 않습니다.
