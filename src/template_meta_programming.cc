#include <iostream>

template<int toCube>
struct Cube {
  enum {
    value =  toCube * toCube * toCube
  }; 
};


// factorial
template<const int input, const int sum = 1>
struct Factorial : Factorial<input - 1, sum * input> {};

template<int sum>
struct Factorial<1, sum> {
  enum value {
    value = sum
  };
}; 

int main() {
  std::cout << "Cube of 5: " << Cube<5>::value << std::endl;
  std::cout << "Factorial of 5: " << Factorial<5>::value << ::std::endl; 
}
