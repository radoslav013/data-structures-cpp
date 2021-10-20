#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool areDisjoint(const vector<int>& a, const vector<int>& b, const vector<int>& c) 
{ // Big O(n*n*n)
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            for (int k = 0; k < c.size(); k++)
                if ((a[i] == b[j]) && (b[j] == c[k])) return false;
    return true;
}

void print(const vector<int>& vect) {
    for(auto el : vect) {
        cout << el << " ";
    }
    cout << endl;
}

bool areDisjointImproved(vector<int>& a, vector<int>& b, vector<int>& c) 
{ // Big O(nlogn)
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int size_sum = a.size() + b.size();
    vector<int> ab(size_sum);
    merge(a.begin(), a.end(), b.begin(), b.end(), ab.begin());

    vector<int> result(size_sum + c.size());
    merge(c.begin(), c.end(), ab.begin(), ab.end(), result.begin());
    
    for(int i = 0; i < result.size() - 1; i++) {
        if(result[i] == result[i + 1]) return false;
    }

    return true;
}

bool areDisjointImproved2(vector<int>& a, vector<int>& b, vector<int>& c) 
{ // Big O(nlogn)
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int size_sum = a.size() + b.size();
    const int init_sum_size = size_sum + c.size();

    vector<int> ab(size_sum);
    vector<int>::iterator it = set_union(a.begin(), a.end(), b.begin(), b.end(), ab.begin());
    ab.resize(it-ab.begin());

    size_sum = ab.size() + c.size();
    vector<int> result(size_sum);
    it = set_union(c.begin(), c.end(), ab.begin(), ab.end(), result.begin());

    result.resize(it-result.begin());  

    return init_sum_size == result.size();
}

int main()
{
    vector<int> a{10, 11, 12, 19};
    vector<int> b{13, 14, 15};
    vector<int> c{16, 17, 12, 18};

    cout << areDisjointImproved2(a, b, c) << endl;
    return 0;
}