#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
//    void processStrings(unordered_set <string>& saved, unordered_set <string>& deleted, string& bigS) {
//        istringstream iss(bigS);
//        string s;
//        while (iss >> s) {
//            if (deleted.count(s)) {
//                // already deleted, ignore it
//            } else if (saved.count(s)) {
//                // second time seeing this string, delete it
//                deleted.insert(s);
//                saved.erase(s);
//            } else {
//                // first time
//                saved.insert(s);
//            }
//        }
//    }
//
//    vector<string> uncommonFromSentences(string A, string B) {
//        unordered_set <string> saved;
//        unordered_set <string> deleted;
//
//        processStrings(saved, deleted, A);
//        processStrings(saved, deleted, B);
//
//        vector<string> uncommon(saved.begin(), saved.end());
//
//        return uncommon;
//    }

    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> m;
        istringstream iss(A + " " + B);
        string s;
        while (iss >> s) {
            ++m[s];
        }
        vector<string> uncommon;
        for (auto &p : m) {
            if (p.second == 1)
                uncommon.push_back(p.first);
        }

        return uncommon;
    }
};

void test1() {
    string A1 = "this apple is sweet", B1 = "this apple is sour";

    cout << " ? " << Solution().uncommonFromSentences(A1, B1) << endl;

    string A2 = "apple apple", B2 = "banana";

    cout << " ? " << Solution().uncommonFromSentences(A2, B2) << endl;
}

void test2() {

}

void test3() {

}