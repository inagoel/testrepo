#include<bits/stdc++.h>
using namespace std;
#define MAXN 202020

vector<int>arr[100001];
vector<int> visited(100001,0);
vector<int>bridges;
void dfs(int node){
    visited[node]=1;
    for(int child: arr[node]){
        if(visited[child]==0){
        dfs(child);
        }
    }
}
 int main(){
     int n,m,a,b;
     cin>>n>>m;
     for(int i=0;i<m;i++){
      
         cin>>a>>b;
         arr[a].push_back(b);
         arr[b].push_back(a);
     }
     for(int i=1;i<=n;i++){
         if(visited[i]==0){
             bridges.push_back(i);
             dfs(i);
         }
     }
     cout<<bridges.size()-1<<endl;
     for (int i = 0; i < bridges.size() - 1; i++) {
      cout << bridges[i] << " " << bridges[i + 1] << endl;
    }

 }