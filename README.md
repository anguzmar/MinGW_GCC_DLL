# What is This Project?
This is a small project I made in order to learn the following things:
  * How to make and compile a DLL using MinGW GCC.
  * How to use the Windows Crypto API (CNG).
  * Makefiles. I knew what they were but I never made one myself.
  * Windows development.

Note that I am pretty much clueless about good practices.

# Usage
1. Clone this repository and navigate into its folder.
2. Compile the code:

```powershell
make
make clean
```

3. Run the executable: `.\test_dll.exe`.

If everything went correctly, you should obtain a fairly large random number.

# References
Main resources I used for this project:
  * For making the DLL: https://www.transmissionzero.co.uk/computing/building-dlls-with-mingw/
  * CNG: https://docs.microsoft.com/en-us/windows/win32/seccng/cng-cryptographic-primitive-functions
