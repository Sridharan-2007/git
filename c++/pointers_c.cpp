//using destructors
#include <iostream>
using namespace std;
class MyClass {
public:
    static int add(int a, int b) {
        return a + b;
    }
};
int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    int result = MyClass::add(num1, num2);
    cout << "The sum of " << num1 << " and " << num2 << " is: " << result << endl;
    return 0;
}