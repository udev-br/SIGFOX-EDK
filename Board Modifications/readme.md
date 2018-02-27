# Board Modifications

In this section, you'll find schematics of which components need to be present for certain configurations of the EDK to work.

<br>__For example__, by default the EDK Analog Input works with a 4-20mA current loop, allowing for a wide possibility of applications.
<br>If one wishes to use the DS18B20 (One-Wire) temperature sensor, a few resistors need to be changed.

In the files on this folder, you'll find a schematic file ("EDK-schematic-adc.png") that shows the position of each resistor on the EDK board.
<br>Alongside it, there are electrical diagrams of two configurations of the EDK. If you wish to use the DS18B20 one-wire temperature probe, it is necessary to change a few components. Refer to "EDK-electrical-adc-DS18B20.png".
<br>The default EDK configuration is also in the files for reference, under "EDK-electrical-adc-original.png".