#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
    Node* top;
public:
    Stack() { 
        top = nullptr;
    }

    void push(string val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (!top) return "";
        string val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    string peek() {
        return top ? top->data : "";
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        Node* curr = top;
        cout << "Stack (top to bottom): ";
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

double toDouble(string s) {
    double val = 0, frac = 0, div = 10;
    bool decimal = false, neg = false;
    if (s[0] == '-') { 
        neg = true;
        s = s.substr(1);
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            decimal = true;
            continue;
        }
        if (!decimal)
            val = val * 10 + (s[i] - '0');
        else {
            frac += (s[i] - '0') / div;
            div *= 10;
        }
    }
    return neg ? -(val + frac) : (val + frac);
}

string toString(double num) {
    string res = "";
    int integer = (int)num;
    double frac = num - integer;

    if (num < 0) {
        res += "-";
        integer = -integer;
        frac = -frac;
    }

    string temp = "";
    if (integer == 0) temp = "0";
    while (integer > 0) {
        temp = char((integer % 10) + '0') + temp;
        integer /= 10;
    }
    res += temp;

    if (frac > 0.0001) {
        res += ".";
        for (int i = 0; i < 2; i++) {
            frac *= 10;
            int digit = (int)frac;
            res += char(digit + '0');
            frac -= digit;
        }
    }
    return res;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    string num = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (ch == ' ') continue;

        if ((ch >= '0' && ch <= '9') || ch == '.') {
            num += ch;
        } else {
            if (num != "") {
                postfix += num + " ";
                num = "";
            }

            if (ch == '(') {
                s.push("(");
            } else if (ch == ')') {
                while (!s.isEmpty() && s.peek() != "(") {
                    postfix += s.pop() + " ";
                }
                s.pop();
            } else {
                while (!s.isEmpty() && precedence(s.peek()[0]) >= precedence(ch)) {
                    postfix += s.pop() + " ";
                }
                string op(1, ch);
                s.push(op);
            }
        }
    }
    if (num != "") postfix += num + " ";

    while (!s.isEmpty()) {
        postfix += s.pop() + " ";
    }

    return postfix;
}

double evaluatePostfix(string postfix) {
    Stack valStack;
    string token = "";

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (ch == ' ') {
            if (token != "") {
                valStack.push(token);
                token = "";
            }
        } else if (isOperator(ch)) {
            double b = toDouble(valStack.pop());
            double a = toDouble(valStack.pop());
            double res = 0;
            if (ch == '+') res = a + b;
            else if (ch == '-') res = a - b;
            else if (ch == '*') res = a * b;
            else if (ch == '/') res = a / b;
            valStack.push(toString(res));
        } else {
            token += ch;
        }
    }

    return toDouble(valStack.pop());
}

int main() {
    Stack s;
    string expr = "12+13-5*(0.5+0.5)+1";

    s.push("=");
    s.push("x");
    s.push(expr);

    cout << "Initial Stack:\n";
    s.display();

    string postfix = infixToPostfix(expr);
    double result = evaluatePostfix(postfix);

    s.pop();
    s.push(toString(result));

    cout << "\nFinal Stack After Evaluation:\n";
    s.display();

    cout << "\nResult of expression: " << result << endl;
    return 0;
}
