#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

#include "catch.hpp"

auto isGreaterThan(int first_num, int second_num) {
    return first_num >= second_num;
}

int main(int argc, char * argv[]) {
    auto render = [](auto collection) {
        for (const auto &val:collection) {
	    std::cout << val << std::endl;
	}
    };

    // transform() for map 
    std::vector<int> inCollection{1, 2, 3, 4, 5};
    std::vector<int> outCollection {};

    std::transform(inCollection.begin(), inCollection.end(),
            std::back_inserter(outCollection), [](const int &value) {return value * 3;});
  
    std::cout << "Transform" << std::endl;

    render(outCollection);

    // copy_if() for filter
    std::vector<int> filterCollection {};

    std::copy_if(inCollection.begin(), inCollection.end(),
	    std::back_inserter(filterCollection), [](const int &value) { return value %2 != 0;});

    std::cout << "copy_if" << std::endl;
    render(filterCollection);

    // accumulate() for reduce
    int accumulateResult = std::accumulate(inCollection.begin(), inCollection.end(), 0);
    std::cout << "accumulate " << accumulateResult << std::endl;

    // use std::bind() for filter numbers over 21 in a container
//    auto isGreaterThan(int first_num, int second_num) { return first_num >= second_num; }
    std::vector<int> inAgeGroup{12, 32, 43, 18, 39, 40};
    std::vector<int> outAgeGroup;

    std::copy_if(inAgeGroup.begin(), inAgeGroup.end(), std::back_inserter(outAgeGroup),
        std::bind(&isGreaterThan, std::placeholders::_1, 21));
    std::cout << "Greater than 21" << std::endl;
    render(outAgeGroup);
    
    return 0;
}
