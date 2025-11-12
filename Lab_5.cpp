include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string email;
    getline(cin, email);
    
    int total = email.length();
    int upper = 0, lower = 0, digit = 0, other = 0;
    
    for (char c : email) {
        if (isupper(c)) {
            upper++;
        } else if (islower(c)) {
            lower++;
        } else if (isdigit(c)) {
            digit++;
        } else {
            other++;
        }
    }
    
    cout << fixed << setprecision(3);
    cout << (upper * 100.0 / total) << "%" << endl;
    cout << (lower * 100.0 / total) << "%" << endl;
    cout << (digit * 100.0 / total) << "%" << endl;
    cout << (other * 100.0 / total) << "%" << endl;
    
    return 0;
}
                                                                                                                            
