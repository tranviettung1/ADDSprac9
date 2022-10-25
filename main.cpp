#include "Converter.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    Converter * convert = new Converter();
    string expression;
    getline(cin, expression);

    if (convert->isValid(expression)) {
        cout << convert -> prefixToInfix(expression) << " = ";
        cout << convert -> prefixCalculator(expression) << endl;
    } else {
        cout << "Error" << endl;
    }
}