#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> charlie(5);
    vector<int> dave(5);
    
    for (int i = 0; i < 5; i++) {
        cin >> charlie[i];
    }
    for (int i = 0; i < 5; i++) {
        cin >> dave[i];
    }
    
    int charlie_points = 0;
    int dave_points = 0;
    
    for (int i = 0; i < 5; i++) {
        if (charlie[i] > dave[i]) {
            charlie_points++;
        } else if (charlie[i] < dave[i]) {
            dave_points++;
        }
    }
    
    cout << charlie_points << " " << dave_points << endl;
    
    return 0;
}
