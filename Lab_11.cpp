#include <iostream>
#include <stack>
#include <string>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;

    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    void enqueue(int package_id) {
        s1.push(package_id);
    }

    void dequeue() {
        if (s2.empty()) {
            transfer();
        }
        if (!s2.empty()) {
            cout << s2.top() << endl;
            s2.pop();
        } else {
            cout << "Invalid Input" << endl;
        }
    }

    void peek() {
        if (s2.empty()) {
            transfer();
        }
        if (!s2.empty()) {
            cout << s2.top() << endl;
        } else {
            cout << "Invalid Input" << endl;
        }
    }

    void size() {
        cout << s1.size() + s2.size() << endl;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    
    QueueUsingStacks q;
    
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        
        if (command == "enqueue") {
            int package_id;
            cin >> package_id;
            if (package_id < 1 || package_id > 1000) {
                cout << "Invalid Input" << endl;
            } else {
                q.enqueue(package_id);
            }
        } else if (command == "dequeue") {
            q.dequeue();
        } else if (command == "peek") {
            q.peek();
        } else if (command == "size") {
            q.size();
        } else {
            cout << "Invalid Input" << endl;
        }
    }
    
    return 0;
}
                                                                                                                            
