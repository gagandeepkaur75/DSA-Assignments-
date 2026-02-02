#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char ch : str) {
        
        if (ch == ' ') continue;

        freq[ch]++;
        q.push(ch);

       
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter the character stream: ";
    getline(cin, input); 

    cout << "First non-repeating characters: ";
    firstNonRepeating(input);

    return 0;
}
