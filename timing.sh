#!/bin/bash

echo "################################################" >> report.txt

#First print the name of the server
echo "Server: $HOSTNAME" >> report.txt

#The CPU speed
cat /proc/cpuinfo | grep "MHz" | head -1 >> report.txt

#The OS and kernel version
echo -n "Kernel version and OS: " >> report.txt
uname -or >> report.txt

#The gcc version and compilation command
echo -n "gcc version info: " >> report.txt
gcc --version | head -1>> report.txt
echo "Compilation command: g++ -O3 -Wall -pedantic -o knapsack knapsack.cpp" >> report.txt

#Number of users logged in
echo -n "Users currently logged in: " >> report.txt
who | wc -l >> report.txt

#Now we need to run the program five times and catch the times in a file
g++ -O3 -Wall -pedantic -o knapsack knapsack.cpp

for i in {1..5}; do
    /usr/bin/time -o times.txt -a -f "%e %U %S" ./knapsack input.txt > /dev/null
done

./stats times.txt
rm times.txt
