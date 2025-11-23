#include <iostream>
#include <vector>
#include <algorithm>

long long solve() {
    int arraySize, queryCount;
    std::cin >> arraySize >> queryCount;
    
    std::vector<long long> diffArray(arraySize + 2, 0);
    
    for (int i = 0; i < queryCount; ++i) {
        int a, b, k;
        std::cin >> a >> b >> k;
        
        diffArray[a] += k;
        if (b + 1 <= arraySize) {
            diffArray[b + 1] -= k;
        }
    }
    
    long long currentMax = 0;
    long long runningSum = 0;
    
    for (int i = 1; i <= arraySize; ++i) {
        runningSum += diffArray[i];
        if (runningSum > currentMax) {
            currentMax = runningSum;
        }
    }
    
    return currentMax;
}

int main() {
    std::cout << sol
ve() << std::endl;
    return 0;
}
                                                                                                                            
