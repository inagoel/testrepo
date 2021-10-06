#include<iostream>
#include<vector>
using namespace std;
vector<int> arr[100001];
int in[100001],low[100001],vis[100001],timer;
vector<pair<int,int> > edge_list;
bool hasBrigde=false;
void dfs(int node,int par){
    vis[node]=1;
    in[node]=low[node]=timer++;
    for(int child:arr[node]){
        if(child==par)continue;
        if(vis[child]){
            low[node]=min(low[node],in[child]);
            if(in[node]>in[child]){
                edge_list.push_back(make_pair(node,child));
            }
        }
        else{
            dfs(child,node);
            if(low[child]>in[node]){
                hasBrigde=true;
                return;

            }
            edge_list.push_back(make_pair(node,child));
            low[node]=min(low[node],low[child]);
        }
    }
}

int main(){
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1,-1);
    if(hasBrigde==true){
        cout<<"0";
    }
    else{
        for(pair<int,int> e:edge_list){
            cout<<e.first<<" "<<e.second<<endl;
        }
    }
}
