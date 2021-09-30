## testing script

# basic test
./words < testfile.txt

# test with testfile.txt
./words testfile.txt

# test with testfile2.txt
./words testfile2.txt

# test with both test files
./words testfile.txt testfile2.txt

# test with special file name
./words - < testfile.txt testfile.txt testfile2.txt

# test with special file name
./words testfile.txt - < testfile.txt testfile2.txt

# test with special file name
./words testfile.txt testfile2.txt - < testfile.txt

# test with nonexistent file name
./words incorrectfilename.txt