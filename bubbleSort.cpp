#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int c = 0;
    cin >> n;
    vector < int > A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }

    for (int k = 0; k < n; k++) cout << A[k] << " ";

    return 0;
}