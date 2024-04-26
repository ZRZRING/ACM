echo off
g++ std.cpp -o std
for /l %%a in (1, 1, 10) do (
	echo %%a
	std.exe < %%a.in > %%a.out
)