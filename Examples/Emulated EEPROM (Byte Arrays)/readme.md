# Attention!
When writing and reading arrays in the Emulated EEPROM, there are a few warnings to consider:
  * After using the "Get_Value_Array" function, the result will be in "Little Endian", meaning that the Least Significant Bytes are stored first.
    * e.g. Writing an array of [0x0A, 0x05, 0x03, 0x00] to the memory address '0' will result in a value stored as decimal 197898, or 0x0003050A.
  * Despite that, accessing each memory address independently will yield the values in "Big Endian".
    * e.g. Writing the same array above will yield at addresses 0, 1, 2, 3, respectively and in decimal notation: 10, 05, 03, 00.
  * We have provided a few macros to convert integers to and from a byte array, in the macros.h header file.
  * There are two methods of writing, one involving a conversion beforehand. Both are exemplified.
