if not exist build mkdir build
cd build
cmake -S ../ -B . -G "MinGW Makefiles"
mingw32-make.exe  &:: mingw32-make.exe Shaders
:: remember to append && mingw32-make.exe SHADERS once shaders need to be built