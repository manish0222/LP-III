#include <bits/stdc++.h>
using namespace std;
class nqueen{
    // Time Complexity: O(N!)
// Auxiliary Space: O(N2)
public:
    int n;
    nqueen(int n){
        this->n=n;
    }
    bool valid(int row,int col,vector<string> &arr,int n){
        int r=row,c=col;
        while(r>=0 and c>=0){
            if(arr[r][c]=='Q') return false;
            r--;c--;
        }
        c=col;
        r=row;
        while(c>=0){
            if(arr[r][c]=='Q') return false;
            c--;
        }
        c=col;r=row;
        while(r<n and col>=0){
            if(arr[r][c]=='Q') return false;
            r++;c--;
        }
        return true;
    }
    void get(int col,vector<string> &arr,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(arr);
            return;
        }
        for(int row=0;row<n;row++){
            if(valid(row,col,arr,n)){
                arr[row][col]='Q';
                get(col+1,arr,ans,n);
                arr[row][col]='.';
            }
        }
    }
    vector<vector<string>> solve(int n){
        string s(n,'.');
        vector<vector<string>> ans;
        vector<string> arr(n);
        for(int i=0;i<n;i++) arr[i]=s;
        get(0,arr,ans,n);
        return ans;
    }
};
int main() {
    nqueen obj(4);
    auto k=obj.solve(4);
    int r=0,c=0;
    if(k.size()==0) cout<<"NP";
    else cout<<k.size()<<endl;
    bool found=0;
    for(auto i:k){
        if(i[r][c]=='Q'){
            found=1;
            for(auto j:i){
                cout<<j<<endl;
            }
            cout<<"\n------\n";
        }
    }
    if(found==0) cout<<"NP";
    return 0;
}
