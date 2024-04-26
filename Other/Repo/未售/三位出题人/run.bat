echo off
g++ std.cpp -o std -std=c++11 -O2
for /l %%a in (1, 1, 6) do (
	echo %%a
	std.exe < sub%%a-1.in > sub%%a-1.out
)