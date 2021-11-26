/*
 * problem: 29
 * difficulty: medium
 * contributor: michael popp
 * status: in-progress
 */
#include <iostream>

int divide(int dividend, int divisor){
    
    int result = 0;
    return result;
}

int main(int argc, char* argv[]){

    if(argc != 3) {fprintf(stderr, "USAGE: %s dividend divisor\n", argv[0]); exit(-1);}
    int dividend = std::stoi(argv[1]);
    int divisor = std::stoi(argv[2]);

    int result = divide(dividend, divisor);
    std::cout << result << std::endl;

    return 0;
}
