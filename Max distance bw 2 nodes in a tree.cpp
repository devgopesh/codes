#include <bits/stdc++.h>
using namespace std;

long ds;
vector< pair<long,long> > v[100001];

void initialise(){
    memset(v,0,sizeof(v));
}

long bfs(long s, long n) {
    queue <long> q;
    bool vis[n+1];
    long dist[n+1];
    memset(dist,0,sizeof(dist));
    memset(vis,false,sizeof(vis));
    q.push(s);
    vis[ s ] = true;
    dist[s]=0;
    while(!q.empty())
    {
        long p= q.front();
        q.pop();
        for(int i = 0;i < v[ p ].size() ; i++)
        {
            if(vis[ v[ p ][ i ].first ] == false)
            {   dist[v[p][i].first]=dist[p]+v[p][i].second;
                q.push(v[ p ][ i ].first);
                vis[ v[ p ][ i ].first ] = true;
            }
        }
    }
    ds=*max_element(dist+1,dist+n+1);
    return(max_element(dist,dist+n+1)-dist);
}

int main()
{   long t,n,i,a,b,c,j,cost;
    cin>>t;
    while(t--){
        
        cin>>n;
        initialise();
        for(i=0;i<n-1;i++){
            
            cin>>a>>b>>c;
            v[a].push_back( make_pair(b,c) );
            v[b].push_back( make_pair(a,c) );
        }
        j=bfs(1,n);
        bfs(j,n);
        if(ds<100)
            cost=0;
        else if(ds>100&&ds<=1000)   
            cost=100;
        else if(ds>1000&&ds<=10000)
            cost=1000;
        else
            cost=10000;
        cout<<cost<<" "<<ds<<endl;
    }
    return 0;
}
