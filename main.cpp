#include <iostream>
#include "BigReal.h"
using namespace std;

int main() {
    string input1, input2;
    cout << "Enter the first number: ";
    cin >> input1;
    cout << "Enter the second number: ";
    cin >> input2;

    BigReal real1(input1);
    BigReal real2(input2);

    char ope;
    cout << "Enter the desired operation, type a for addition, s for subtraction: ";
    cin >> ope;

    if (ope == 'a') {
        BigReal sum = real1 + real2;
        cout << "Sum: " << sum.toString() << endl;
    } else if (ope == 's') {
        BigReal difference = real1 - real2;
        cout << "Difference: " << difference.toString() << endl;
    }
    return 0;
}