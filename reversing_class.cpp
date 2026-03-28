//reversing a number using class
#include <iostream>
using namespace std;

class Reverse {
    private:
        int num;
    public:
        void getInput() {
            cout << "Enter a number: ";
            cin >> num;
        }
        void displayReverse() {
            int reversed = 0;
            int original = num;
            while (num > 0) {
                int digit = num % 10;
                reversed = reversed * 10 + digit;
                num /= 10;
            }
            cout << "Reversed number of " << original << " is " << reversed << endl;
        }
};

int main() {
    Reverse r;
    r.getInput();
    r.displayReverse();
    return 0;
}