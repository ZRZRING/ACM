@echo off
cd %~dp0
g++ wa.cpp -o wa -w -std=c++20 -O2
wa.exe < in.txt > out.txt
fc out.txt ans.txt