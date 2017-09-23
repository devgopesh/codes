#include <bits/stdc++.h>
using namespace std;

void build_tree(long node, long a, long b, long arr[], long tree[]){
    
    if(a==b)
        tree[node]=arr[a];
    else{
        long mid=(a+b)/2;
        build_tree(2*node,a,mid,arr,tree);
        build_tree(2*node+1,mid+1,b,arr,tree);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

void update_tree(long node, long a, long b, long i, long j, long value, long arr[], long tree[], long lazy[]){
    
    if(lazy[node] != 0) { 
   		tree[node] += (b-a+1)*lazy[node]; 

		if(a != b) {
			lazy[node*2] += lazy[node]; 
    			lazy[node*2+1] += lazy[node]; 
		}

   		lazy[node] = 0; 
  	}
    if(a>b || i>b || j<a)
        return;
    if(a >= i && b <= j) {
    		tree[node] += (b-a+1)*value;

		if(a != b) { 
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}
		return;
	}	
		long mid=(a+b)/2;
        update_tree(2*node,a,mid,i,j,value,arr,tree,lazy);
        update_tree(2*node+1,mid+1,b,i,j,value,arr,tree,lazy);
        tree[node]=tree[2*node]+tree[2*node+1];
    }

long query_tree(long node, long a, long b, long i, long j, long arr[], long tree[], long lazy[]){
    
    if(a>j || i>b || a>b)
        return 0;
    if(lazy[node] != 0) { 
		tree[node] += (b-a+1)*lazy[node]; 

		if(a != b) {
			lazy[node*2] += lazy[node]; 
			lazy[node*2+1] += lazy[node]; 
		}

		lazy[node] = 0; 
	}
    if(i<=a && j>=b)
        return tree[node];
    long mid=(a+b)/2;
    long p1=query_tree(2*node,a,mid,i,j,arr,tree,lazy);
    long p2=query_tree(2*node+1,mid+1,b,i,j,arr,tree,lazy);
    long res=p1+p2;
    return res;
}

int main()
{   long n,q,i,x,y,z,t,arr[100000],tree[10*100005],lazy[10*100005],c;
	cin>>t;
	while(t--){
		
		cin>>n>>q;
    	for(i=1;i<=10*n;i++){
    		
			arr[i]=0;
			tree[i]=0;
			lazy[i]=0;
		}
    	build_tree(1,1,n,arr,tree);
    	while(q--){
        
        	cin>>c;
        	if(c==0){
        		cin>>x>>y>>z;
        		update_tree(1,1,n,x,y,z,arr,tree,lazy);
			}
        	else{
        		cin>>x>>y;
        		cout << query_tree(1,1,n,x,y,arr,tree,lazy) << "\n";
			}
    	}
	}
    return 0;
}

