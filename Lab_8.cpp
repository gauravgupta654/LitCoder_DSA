#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    vector<int> sightings;
    int num;
    
    while (cin >> num) {
        sightings.push_back(num);
    }
    
    unordered_map<int, int> freq;
    for (int plant : sightings) {
        freq[plant]++;
    }
    
    int maxFreq = 0;
    int result = 0;
    
    for (auto& [plant, count] : freq) {
        if (count > maxFreq || (count == maxFreq && plant < result)) {
            maxFreq = count;
            result = plant;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
                                                                                                                            
