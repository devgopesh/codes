#include <bits/stdc++.h>
using namespace std;

long arr[100005];
long tree[4*100005];

void build_tree(long node, long a, long b){
    
    if(a==b)
        tree[node]=arr[a];
    else{
        long mid=(a+b)/2;
        build_tree(2*node,a,mid);
        build_tree(2*node+1,mid+1,b);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

void update_tree(long node, long a, long b, long i, long value){
    
    if(a>b || i>b || i<a)
        return;
    if(a==b){
        tree[node]=value;
        arr[i]=value;
    }
    else{
        long mid=(a+b)/2;
        if(i>=a && i<=mid)
            update_tree(2*node,a,mid,i,value);
        else
            update_tree(2*node+1,mid+1,b,i,value);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

long query_tree(long node, long a, long b, long i, long j){
    
    if(a>j || i>b || a>b)
        return 0;
    if(i<=a && j>=b)
        return tree[node];
    long mid=(a+b)/2;
    long p1=query_tree(2*node,a,mid,i,j);
    long p2=query_tree(2*node+1,mid+1,b,i,j);
    long res=min(p1,p2);
    return res;
}

// execution begins here
int main()
{   long n,q,i,x,y;
    char c;
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    build_tree(1,1,n);
    while(q--){
        
        cin>>c>>x>>y;
        if(c=='u')
            update_tree(1,1,n,x,y);
        else
            cout << query_tree(1,1,n,x,y) << "\n";
    }
    return 0;
}

