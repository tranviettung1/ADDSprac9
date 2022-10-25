#ifndef CONVERTER
#define CONVERTER

#include <string>

using namespace std;

class Converter {
    public:
        bool isOperator(char op);
        bool isValid(string prefixStr);
        int opCalculator(int a, int b, char op);
        int prefixCalculator(string prefixStr);
        string prefixToInfix(string prefixStr);
};

#endif