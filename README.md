# 3D_Viewer 
Implementation of our own version of the 3D Viewer.

## Build
### Preparation
   To start build you need to move to `./src` dir.
   ```Bash
   cd ./src
   ```
### Build
* Build program

   ```
   make all
   ```
   or
   ```
   make install
   ```
*  Build and run tests
   ```
   make tests
   ```
*  Generate lib code coverage by tests into `./src/report` dir
   ```
   make gcov_report
   ```
*  Clean project
   ```
   make clean
   ```
*  Unistall Project
   ```
<<<<<<< HEAD
   make unistall
=======
   make uninstall
>>>>>>> e12bc9f4e2e07e14a53e9814c8eaff5644772b75
   ```
*  Open HTML file
   ```
   make dvi
   ```
*  Create archive with program
   ```
   make dist
   ```
