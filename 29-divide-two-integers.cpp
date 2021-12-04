/*
 * problem: 29
 * difficulty: medium
 * contributor: michael popp
 * status: in-progress, currently fails overflow test case
 */
#include <iostream>

int divide(int dividend, int divisor) {
    
    int temp = 0;
    int result = 0;
    bool isNegative = false;
    // determines whether output should be positive or false
    if(dividend < 0 || divisor < 0) {isNegative = true;}
    if(dividend < 0 && divisor < 0) {isNegative = false;}

    if (dividend < 0) {dividend = dividend - dividend - dividend;}
    if (divisor < 0) {divisor = divisor - divisor - divisor;}
    
    if (divisor > dividend) {return 0;}
    

    while (temp < dividend) {
        temp = temp + divisor;
        if(temp <= dividend){result++;}
    }

    if(isNegative) {result = result - result - result;}

    return result;
}

int main(int argc, char* argv[]) {

    if(argc != 3) {fprintf(stderr, "USAGE: %s dividend divisor\n", argv[0]); exit(-1);}
    int dividend = std::stoi(argv[1]);
    int divisor = std::stoi(argv[2]);

    int result = divide(dividend, divisor);
    std::cout << result << std::endl;

    return 0;
}
