#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class VisitorCounter {
private:
    vector<long long> prefixSum;
    
public:
    VisitorCounter(const vector<int>& visitors) {
        int n = visitors.size();
        prefixSum.resize(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + visitors[i];
        }
    }
    
    long long query(int left, int right) {
        int n = prefixSum.size() - 1;
        if (left < 0 || right >= n || left > right) {
            return 0;
        }
        
        return prefixSum[right + 1] - prefixSum[left];
    }
};

int main() {
    vector<int> visitors;
    string line;
    
    if (!getline(cin, line)) {
        return 0;
    }
    
    stringstream ss(line);
    int num;
    
    while (ss >> num) {
        visitors.push_back(num);
    }
    
    if (visitors.empty()) {
        cout << "Input is not in correct format or missing cpp code" << endl;
        return 0;
    }
    
    int q;
    if (!(cin >> q)) {
        cout << "Input is not in correct format or missing cpp code" << endl;
        return 0;
    }
    
    VisitorCounter counter(visitors);
    
    for (int i = 0; i < q; i++) {
        int left, right;
        if (!(cin >> left >> right)) {
            cout << "Input is not in correct format or missing cpp code" << endl;
            return 0;
        }
        
        cout << counter.query(left, right) << endl;
    }
    
    return 0;
}
