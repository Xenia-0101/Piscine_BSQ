#!/bin/sh
chmod +x  ./map_generator.pl

# ./map_generator.pl 40 20 5 > tests/t1.txt
# ./map_generator.pl 100 40 5 > tests/t2.txt
# ./map_generator.pl 1000 1000 50 > tests/t3.txt
./map_generator.pl 5000 2500 500 > tests/t4.txt
# ./map_generator.pl 10 10 5 > tests/t5.txt
# ./map_generator.pl 10 10 2 > tests/t6.txt
# ./map_generator.pl 10 10 4 > tests/t7.txt
