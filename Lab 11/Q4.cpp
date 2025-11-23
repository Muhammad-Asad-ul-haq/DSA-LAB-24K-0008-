#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void findPairs(const vector<int>& arr) {
    unordered_map<int, pair<int,int>> mp;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {

            int sum = arr[i] + arr[j];

            if (mp.find(sum) == mp.end()) {
                mp[sum] = {arr[i], arr[j]};
            } else {
                auto p = mp[sum];
                if (p.first != arr[i] && p.first != arr[j] &&
                    p.second != arr[i] && p.second != arr[j]) {

                    cout << "(" << p.first << ", " << p.second << ") and ("
                         << arr[i] << ", " << arr[j] << ")" << endl;
                    return;
                }
            }
        }
    }

    cout << "No pairs found" << endl;
}

int main() {
    findPairs({3,4,7,1,2,9,8});
    findPairs({3,4,7,1,12,9});
    findPairs({65,30,7,90,1,9,8});
}
