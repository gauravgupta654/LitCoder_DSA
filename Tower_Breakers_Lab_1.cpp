#include <iostream>
using namespace std;

int towerBreakers(int n, int m) {
    if (n == 1) {
        return 1;
    }
    
    if (m == 1) {
        return 1;
    }
    
    if (m % 2 == 0) {
        return 2;
    }
    
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    cout << towerBreakers(n, m) << endl;
    
    return 0;
}
