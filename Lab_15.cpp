#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

bool is_prefix(const string& prefix, const string& s) {
    if (prefix.length() >= s.length()) {
        return false;
    }
    return s.substr(0, prefix.length()) == prefix;
}

void solve() {
    string line;
    if (!getline(cin, line)) return;

    stringstream ss(line);
    string password;
    vector<string> passwords;
    
    while (ss >> password) {
        passwords.push_back(password);
    }

    if (passwords.empty()) {
        cout << "GOOD PASSWORD" << endl;
        return;
    }

    sort(passwords.begin(), passwords.end());

    for (size_t i = 0; i < passwords.size() - 1; ++i) {
        const string& current = passwords[i];
        const string& next = passwords[i+1];

        if (is_prefix(current, next)) {
            // Violation found
            cout << "BAD PASSWORD" << endl;
            // Print the pair (the shorter one is the prefix)
            cout << current << " " << next << endl;
            return;
        }
    }

    cout << "GOOD PASSWORD" << endl;
}

int main() {
    ios_base::sync_with_stdio(
false);
    cin.tie(NULL);

    solve();

    return 0;
}
                                                                                                                            
