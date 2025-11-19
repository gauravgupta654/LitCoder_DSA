#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <algorithm>

class SimpleTextEditor {
private:
    std::string currentText;
    std::stack<std::string> history; 

    void saveState() {
        history.push(currentText);
    }

public:
    SimpleTextEditor() : currentText("") {}

    void insert(const std::string& value) {
        saveState();
        currentText.append(value);
    }

    void deleteChars(int count) {
        if (count > 0 && !currentText.empty()) {
            saveState();
            
            size_t deleteLength = std::min((size_t)count, currentText.length());
            
            currentText.erase(currentText.length() - deleteLength);
        }
    }

    void get(int index) const {
        if (index >= 0 && index < currentText.length()) {
            std::cout << currentText[index] << "\n";
        }
    }

    void undo() {
        if (!history.empty()) {
            currentText = history.top();
            history.pop();
        }
    }
};

void solve() {
    SimpleTextEditor editor;
    
    int commandType;
    while (std::cin >> commandType) {
        if (commandType == 1) {
            std::string value;
            if (std::cin >> value) {
                editor.insert(value);
            }
        } else if (commandType == 2) {
            int count;
            if (std::cin >> count) {
                editor.deleteChars(count);
            }
        } else if (commandType == 3) {
            int index;
            if (std::cin >> index) {
                editor.get(index - 1); // Adjust index to be 0-based for C++ string access
            }
        } else if (commandType == 4) {
            editor.undo();
        }
    }
}

int main() {
    solve();
    return 0;
}
                                                                                                                            
