#include <bits/stdc++.h>
using namespace std;

int n;
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    int sq=sqrt(n);
    if(a.F.F/sq==b.F.F/sq) return a.F.S<b.F.S;
    return a.F.F/sq<b.F.F/sq;
}

int32_t main(){
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    vector<pair<pair<int,int>,int>> query(q);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        query[i]={{l,r},i};
    }
    sort(all(query),cmp);
    int cn=0;
    vector<int> mpp(1000001,0);
    int l=0,r=-1;
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        int x=query[i].F.F,y=query[i].F.S;x--;y--;
        while(l>x){
            l--;mpp[a[l]]++;
            if(mpp[a[l]]==1) cn++;
        }
        while(r<y){
            r++;mpp[a[r]]++;
            if(mpp[a[r]]==1) cn++;
        }
        while(l<x){
            mpp[a[l]]--;
            if(mpp[a[l]]==0) cn--;
            l++;
        }
        while(r>y){
            mpp[a[r]]--;
            if(mpp[a[r]]==0) cn--;
            r--;
        }
        int z=query[i].S;
        ans[z]=cn;
    }
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0; 
}
