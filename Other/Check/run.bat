g++ wa.cpp -o wa -w -Wl,--stack=19198101 -std=c++11 -O2
wa.exe < data.txt > wa.txt
fc wa.txt std.txt
if errorlevel 1 pause