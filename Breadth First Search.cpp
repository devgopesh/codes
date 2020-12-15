#include <bits/stdc++.h>
using namespace std;

vector <long> v[100001];   //Vector for maintaining adjacency list 
long level[100001],levelcount[100001];           //To determine the level of each node
bool vis[100001];  //Mark the node if visited

void bfs(int s, long x) {
    queue <long> q;
    q.push(s);
    level[ s ] = 1 ;  //Setting the level of the source node as 1
    levelcount[level[s]]++;  //used for counting no. of nodes at a certain level
    vis[ s ] = true;
    while(!q.empty()){
        
        long p = q.front();
        q.pop();
        for(long i = 0;i < v[ p ].size() ; i++){
            
            if(vis[ v[ p ][ i ] ] == false)
            {
                //Setting the level of each node with an increment in the level of parent node
                level[ v[ p ][ i ] ] = level[ p ]+1;    
                levelcount[level[ v[ p ][ i ] ]]++;
                q.push(v[ p ][ i ]);
                vis[ v[ p ][ i ] ] = true;
            }
        }
    }
}

// main function
// execution begins here
int main() {
    long nodes ,x, y,z, k = 0;
    cin >> nodes;  
    for(long i = 1;i <=nodes;i++) {
         cin >> x >> y;     
         v[x].push_back(y);  
         v[y].push_back(x);
    }
    cin>>x;
    bfs(1,x);
    cout << levelcount[x];
    return 0;
}
