#include <iostream>
#include <vector>
int removeDuplicates(std::vector<int>& nums){
    
    if(nums.empty()){return 0;}

    for (auto i = nums.begin() + 1; i != nums.end(); i++){
        if(*i == *(i - 1)){
            nums.erase(i); 
            i--;
            continue;
        }
    }

    return nums.size();
}


int main(int argc, char *argv[]){

    std::vector<int> testCase = {0,0,1,1,1,2,2,3,3,4};

    auto result = removeDuplicates(testCase);

    std::cout << result << ": ";
    for (const auto& i : testCase){std::cout << i;}
    std:: cout << std::endl;

    return 0;
}
