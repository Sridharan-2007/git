//Program to Count Digits of a Number Using Class
#include <iostream>
using namespace std;
class DigitCounter {
    public:
        int countDigits(int number) {
            if (number == 0) {  
                return 1;  
            }
            int count = 0;
            number = abs(number);
            while (number > 0) {
                number /= 10;
                count++;
            }
            return count;
        }
};
int main() {
    DigitCounter digitCounter;
    int number;
    cout << "Enter an integer: ";
    cin >> number;  
    int result = digitCounter.countDigits(number);
    cout << "The number of digits in " << number << " is: " << result << endl;
    return 0;
}