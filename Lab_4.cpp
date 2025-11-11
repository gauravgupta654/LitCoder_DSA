#include <iostream>
#include <vector>
#include <string>

using namespace std;

int digitSum(int n) {
    while (n >= 10) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }
    return n;
}

int main() {
    vector<int> numbers(6);
    for (int i = 0; i < 6; i++) {
        cin >> numbers[i];
    }
    
    string result = "";
    
    for (int num : numbers) {
        int singleDigit = digitSum(num);
        
        if (singleDigit % 2 == 1) {
            result += char('a' + (singleDigit - 1));
        } else {
            result += to_string(singleDigit);
        }
    }
    
    cout << result << endl;
    
    return 0;
}
                                                                                                                            
