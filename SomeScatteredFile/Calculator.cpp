#include <iostream>
#include <stack>
using namespace std;

// Translate the input into reverse-polish.
string process(const string & input){
    string rvs;
    stack<char> optor;
    for (size_t ix{0}; ix < input.size(); ) {
        // To number
        if(input[ix] >= '0' && input[ix] <= '9'){
            while (input[ix] >= '0' && input[ix] <= '9'){
                rvs = rvs + input[ix++];
            }
            rvs = rvs + ' ';

        // To operator
        }else {
            // Right braket
            if(input[ix]==')'){
                while(optor.top()!='('){
                    rvs = rvs + optor.top();
                    optor.pop();
                }
                // cout << optor.top() << endl; 
                optor.pop();
                ++ix;
                continue;
            }
            // 
            else if (!optor.empty() && (input[ix] == '+' || input[ix] == '-') && (optor.top() == '*' || optor.top() == '/')){
                while (!optor.empty() && (optor.top() == '*' || optor.top() == '/')) {
                    rvs = rvs + optor.top();
                    optor.pop();
                }
            }
            optor.push(input[ix]);
            ++ix;
        }
        
    }
    while(!optor.empty()){
        rvs = rvs + optor.top();
        optor.pop();
    }
    return rvs;
}

double calculator(const string& input){
    auto str = process(input);
    stack<double> stk;
    // int rslt{0};
    size_t ix{0};
    
    while (ix < str.size()){
        // Remove the useless space.
            while(str[ix++] == ' ')
                continue;
            --ix;
        // To number
        if (str[ix] >= '0' && str[ix] <= '9'){
            string num;
            while (str[ix] != ' ') {
                num = num + str[ix];
                ++ix;
            }
            stk.push(atoi(num.c_str()));
        
        // To operator
        }else{
            auto a{stk.top()};
            stk.pop();
            auto b{stk.top()};
            stk.pop();

            switch (str[ix])
            {
            case '+':
                stk.push(a + b);
                break;
            case '-':
                stk.push(b - a);
                break;
            case '*':
                stk.push(a * b);
                break;
            case '/':
                stk.push(b / a);
                break;

            default:
                break;
            }
            ++ix;
        }
    }
    return stk.top();
}

int main(){
    string s;
    cin >> s;

    // cout << calculator(s);
    cout << process(s) << endl;
    cout << calculator(s) << endl;
    return 0;
}