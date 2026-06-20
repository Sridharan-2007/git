
#include <iostream>
using namespace std;
class Factorial {
    public:
        unsigned long long calculate(int n) {
            if (n < 0) {
                cout << "Factorial is not defined for negative numbers." << endl;       
                return 0;
            }
            unsigned long long result = 1;
            for (int i = 1; i <= n; ++i) {
                result *= i;
            }
            return result;
        }
};
int main() {
    Factorial factorial;
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;
    unsigned long long result = factorial.calculate(number);
    if (result != 0) {
        cout << "The factorial of " << number << " is: " << result << endl;
    }
    return 0;
}