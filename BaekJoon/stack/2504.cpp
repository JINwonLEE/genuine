#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

using namespace std;

int main() {
    stack<string> stack_input;

    int result = 0;
    string input;
    cin >> input;
    bool wrong = false;

    for (auto& i : input) {
        if (i == '(' || i == '[') {
            stack_input.push(string(1, i));
        } else if (i == ')') {
            if (stack_input.empty()) {
                result = 0;
                break;
            }
            string top = stack_input.top();
            if (top == "(") {
                stack_input.pop();
                stack_input.push("2");
            } else {
                int num = 0;
                while (!stack_input.empty() && stack_input.top() != "(") {
                    try {
                        num += stoi(stack_input.top());
                        stack_input.pop();
                    } catch (...) {
                        wrong = true;
                        num = 0;
                        break;
                    }
                }

                if (wrong || stack_input.empty()) {
                    result = 0;
                    break;
                }

                stack_input.pop();
                num *= 2;
                stack_input.push(to_string(num));
            }
        } else if (i == ']') {
            if (stack_input.empty()) {
                result = 0;
                break;
            }
            string top = stack_input.top();
            if (top == "[") {
                stack_input.pop();
                stack_input.push("3");
            } else {
                int num = 0;
                while (!stack_input.empty() && stack_input.top() != "[") {
                    try {
                        num += stoi(stack_input.top());
                        stack_input.pop();
                    } catch (...) {
                        wrong = true;
                        num = 0;
                        break;
                    }
                }

                if (wrong || stack_input.empty()) {
                    result = 0;
                    break;
                }

                stack_input.pop();
                num *= 3;
                stack_input.push(to_string(num));
            }
        }
    }

    while (!stack_input.empty()) {
        string num = stack_input.top();
        try {
            result += stoi(num);
        } catch (...) {
            result = 0;
            break;
        }
        stack_input.pop();
    }
    cout << result << endl;
    return 0;
}
