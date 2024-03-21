echo off
g++ data.cpp -o data
g++ std1.cpp -o std1
for /l %%a in (15, 1, 20) do (
	echo %%a
	data.exe > %%a.in
	std1.exe < %%a.in > %%a.out
)