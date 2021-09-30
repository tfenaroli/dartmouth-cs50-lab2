## testing script

# basic test
./histo < testfile1.txt

# test with binRange expansion
./histo < testfile2.txt

# test with large binRange expansion
./histo < testfile3.txt

# test with large amount of data
echo {1..30} 500 | ./histo
