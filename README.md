# Battery Meter

Measure the current from a lithium polymer battery through the typical 2-pin JST-PH connectors

![setup](setup.jpg)

### Components

- [Adafruit Feather STM32F405 Express](https://www.adafruit.com/product/4382)
- [INA219 High Side DC Current Sensor Breakout](https://www.adafruit.com/product/904)

### Build

```bash
pio run -t upload  # while B0 connected to 3.3V
```

### Run

```bash
screen -L /dev/tty.usbmodem207138A832521 115200  # or similar device
```

### Output

```bash
cat screenlog.0
[...]
66661, 1.1
66762, 1.2
[Button press]
Time (ms), Current (mA)
1, 1.2
102, 1.2
203, 1.2
304, 1.2
405, 1.2
[...]
49390, 125.2
49491, 53.1
49592, 137.4
49693, 53.3
```
