#include <bits/stdc++.h>
using namespace std;

int findMinDis(int distance[],bool visited[],int n)
{
    int minV=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minV==-1 || distance[minV]>distance[i]))
            minV=i;
    }
    return minV;
}
void dijk(int **edges,int n){
    
    int distance[n];
    bool visited[n];
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    //Starting with node 0
    distance[0]=0;for(int i=0;i<n-1;i++)
    {
        int minV=findMinDis(distance,visited,n);
        visited[minV]=true;
        
        for(int j=0;j<n;j++)
        {
            if(edges[minV][j] && !visited[j])
            {
                if(distance[j]>distance[minV]+edges[minV][j])
                    distance[j]=distance[minV]+edges[minV][j];
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<i<<" "<<distance[i]<<endl;
}
int main()
{
    int V, E;
    cin >> V >> E;

    int **edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }
    
    for(int i=0;i<E;i++){
        int ei,ej,w;
        cin>>ei>>ej>>w;
        edges[ei][ej]=w;
        edges[ej][ei]=w;
    }
    dijk(edges,V);
  return 0;
}
