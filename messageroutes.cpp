#include<bits/stdc++.h>
using namespace std;



int main(){

     int n,m,a,b;
     cin>>n>>m;
     vector<vector<int> >arr(n+1);
     vector<int> dis(n+1,INT_MAX);
     vector<int> parent(n+1);

     for(int i=0;i<m;i++){
      
         cin>>a>>b;
         arr[a].push_back(b);
         arr[b].push_back(a);
     }
     queue<int> q;
     q.push(1);
     dis[1]=0;

     while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int t:arr[p]){
            if(dis[t]==INT_MAX){
                dis[t]=dis[p]+1;
                parent[t]= p;
                q.push(t);
            }
        }
     }

        

   
     if(dis[n]==INT_MAX){
         cout<<"IMPOSSIBLE";
     }
     else{
         cout<<dis[n]+1<<endl;
         vector<int> V;
         V.push_back(n);
         while(V.back()!=1){
             V.push_back(parent[V.back()]);

         }
         reverse(begin(V),end(V));
         for (int t: V) cout << t << " ";

     }
    
}
