#include <bits/stdc++.h>
using namespace std;

#define int    long long int

template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }

void build(vector<int> a,vector<int> &pre){
    int n=a.size();
    int sq=sqrt(n);
    int sz=(n+sq-1)/sq;
    vector<int> v(sz,1e12);
    for(int i=0;i<n;i++){
        int x=i/sq;
        umin(v[x],a[i]);
    }
    pre=v;
}
int query(int l,int r,vector<int> a,vector<int> pre){
    int n=a.size();
    int sq=sqrt(n);
    int lb=(l+sq-1)/sq;
    int ub=r/sq;
    deb(l,r);
    deb(lb,ub,sq);
    if(ub<=lb){
        int mn=1e12;
        for(int i=l;i<=r;i++){
            umin(mn,a[i]);
        }
        return mn;
    }
    int mn1=1e12,mn2=1e12,mn3=1e12;
    for(int i=l;i<=lb*sq;i++){
        umin(mn1,a[i]);
    }
    for(int i=lb;i<ub;i++){
        umin(mn2,pre[i]);
    }
    for(int i=ub*sq;i<=r;i++){
        umin(mn3,a[i]);
    }
    return min({mn1,mn2,mn3});
}

int32_t main(){
    int n;
    cin>>n; // Taking input of the length of the array
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> pre;
    build(a,pre); // Building the sqrt sized vector
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r,a,pre)<<endl; // Processing the queries
    }
    return 0;
}
