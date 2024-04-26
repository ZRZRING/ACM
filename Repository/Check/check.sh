cd $(dirname "$0")
echo Compiling...
g++ data.cpp -o data -std=c++17 -O2
g++ wa.cpp -o wa -std=c++17 -O2
g++ std.cpp -o std -std=c++17 -O2
echo Compiled!
for i in {1..10000}
do
    ./data > in.txt
    ./wa < in.txt > out.txt
    ./std < in.txt > ans.txt
    if diff -q out.txt ans.txt ; then
        printf "Accept in case $i \n"
    else
        printf "Wrong Answer in case $i\n"
        printf "~~~~~~~~~~~~I~N~~~~~~~~~~~\n"
        	cat < in.txt | head -n 10
		printf "~~~~~~~~~~~~OUT~~~~~~~~~~~\n"
			cat < out.txt | head -n 10
		printf "~~~~~~~~~~~~ANS~~~~~~~~~~~\n"
			cat < ans.txt | head -n 10
        exit 0;
    fi
done