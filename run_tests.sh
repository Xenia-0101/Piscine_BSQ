
#!/bin/bash

rm -f bsq
clear

make

echo ./checker1.txt
./bsq tests/checker1.txt
echo ./checker2.txt
./bsq tests/checker2.txt
echo ./error1.txt
./bsq ./error1.txt
echo ./error2.txt
./bsq tests/error2.txt
echo ./error3.txt
./bsq tests/error3.txt
echo ./error4.txt
./bsq tests/error4.txt
echo ./exxtralarge.txt
./bsq tests/exxtralarge.txt
echo ./large.txt
./bsq tests/large.txt
echo ./middle.txt
./bsq tests/middle.txt
echo ./onefree.txt
./bsq tests/onefree.txt
echo ./onefull.txt
./bsq tests/onefull.txt
echo ./onethousand.txt
./bsq tests/onethousand.txt
echo ./onetwothree.txt
./bsq tests/onetwothree.txt

