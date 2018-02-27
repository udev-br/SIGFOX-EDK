# Board Modifications

In this section, you'll find schematics of which components need to be present for certain configurations of the EDK to work.

<br>__For example__, by default the EDK Analog Input works with a 4-20mA current loop, allowing for a wide possibility of applications.
<br>If one wishes to use the DS18B20 (One-Wire) temperature sensor, a few resistors need to be changed.

In this folder's files, you'll find three images:
* __EDK-schematic-adc.png__ , a schematic file that shows the position of each resistor on the EDK board.
* __EDK-electrical-adc-DS18B20.png__ , an electrical diagram showing how the components should be to allow use of the DS18B20 one-wire temperature probe
* __EDK-electrical-adc-original.png__ , an electrical diagram showing the default EDK configuration