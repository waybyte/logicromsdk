# Logicrom SDK for Wireless IoT

Software development kit for Logicrom Platform

[![Documentation Status](https://readthedocs.org/projects/logicromsdk/badge/?version=latest)](https://docs.logicrom.com)
[![Github Issues](https://img.shields.io/github/issues/waybyte/logicromsdk.svg)](http://github.com/waybyte/logicromsdk/issues)
[![Github Releases](https://img.shields.io/github/release/waybyte/logicromsdk.svg)](https://github.com/waybyte/logicromsdk/releases)


## Installation Guide
 - [PlatformIO IDE](https://github.com/waybyte/logicromsdk/blob/master/docs/book/quick_start.rst#platformio-ide)
 - [Arduino IDE](https://github.com/waybyte/logicromsdk/blob/master/docs/book/quick_start.rst#arduino-ide)

## Resources

* [Documentation](https://docs.logicrom.com) - Logicrom SDK documentation for latest version

# Supported Modules
## 4G LTE Cat.1 Modules

| Module Name  | Networking | BLE[^1] | GPS | GPIO | ADC | I2C | SPI | USB | LCD | Camera |
|--------------|------------|---------|-----|------|-----|-----|-----|-----|-----|--------|
| Neoway N58  | &check; | &check; | &check; | &check; | &check; | &check; | &check; | &check; | &check; | &cross; |
| Neoway N716 | &check; | &check; | &#8212; | &check; | &check; | &check; | &check; | &check; | &check; | &cross; |
| Quectel EC200U | &check; | &check; | &check; | &check; | &check; | &check; | &check; | &check; | &check; | &cross; |
| Quectel EC600U | &check; | &check; | &#8212; | &check; | &check; | &check; | &check; | &check; | &check; | &cross; |
| Quectel EG915U  | &check; | &check; | &#8212; | &check; | &check; | &check; | &check; | &check; | &check; | &cross; |
| Fibocom L610  | &check; | &check; | &#8212; | &check; | &check; | &check; | &check; | &check; | &check; | &cross; |

DFOTA is also supported for LTE modules

## NB-IoT Modules[^2]

| Module Name  | Networking | GPS | GPIO | ADC | I2C | SPI | USB |
|--------------|------------|-----|------|-----|-----|-----|-----|
| Quectel BC66 | &check; | &#8212; | &check; | &check; | &check; | &check; | &check; |
| Quectel BC20 | &check; | &check; | &check; | &check; | &check; | &check; | &check; |

## GSM Modules

| Module Name  | Networking | BT | GPS | GPIO | ADC | I2C | SPI | USB | LCD[^3] |
|--------------|------------|----|-----|------|-----|-----|-----|-----|---------|
| Quectel M66  | &check; | &check; | &#8212; | &check; | &check; | &check; | &check; | &#8212; | &cross; |
| Quectel M66DS| &check; | &check; | &#8212; | &check; | &check; | &check; | &check; | &#8212; | &cross; |
| Quectel MC60 | &check; | &check; | &check; | &check; | &check; | &check; | &check; | &#8212; | &cross; |
| Quectel MC20 | &check; | &check; | &check; | &check; | &check; | &check; | &check; | &#8212; | &cross; |
| Quectel M56| &check; | &check; | &#8212; | &check; | &check; | &check; | &check; | &check; | &cross; |
| Quectel MC20U| &check; | &check; | &check; | &check; | &check; | &check; | &check; | &check; | &cross; |
| SIMCOM SIM868[^4]| &check; | &check; | &check; | &check; | &check; | &check; | &check; | &check; | &cross; |


[^1]: Currely only GATT Server supported and used for console purpose only.

[^2]: Updates to come

[^3]: LCD is work in progress.

[^4]: Please backup calibration during first flash via Maui Meta tool (google is your friend).
