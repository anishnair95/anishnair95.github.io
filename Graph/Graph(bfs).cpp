#include <iostream>
#include<map>
#include<list>
#include<string>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    public:
    map<T,list<T>>l;


    void addEdge(T x,T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
        
    }
    void bfs(int src)
   {
     map<T,int>visited;
     queue<T>q;

     q.push(src);              //pushing src node;
     visited[src]=true;      //marking visited

     while(!q.empty())
     {
          T node=q.front();
          q.pop();          //       1.popping front element
          cout<<node<<" ";          
                                     //2. inserting unvisited nbr of popped element and marking as visited
          for(auto nbr:l[node])
          {
              if(!visited[nbr])
              {                      
                  q.push(nbr);
                  visited[nbr]=true;    
              }
          }

     }
   }


};
int main() {
    Graph <int>g;
    /*g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);*/
    
    int src,dest,st,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>src>>dest;
        g.addEdge(src,dest);

    }
    cin>>st;

    g.bfs(st);
    return 0;    
}
