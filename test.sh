#!/bin/bash.sh

#NAME: Forrest Burton
#EMAIL: burton.forrest10@gmail.com
#ID: 005324612

CHECK_VAR=100

./lab0 --ssss
if [[ $? -eq 1 ]] 
then
    echo "Incorrect option input succesful. Test Passed"
else 
    echo "Incorrect option input failed. Should return 1"
    CHECK_VAR=-1
fi  

touch random_input.txt
touch random_outout.txt
./lab0 --input=random_input.txt --output=random_output.txt
if [[ $? -eq 0 ]]
then 
    echo "Copy succesful. Test Passed"
else
    echo "Copy unsuccesful. Should return 0"
    CHECK_VAR=-1
fi

./lab0 --segfault --catch
if [[ $? -eq 4 ]]
then 
    echo "Segfault caught. Test Passed"
else
    echo "Segfault not caught. Should return 4"
    CHECK_VAR=-1
fi

touch failure.txt
chmod -r failure.txt
./lab0 --input=failure.txt
if [[ $? -eq 2 ]]
then
    echo "Input failure correct output. Test Passed"
else
    echo "Input failure incorrect output. Should return 2"
    CHECK_VAR=-1
fi

./lab0 --input=non_existant_file_asdfasf.txt
if [[ $? -eq 2 ]]
then
    echo "Input failure correct output. Test Passed"
else
    echo "Input failure incorrect output. Should return 2"
    CHECK_VAR=-1
fi

if [ $CHECK_VAR -eq -1 ]
then 
    echo "Tests Failed"
else
    echo "Tests Passed"
fi

