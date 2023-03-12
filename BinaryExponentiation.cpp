#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
const int MOD=1e9+7;

int bin_pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

struct Matrix{
    vector<vector<int>> a;
    int n;
    Matrix(int n){
        this->n=n;
        a.resize(n,vector<int>(n,0));
    }
    Matrix operator*(const Matrix& other){
        Matrix product(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    product.a[i][k]=(product.a[i][k]+a[i][j]*other.a[j][k])%MOD;
                }
            }
        }  
        return product;      
    }

    Matrix operator^(int k){
        Matrix ans(n);
        Matrix m=*this;
        for(int i=0;i<n;i++)ans.a[i][i]=1;
        while(k>0){
            if(k&1)ans=ans*m;
            m=m*m;
            k>>=1;
        }
        return ans;
    }
};


int32_t main(){
    //When I wrote this, only God and I understood what I was doing
    //Now, only God knows
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    Matrix ans(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        ans.a[u-1][v-1]=1;
    }
    ans=ans^k;
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)sum=(sum+ans.a[i][j])%MOD;
    }
    cout<<sum<<endl;
    return 0;
}