/****

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that
for every directed edge uv, vertex u comes before v in the ordering.
Topological Sorting for a graph is not possible if the graph is not a DAG.

*/
#include<bits/stdc++.h>

#define GREY 1
#define WHITE 0

using namespace std;

vector<int> color;
stack<int> stackValue;
void TopologicalSort(vector<int> Graph[] , int st){
    color[st] = GREY;
    int sz = Graph[st].size();
    for(int i = 0 ; i < sz ; i++){
        int v = Graph[st][i];
        if(color[v] == WHITE){
            TopologicalSort(Graph , v);
        }
    }

    stackValue.push(st);
}

int main()
{
    int vertices = 6; int edge = 7,val_1,val_2;
    vector<int> graph[1000];

    cout<<"vertices & edge :\n";
    cin>>vertices>>edge;
    cout<<"\nu->v :\n";
    for(int i = 1; i <= edge ;i++){
        cin>>val_1>>val_2;
        graph[val_1].push_back(val_2);
    }



    color.assign(vertices,0);

   /* graph[0];
    graph[1];
    graph[2].push_back(3);
    graph[3].push_back(1);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[5].push_back(0);
    graph[5].push_back(2);
*/


    for(int i = 0 ;i < vertices;i++){
    //cout<<color.size();
        if(color[i] == WHITE){
            TopologicalSort(graph , i);
        }

    }


    while(!stackValue.empty()){
        int v = stackValue.top();
        cout<<v<<"  ";
        stackValue.pop();
    }


    return 0;
}
