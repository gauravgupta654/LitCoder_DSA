#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int minStepsToTargetSweetness(long long target_sweetness, const vector<long long>& candies) {
    
    priority_queue<long long, vector<long long>, greater<long long>> min_heap;

    for (long long sweetness : candies) {
        min_heap.push(sweetness);
    }

    int steps = 0;

    while (min_heap.top() < target_sweetness) {
        
        if (min_heap.size() < 2) {
            return -1;
        }
        
        long long C1 = min_heap.top();
        min_heap.pop();
        
        long long C2 = min_heap.top();
        min_heap.pop();

        long long C_new = C1 + 2 * C2;

        min_heap.push(C_new);

        steps++;
    }

    return steps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long target;
    if (!(cin >> target)) return 0;

    vector<long long> candies;
    long long sweetness;
    
    while (cin >> sweetness) {
        candies.push_back(sweetness);
    }

    cout << minStepsToTarge;
tSweetness(target, candies) << endl;

    return 0;
}
                                                                                                                            
