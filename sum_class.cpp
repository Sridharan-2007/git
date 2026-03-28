// This class provides a method to calculate the sum of two numbers
class Sum {
public:
    int calculate(int a, int b) {
        return a + b;
    }
};
#include <iostream>

int main() {
    Sum sum;                
    int num1, num2;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    int result = sum.calculate(num1, num2);
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << result << std::endl;
    return 0;
}   
