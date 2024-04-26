@echo off
cd %~dp0
echo Compiling...
g++ data.cpp -o data -w -std=c++20 -O2
g++ std.cpp -o std -w -std=c++20 -O2
echo Compiled!
for /l %%a in (1,1,100000) do (
	echo %%a
	data%%a.exe > %%a.in
	std.exe < %%a.in > %%a.out
)