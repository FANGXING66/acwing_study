#include <iostream>  
#include <algorithm>  
#include <unordered_map>  
#include <stack>  

using namespace std;  
#define int long long  

stack<int> num;  
stack<char> op;  

void eval() {  
    auto a = num.top(); num.pop();  
    auto b = num.top(); num.pop();  
    auto c = op.top(); op.pop();  

    if (c == '+') num.push(b + a);  
    else if (c == '-') num.push(b - a);  
    else if (c == '*') num.push(a * b);  
    else num.push(b / a);
}

signed main() {  
    unordered_map<char, int> df = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};  
    string str; cin >> str;  

    for (int i = 0; i < str.size(); i++) {  
        auto c = str[i];  
        
        if (isdigit(c)) {  
            int j = i;  
            int x = 0;  
            while (j < str.size() && isdigit(str[j])) {  
                x = x * 10 + str[j] - '0';  
                j++;  
            }  
            i = j - 1;  
            num.push(x);  
        } else if (c == '(') {  
            op.push(c);  
        } else if (c == ')') {  
            while (!op.empty() && op.top() != '(') eval();  
            if (!op.empty()) op.pop(); 
        } else {  
            while (!op.empty() && df[c] <= df[op.top()]) eval();  
            op.push(c);  
        }  
    }  

    while (!op.empty()) eval();  
    cout << num.top() << "\n";  

    return 0;  
}