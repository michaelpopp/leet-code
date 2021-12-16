#include <iostream>
#include <cstdint>

int hammingWeight(uint32_t n){ 
    
    int count = 0;
    while(n > 0){
        // checks least significant bit for 1
        count += n & 1;
        n = n >> 1;
    }
    return count;
}

int main(int argc, char* argv[]){

    uint32_t n = 00000000000000000000000000001011;
    std::cout << hammingWeight(n) << std::endl;
    return 0;
}
