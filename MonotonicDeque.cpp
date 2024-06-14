#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

struct MonotonicDeque
{
    deque<int> dq;

    void insert(int x) {
        while(!dq.empty() && dq.back() > x) dq.pop_back();
        dq.push_back(x);
    }

    void remove(int x) {
        if(!dq.empty() && dq.front() == x) dq.pop_front();
    }

    int get_min() {
        return dq.front();
    }
};

signed main() {
    MonotonicDeque mdq;

    vector<int> elements = {5, 3, 8, 1, 2, 7};
    int k=3;

    int l=0,r=0;
    while(r<elements.size()) {
        mdq.insert(elements[r]);
        if(r-l+1==k) {
            cout<<l<<" "<<r<<" "<<mdq.get_min()<<endl;
            mdq.remove(elements[l]);
            ++l;
        }
        ++r;
    }

    return 0;
}
