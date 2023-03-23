# Logicrom SDK for Wireless IoT

Software development kit for Logicrom Platform

[![PlatformIO Registry](https://badges.registry.platformio.org/packages/waybyte/tool/framework-logicromsdk.svg)](https://registry.platformio.org/tools/waybyte/framework-logicromsdk)
[![Documentation Status](https://readthedocs.org/projects/logicromsdk/badge/?version=latest)](https://docs.logicrom.com)
[![Github Issues](https://img.shields.io/github/issues/waybyte/logicromsdk.svg)](http://github.com/waybyte/logicromsdk/issues)
[![Github Releases](https://img.shields.io/github/release/waybyte/logicromsdk.svg)](https://github.com/waybyte/logicromsdk/releases)


## Installation Guide
 - [PlatformIO IDE](https://docs.logicrom.com/en/latest/book/quick_start/setup_platformio.html)
 - [Arduino IDE](https://docs.logicrom.com/en/latest/book/quick_start/setup_arduino.html)

## Resources

* [Documentation](https://docs.logicrom.com) - Logicrom SDK documentation for latest version
* [SDK Examples](https://docs.logicrom.com/en/latest/book/example.html)

# Supported Modules

| Name              | Vendor   | SoC/Chipset | Supported Peripherals                              | APP RAM / ROM   |
|-------------------|----------|-------------|----------------------------------------------------|-----------------|
| EC200U-XX-YY [^1] | Quectel  | RDA8910     |  UART, USB, SPI, I2C, ADC, LCD, BT [^2], GNSS [^3] | 500 KB / 1 MB   |
| EC600U-XX-YY [^1] | Quectel  | RDA8910     |                                                    | 500 KB / 1 MB   |
| EC600U-XX-YY [^1] | Quectel  | RDA8910     |                                                    | 500 KB / 1 MB   |
| EG915U-XX-YY [^1] | Quectel  | RDA8910     |                                                    | 500 KB / 1 MB   |
| N58-CA            | Neoway   | RDA8910     |                                                    | 500 KB / 1 MB   |
| N716-CA           | Neoway   | RDA8910     |                                                    | 500 KB / 1 MB   |
| EC100N-XX-XX      | Quectel  | ASR1603     |  UART, USB, SPI, I2C, ADC                          | 512 KB / 1 MB   |
| EC200N-CN-AA      | Quectel  | ASR1603     |                                                    | 512 KB / 512 KB |
| EC600N-CN-AA      | Quectel  | ASR1603     |                                                    | 512 KB / 1 MB   |
| EG912Y-EU-YY      | Quectel  | ASR1603     |                                                    | 512 KB / 1 MB   |
| EG915N-EU-YY      | Quectel  | ASR1603     |                                                    | 512 KB / 512 KB |
| EC100Y-CN-YY      | Quectel  | ASR1601     |  UART, USB, SPI, I2C, ADC                          | 512 KB / 512 KB |
| EC100S-CN-YY      | Quectel  | ASR1601     |                                                    | 512 KB / 1 MB   |
| EC600S-CN-YY      | Quectel  | ASR1601     |                                                    | 512 KB / 1 MB   |
| AC7670C           | SIMCOM   | ASR1601     |                                                    | 512 KB / 1 MB   |
| MC20, MC60, MC20U | Quectel  | MT2503      |  UART, USB, SPI, I2C, ADC, GNSS                    | 94 KB / 256 KB  |
| SIM868[^4]        | SIMCOM   | MT2503      |                                                    | 94 KB / 256 KB  |
| M66, M26, M56     | Quectel  | MT6261      |  UART, USB, SPI, I2C, ADC                          | 94 KB / 256 KB  |
| SIM800[^4]        | SIMCOM   | MT6261      |                                                    | 94 KB / 256 KB  |
| MC65              | Quectel  | RDA8955     |  UART, USB, SPI, I2C, ADC, GNSS [^3], LCD          | 1 MB / 576 KB   |
| M590              | Neoway   | RDA8955     |                                                    | 1 MB / 576 KB   |
| A9, A9G           | AiThinker| RDA8955     |                                                    | 1 MB / 576 KB   |

[^1]: XX can be CN/AU/EU, YY can be AA/AB/AC

[^2]: Currely only GATT Server supported and used for console purpose only

[^3]: Supported on module with GNSS

[^4]: IMEI need to be configured when core is flashed for first time, use AT+EGMR=1,7,"imei"

> DFOTA is also supported for LTE modules


# License & Credits

[LittleFS](https://github.com/ARMmbed/littlefs) library written by ARM Limited and released under the [BSD 3-clause license](https://github.com/ARMmbed/littlefs/blob/master/LICENSE.md).

[Int64String](https://github.com/djGrrr/Int64String) library written by djGrrr and released under the [MIT license](https://github.com/djGrrr/Int64String/blob/master/LICENSE).

[PicoHTTPParser](https://github.com/h2o/picohttpparser) library written by Kazuho Oku, Tokuhiro Matsuno, Daisuke Murase, Shigeo Mitsunari and released under the MIT license.

[heatshrink](https://github.com/atomicobject/heatshrink) library written by Scott Vokes and released under the [ISC license](https://github.com/atomicobject/heatshrink/blob/master/LICENSE).

[SimpleKalmanFilter](https://github.com/denyssene/SimpleKalmanFilter) library written by Denys Sene and released under the [MIT license](https://github.com/denyssene/SimpleKalmanFilter/blob/master/LICENSE).

[OneWire](https://github.com/PaulStoffregen/OneWire) library originally written by Jim Studt and later maintained by Paul Stoffregen, is released uder [custom license](https://github.com/PaulStoffregen/OneWire/blob/master/OneWire.cpp).
