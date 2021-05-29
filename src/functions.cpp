// compile this file with the following command:
// $ g++ function.cpp --std=c++17 -o function.o

#include <iostream>
#include <functional>
#include <vector>
#include <string>

void anonymousFunc() { std::cout << "anonymousFunc()" << std::endl; }
void binaryFunc(int a, int b) { std::cout << "binaryFunc() " << a + b << std::endl; }

class Functor {
public:
    void operator ()() const {
	std::cout << "Functor() " << std::endl;
    }
};

int main() {
    std::vector<std::function<void()>> funcs;
    funcs.push_back(anonymousFunc);

    Functor func_ins;
    funcs.push_back(func_ins);
    funcs.push_back([](){std::cout << "Pushed back anonymous func" << std::endl;});
    // we cannot use std::placeholders::_1 and std::placeholders::_2 here - why?
    funcs.push_back(std::bind(&binaryFunc, 1, 1));

    for (auto const & f : funcs) {
        f();
    }
    return 0;
}


