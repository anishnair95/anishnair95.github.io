#include <iostream>
#include<map>
#include<queue>
#include<climits>
#include<list>
using namespace std;
template<typename T>

class Graph{
    public:
    map<int,list<int>>l;

    void addEdge(T x,T y)
    {
      l[x].push_back(y);
      l[y].push_back(x);

    }


   void bfs(T src)
   {
     map<int,int>dist;
     queue<int>q;
         

    for(auto nodepair:l)
    {
        T node=nodepair.first;
        dist[node]=INT_MAX;

    }
    q.push(src);
    dist[src]=0;
    

    while(!q.empty())
    {
        T node=q.front();
        q.pop();

        for(auto nbr:l[node])
        {
            if(dist[nbr]==INT_MAX)
            {
                q.push(nbr);
                dist[nbr]=dist[node]+1;
                

            }
        }     

    }

    for(auto p:dist)
    {
        cout<<"Node "<<p.first<<" from src :"<<p.second<<endl;
    }
    

   }

};
int main() {
    
    Graph <int>g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);
    return 0;
}
