#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool isSpecialPrime(int num) {
    string s = to_string(num);
    int len = s.length();
    
    for (int i = 1; i <= len; i++) {
        int prefix = stoi(s.substr(0, i));
        if (!isPrime(prefix)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = n - 1; i >= 2; i--) {
        if (isSpecialPrime(i)) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}
                                                                                                                            
