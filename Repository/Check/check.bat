@echo off
cd %~dp0
echo Compiling...
g++ data.cpp -o data -w -std=c++17 -O2
g++ wa.cpp -o wa -w -std=c++17 -O2
g++ std.cpp -o std -w -std=c++17 -O2
echo Compiled!
for /l %%a in (1,1,100000) do (
	echo %%a
	data.exe > in.txt
	wa.exe < in.txt > out.txt
	std.exe < in.txt > ans.txt
	fc out.txt ans.txt
	if errorlevel 1 (exit)
)