contains
- a solution file -> "maxflow.cpp" ,
- the header file used -> "maxflow.h"
- the program to run your functions -> "main.cpp"
- an example makefile to compile the code -> "Makefile".

test_inputs folder contains the input files.

test_outputs folder contains the corresponding outputs.

To compile your code you should replace the empty maxflow.cpp file with your
solution. The following command is used to compile your solutions:

g++ maxflow.cpp main.cpp -std=c++11 -o main

After compiling your code with the given main.cpp file you can direct an input
file to stdin when running the program and the output will be printed on stdout. 

Ex: ./main < test_inputs/inp1.txt
