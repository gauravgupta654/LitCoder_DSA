#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    string input;
    vector<int> heights;
    
    getline(cin, input);
    
    stringstream ss(input);
    string token;
    
    while (ss >> token) {
        bool isInteger = true;
        for (char c : token) {
            if (!isdigit(c)) {
                if (c == '-' && token.size() > 1) {
                    continue;
                }
                isInteger = false;
                break;
            }
        }
        
        if (!isInteger) {
            cout << "Input was not in a correct format" << endl;
            return 0;
        }
        
        try {
            heights.push_back(stoi(token));
        } catch (...) {
            cout << "Input was not in a correct format" << endl;
            return 0;
        }
    }
    
    if (heights.size() < 3) {
        cout << "Input was not in a correct format" << endl;
        return 0;
    }
    
    vector<int> peaks;
    int n = heights.size();
    
    for (int i = 1; i < n - 1; i++) {
        if (heights[i] > heights[i - 1] && heights[i] > heights[i + 1]) {
            peaks.push_back(heights[i]);
        }
    }
    
    vector<vector<int>> mountainPeaks;
    vector<int> currentMountain;
    
    for (int i = 0; i < peaks.size(); i++) {
        currentMountain.push_back(peaks[i]);
        
        if (i == peaks.size() - 1) {
            mountainPeaks.push_back(currentMountain);
            currentMountain.clear();
        } else {
            int currentPeakIndex = distance(heights.begin(), 
                find(heights.begin(), heights.end(), peaks[i]));
            int nextPeakIndex = distance(heights.begin(), 
                find(heights.begin() + currentPeakIndex + 1, 
                    heights.end(), peaks[i + 1]));
            
            bool hasValley = false;
            for (int j = currentPeakIndex + 1; j < nextPeakIndex; j++) {
                if (heights[j] < heights[currentPeakIndex] && 
                    heights[j] < heights[nextPeakIndex]) {
                    hasValley = true;
                    break;
                }
            }
            
            if (hasValley) {
                mountainPeaks.push_back(currentMountain);
                currentMountain.clear();
            }
        }
    }
    
    if (peaks.empty()) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> highestPeaks;
    for (const auto& mountain : mountainPeaks) {
        if (!mountain.empty()) {
            int maxPeak = *max_element(mountain.begin(), mountain.end());
            highestPeaks.push_back(maxPeak);
        }
    }
    
    cout << highestPeaks.size() << endl;
    
    if (!highestPeaks.empty()) {
        for (size_t i = 0; i < highestPeaks.size(); i++) {
            cout << highestPeaks[i];
            if (i != highestPeaks.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
