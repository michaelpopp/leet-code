#include <iostream>
#include <vector>
#include <map>

// time complexity, space complexity - O(n), O(n) 
int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize){

    std::multimap<int,int, std::greater<int>> map_boxTypes;
    int const size = boxTypes.size();
    int spaceLeft = truckSize;
    int units = 0;

    // convert vector into map key - units per box, value - box count
    for(int i = 0; i < size; i++){
        auto temp = boxTypes[i];
        auto pair = std::make_pair(temp[1], temp[0]);
        map_boxTypes.insert(pair);
    }

    for(auto it = map_boxTypes.begin(); it != map_boxTypes.end(); ++it){
        
        // box count & units per box
        int UPB = it->first;
        int BC = it->second;
        if(spaceLeft == 0){return units;}
        if(BC > spaceLeft){units += (spaceLeft*UPB); return units;}
        else {units += (BC * UPB); spaceLeft -= BC;}
    }
    return units;
}

int main(int argc, char* argv[]){

    std::vector<int> i = {5,10};
    std::vector<int> j = {2,5};
    std::vector<int> k = {4,7};
    std::vector<int> l = {3,9};
    std::vector<std::vector<int>> boxTypes = {i, j, k, l};

    std::cout << maximumUnits(boxTypes, 10) << "\n";

    return 0;
}
