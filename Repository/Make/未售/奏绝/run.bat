echo off
g++ data1.cpp -o data1
g++ data2.cpp -o data2
g++ std.cpp -o std
for /l %%a in (1, 1, 8) do (
	echo %%a
	g++ data1.cpp -o data1
	data1.exe > %%a.in
	std.exe < %%a.in > %%a.out
)
for /l %%a in (9, 1, 10) do (
	echo %%a
	g++ data2.cpp -o data2
	data2.exe > %%a.in
	std.exe < %%a.in > %%a.out
)