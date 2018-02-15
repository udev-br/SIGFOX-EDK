# Instructions

The instructions are the same for every example: simply download the entire example folder, and open the corresponding .CPROJ file.

After that, add the static library file (__libudev_sigfox_edk.a__) to the /sdk/lib path, and the example will be ready to go!

__Every example is set to start at the 0x6000 memory address, to conform with the presence of the default bootloader.__

---

## Guidelines

These are instructions that work for every example, to avoid repeating the same instruction on each header file.


* __fnUSER_Setup()__: Whatever is within this context will run __once__. Use it for initializing components and setting one-time values.
* __fnUSER_Loop()__: In this context, code will run in an endless loop, continuously. Use it as the  of your application.
* __XXXXX_Measure_Start_Blocking_Mode()__: This function will start a measurement for the sensor, in "blocking mode". This means that the program doesn't execute other tasks while waiting for the measurement to be complete. Once the program steps out of this function, the measurement is complete.
* __XXXXX_Measure_Start_Callback_Mode()__: This function also starts a measurement for the sensor, but in "callback mode". The program continues normally after calling this function, and when the measurement is properly complete, the corresponding _Measure_Done_Callback()_ gets called _automatically_, at the moment of completion. This method doesn't halt the program at all, and you can execute multiple tasks simultaneously.
* __XXXXX_Measure_Done_Callback()__: This function is called _automatically_ after _Start_Callback_Mode()_ is called and completely finishes a measurement. You can implement this function within __user.c__, so whenever it is called, it has the data ready for display or use. (Check the __user.c__ example files for examples of this implementation)
* bool __b_system_low_power_enabled__: This variable should be defined before other variables, after your <i>includes</i> section. It dictates whether the board operates in low-power mode, or in normal-power mode. If the variable is not defined, the default is TRUE, which corresponds to low-power mode. In low-power, the board cannot communicate via USB, so USB serial communication is not an option, and using a serial terminal will not work. To debug via USB, you must set this variable to FALSE.

Whenever possible, the example __user.c__ files will have both methods implemented, but the _blocking_ mode will be commented.
<br>If desired, you can uncomment it and comment the _Callback_ call and implementation. This way the application will work in _blocking_ mode.

<sub>__XXXXX__ is the sensor in question, e.g. __SI1133__ for the light sensor</sub>
