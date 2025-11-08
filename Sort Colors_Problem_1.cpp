#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

void sortColorNames(vector<string>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    
    while (mid <= high) {
        if (nums[mid] == "Crimson") {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == "Ivory") {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    string input;
    getline(cin, input);
    
    stringstream ss(input);
    string token;
    vector<string> tokens;
    
    while (ss >> token) {
        tokens.push_back(token);
    }
    
    if (tokens[0] == "0" || tokens[0] == "1" || tokens[0] == "2") {
        vector<int> nums;
        for (const string& token : tokens) {
            nums.push_back(stoi(token));
        }
        
        sortColors(nums);
        
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i];
            if (i < nums.size() - 1) cout << " ";
        }
        cout << endl;
    } else {
        sortColorNames(tokens);
        
        for (int i = 0; i < tokens.size(); i++) {
            cout << tokens[i];
            if (i < tokens.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
