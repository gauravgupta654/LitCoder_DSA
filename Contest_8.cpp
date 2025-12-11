#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

pair<bool, int> checkBrackets(const string& str) {
    stack<char> st;
    int matchedPairs = 0;
    
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                return {false, matchedPairs};
            }
            
            char top = st.top();
            
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();
                matchedPairs++;
            } else {
                return {false, matchedPairs};
            }
        }
    }
    
    bool allMatched = st.empty();
    return {allMatched, matchedPairs};
}

int main() {
    string input;
    
    getline(cin, input);
    
    stringstream ss(input);
    string token;
    vector<string> strings;
    
    while (getline(ss, token, ',')) {
        strings.push_back(token);
    }
    
    for (size_t i = 0; i < strings.size(); i++) {
        pair<bool, int> result = checkBrackets(strings[i]);
        
        if (result.first) {
            cout << "YES " << result.second;
        } else {
            cout << "NO " << result.second;
        }
        
        if (i != strings.size() - 1) {
            cout << endl;
        }
    }
    
    return 0;
}
