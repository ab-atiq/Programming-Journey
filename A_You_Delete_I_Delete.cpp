// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int tc;
//     cin >> tc;

//     while (tc--) {
//         string s;
//         cin >> s;

//         string aliceBest = "";

//         bool firstAlice = true;

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] != '0') continue;

//             // Alice deletes this 0
//             string afterAlice = s.substr(0, i) + s.substr(i + 1);

//             string bobBest;
//             bool firstBob = true;

//             for (int j = 0; j < afterAlice.size(); j++) {
//                 if (afterAlice[j] != '1') continue;

//                 // Bob deletes this 1
//                 string afterBob = afterAlice.substr(0, j) + afterAlice.substr(j + 1);

//                 if (firstBob || afterBob < bobBest) {
//                     bobBest = afterBob;
//                     firstBob = false;
//                 }
//             }

//             if (firstAlice || bobBest > aliceBest) {
//                 aliceBest = bobBest;
//                 firstAlice = false;
//             }
//         }

//         cout << aliceBest << '\n';
//     }

//     return 0;
// }



#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        // Alice's move
        if (s[0] == '0') {
            // delete first 0
            int pos = s.find('0');
            s.erase(pos, 1);
        } else {
            // delete last 0
            int pos = s.rfind('0');
            s.erase(pos, 1);
        }

        // Bob's move: delete first 1
        int pos = s.find('1');
        s.erase(pos, 1);

        cout << s << '\n';
    }
}