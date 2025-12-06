#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

bool isOpeningBracket(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isClosingBracket(char c) {
    return c == ')' || c == '}' || c == ']';
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

pair<bool, int> checkBracketString(const string& s) {
    stack<pair<char, int>> bracketStack; // stack stores bracket char and its index
    vector<bool> matched(s.length(), false); // track which brackets are matched
    
    for (int i = 0; i < s.length(); i++) {
        if (isOpeningBracket(s[i])) {
            bracketStack.push({s[i], i});
        } 
        else if (isClosingBracket(s[i])) {
            if (!bracketStack.empty() && isMatchingPair(bracketStack.top().first, s[i])) {
                matched[bracketStack.top().second] = true;
                matched[i] = true;
                bracketStack.pop();
            }
        }
    }
    
    int pairCount = 0;
    for (bool m : matched) {
        if (m) pairCount++;
    }
    pairCount /= 2; 
    
    bool allMatched = true;
    for (bool m : matched) {
        if (!m) {
            allMatched = false;
            break;
        }
    }
    
    return {allMatched, pairCount};
}

int main() {
    string input;
    
    getline(cin, input);
    
    stringstream ss(input);
    string bracketString;
    vector<string> strings;
    
    while (getline(ss, bracketString, ',')) {
        strings.push_back(bracketString);
    }
    
    for (size_t i = 0; i < strings.size(); i++) {
        pair<bool, int> result = checkBracketString(strings[i]);
        
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
