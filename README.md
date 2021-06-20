# Battery Meter

- [Adafruit Feather STM32F405 Express](https://www.adafruit.com/product/4382)
- [INA219 High Side DC Current Sensor Breakout](https://www.adafruit.com/product/904)

```bash
pio run -t upload --upload-port=/dev/cu.URT1

screen -L /dev/tty.usbmodem207138A832521 115200
```

```bash
Time (ms), Current (mA)
1, 1.2
102, 1.2
203, 1.2
304, 1.2
405, 1.2
(...)
49390, 125.2
49491, 53.1
49592, 137.4
49693, 53.3
```

![setup](setup.jpg)
