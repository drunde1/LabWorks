#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cmath>
#include <functional>
#include <map>
using namespace std;

const map<char, pair<int, std::function<float(float, float)>>> OPERATORS = {
    {'+', {1, [](float a, float b){ return a + b; }}},
    {'-', {1, [](float a, float b){ return a - b; }}},
    {'*', {2, [](float a, float b){ return a * b; }}},
    {'/', {2, [](float a, float b){ return a / b; }}},
    {'^', {3, [](float a, float b){ return pow(a, b); }}}
};

float eval_(string formula_string){
    stringstream ss(formula_string);

    string token;
    stack<string> op_stack;
    while (ss >> token) {
        if (token == "(") {
            op_stack.push(token);
        }
        else if (token == ")") {
            while (op_stack.top() != "(") {
                float y = stof(op_stack.top());
                op_stack.pop();
                float x = stof(op_stack.top());
                op_stack.pop();
                char op = op_stack.top()[0];
                op_stack.pop();
                float res = OPERATORS.at(op).second(x, y);
                op_stack.push(to_string(res));
            }
            op_stack.pop();
        }
        else if (OPERATORS.count(token[0])) {
            while (!op_stack.empty() && op_stack.top() != "(" && OPERATORS.at(token[0]).first <= OPERATORS.at(op_stack.top()[0]).first) {
                float y = stof(op_stack.top());
                op_stack.pop();
                float x = stof(op_stack.top());
                op_stack.pop();
                char op = op_stack.top()[0];
                op_stack.pop();
                float res = OPERATORS.at(op).second(x, y);
                op_stack.push(to_string(res));
            }
            op_stack.push(token);
        }
        else {
            op_stack.push(token);
        }
    }

    while (!op_stack.empty() && op_stack.top() != "(") {
        float y = stof(op_stack.top());
        op_stack.pop();
        float x = stof(op_stack.top());
        op_stack.pop();
        char op = op_stack.top()[0];
        op_stack.pop();
        float res = OPERATORS.at(op).second(x, y);
        op_stack.push(to_string(res));
    }

    return stof(op_stack.top());
}

int main() {
    string str = "1 + 1";
    cout << stoi(str) << endl;  // should output 7
    return 0;
}