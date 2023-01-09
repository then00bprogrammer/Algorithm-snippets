#include <bits/stdc++.h>
using namespace std;
using ll= long long;
typedef vector<ll> vector1D;
typedef vector<vector1D> vector2D;
typedef vector<vector2D> vector3D;
typedef vector<vector3D> vector4D;

ll getDigit(ll num, ll place) {
  num/=pow(10,place);
  return num%10;
}

ll getCount(ll n,ll num,bool check,bool leading,bool isEven,vector4D &dp){
    ll sum=0;
    ll maxi=check?getDigit(num,n):9;

    if(n==0){
        if(isEven)return 1+(maxi/2);
        else return ceil(1.0*maxi/2);
    }

    if(dp[n][check][leading][isEven]!=-1)return dp[n][check][leading][isEven];
    
    for(ll i=0;i<=maxi;i++){
        bool newCheck=false;
        if(check && (i==maxi)) newCheck=true;
        
        if((i==0) && leading){
            sum+=getCount(n-1,num,newCheck,true,isEven,dp);
            continue;
        }
        if(isEven && (i%2==0))sum+=getCount(n-1,num,check && (i==maxi),false,!isEven,dp);
        if(!isEven && (i%2))sum+=getCount(n-1,num,check && (i==maxi),false,!isEven,dp);
    }
    return dp[n][check][leading][isEven]=sum;
}
int main(){
    ll t;cin>>t;
    ll count=1;

    while (count<=t){
        vector4D dp;
        dp.resize(18+1,vector3D(2,vector2D(2,vector1D(2,-1))));
        ll l,r;
        cin>>l>>r;
        ll high=getCount(18,r,true,true,false,dp);
        fill(dp.begin(), dp.end(), vector3D(2,vector2D(2,vector1D(2,-1))));
        ll low=getCount(18,l-1,true,true,false,dp);
        cout<<"Case #"<<count<<": "<<high-low<<endl;
        ++count;
    }
    return 0;
}