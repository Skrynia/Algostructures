#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector < string > A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    int m = A[0].size();

    for (int i = m - 1; i > -1; i--) {
        vector < vector < string > > bucket(10);
        for (int j = 0; j < n; j++) bucket[A[j][i] - '0'].push_back(A[j]);
        int p = 0;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < bucket[j].size(); k++) {
                A[p] = bucket[j][k];
                p++;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << A[i] << ' ';

    return 0;
}