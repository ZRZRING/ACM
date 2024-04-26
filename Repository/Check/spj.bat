@echo off
echo 1
g++ data.cpp -o data -w -Wl,--stack=19198101 -std=c++17 -O2
g++ wa.cpp -o wa -w -Wl,--stack=19198101 -std=c++17 -O2
g++ std.cpp -o std -w -Wl,--stack=19198101 -std=c++17 -O2
data.exe > data.txt
wa.exe < data.txt > wa.txt
std.exe < data.txt > std.txt
fc wa.txt std.txt
if errorlevel 1 pause
for /l %%a in (2,1,100000) do (
	echo %%a
	data.exe > data.txt
	wa.exe < data.txt > wa.txt
	std.exe < wa.txt > std.txt
	fc wa.txt std.txt
	if errorlevel 1 pause
)
:ed