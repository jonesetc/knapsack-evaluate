#!/bin/bash

#Print out a little header
echo -e "Kyle Jones\nArchitecture HW #1\n" > report.txt

#I'm already on athena, so run timing.sh
./timing.sh

#I have a key set up for eros, so ssh over there and run timing.sh
ssh eros 'cd arch; ./timing.sh'
