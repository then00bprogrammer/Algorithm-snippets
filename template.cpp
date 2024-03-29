#include <bits/stdc++.h>
using namespace std;
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

typedef pair<int, int> pair_int;
typedef pair<int,pair_int> pair_int_pair;

typedef vector<int> vector1D;
typedef vector<vector1D> vector2D;
typedef vector<vector2D> vector3D;
typedef vector<vector3D> vector4D;

typedef unordered_map <int,int> u_map_int_int;
typedef map<pair_int,int> map_pair_int;
typedef map<vector1D,int> map_vector_int;

typedef priority_queue<int, vector<int>, greater<int>> pq_int_min;
typedef priority_queue<int, vector<int>> pq_int_max;
typedef priority_queue<pair_int, vector<pair_int>, greater<pair_int>> pq_pair_min;
typedef priority_queue<pair_int, vector<pair_int>> pq_pair_max;
typedef priority_queue<pair_int_pair, vector<pair_int_pair>, greater<pair_int_pair>> pq_pair_int_pair_min;
typedef priority_queue<pair_int_pair, vector<pair_int_pair>> pq_pair_int_pair_max;

int getDigit(int num, int place) {
  num/=pow(10,place-1);
  return num%10;
}

int main(){
pq_int_min pq;
pq.push(1);
pq.push(10);
pq.push(34);
pq.push(-55);
while(!pq.empty()){
    cout<<pq.top()<<endl;
    pq.pop();
} 
int num=423552;
cout<<"4th digit is :"<<getDigit(num,4)<<endl;
return 0;
}