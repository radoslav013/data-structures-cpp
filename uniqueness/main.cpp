#include <iostream>
#include <vector>

using namespace std;

bool isUnique(const vector<int>& arr, int start, int end) {
    cout << start << " - " << end << endl;
    if (start >= end) return true;
    if (!isUnique(arr, start, end - 1))
        return false;
    if (!isUnique(arr, start+1, end))
        return false;

    return (arr[start] != arr[end]);
}

int main() {
    vector<int> vect{10, 20, 4, 5};
    cout << isUnique(vect, 0, vect.size() - 1) << endl;
    return 0;
}