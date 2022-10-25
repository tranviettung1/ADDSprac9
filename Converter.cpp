#include "Converter.h"
#include <string>
#include <stack>
#include <cctype>
#include <iostream>

using namespace std;

bool Converter::isOperator(char op) {
    switch(op) {
        case '+':
        case '-':
        case '*':
        case '/':
          return true;
    }
    return false;
}

bool Converter::isValid(string prefixStr) {
    int countOperator = 0;
    int countNumber = 0;
    string number = "";
    bool prevNumber =  false;

    for (int i = 0; i < prefixStr.size(); i++) {
        if (!isOperator(prefixStr[i]) && !isdigit(prefixStr[i]) && prefixStr[i] != ' ') return false;
        if (isOperator(prefixStr[i])) countOperator++;
        else if (prefixStr[i] == ' ' && prevNumber) {
            if (stoi(number) > 99) return false;
            countNumber++;
            prevNumber = false;
            number = "";
        } 
        else if (isdigit(prefixStr[i])) {
            number += prefixStr[i];
            prevNumber = true;
        }
    }

    if (prevNumber) countNumber++;
    if (countNumber - countOperator != 1) return false;
    return true;
}

int Converter::opCalculator(int a, int b, char op) {
    switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}

int Converter::prefixCalculator(string prefixStr) {
    if (prefixStr.size() < 2) return stoi(prefixStr);

    stack<int> s;
    int len = prefixStr.size();
    string number = "";
    bool prevNumber = false;

    for (int i = len-1; i >= 0; i--) {
        if (isOperator(prefixStr[i])) {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            int temp = opCalculator(op1, op2, prefixStr[i]);
            s.push(temp);
        } else if (prefixStr[i] == ' ' && prevNumber){
            int temp = stoi(number);
            s.push(temp);
            number = "";
            prevNumber = false;
        } else if (isdigit(prefixStr[i])) {
            number = prefixStr[i] + number;
            prevNumber = true;
        }
    }

    return s.top();
}

string Converter::prefixToInfix(string prefixStr) {
    if (prefixStr.size() < 2) return prefixStr;

    stack<string> s;
    int len = prefixStr.size();
    string number = "";
    bool prevNumber = false;

    for (int i = len-1; i >= 0; i--) {
        if (isOperator(prefixStr[i])) {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = "(" + op1 + " " + prefixStr[i] + " " + op2 + ")";
            if (i == 0 || prefixStr[i] == '*' || prefixStr[i] == '/') temp =  op1 + " " + prefixStr[i] + " " + op2;
            s.push(temp);
        } else if (prefixStr[i] == ' ' && prevNumber) {
            s.push(number);
            number = "";
            prevNumber = false;
        } else if (isdigit(prefixStr[i])) {
            number = prefixStr[i] + number;
            prevNumber = true;
        }
    }

    return s.top();
}