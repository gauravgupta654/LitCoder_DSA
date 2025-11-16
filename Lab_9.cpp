#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    cin >> k;
    
    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);
    }
    
    int count = 0;
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) % k == 0) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}
