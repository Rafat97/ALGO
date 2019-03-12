#include<bits/stdc++.h>

#define ArraySizeMax 100000000

using namespace std;


int visited[ArraySizeMax];
int level[1000];
void bfs(vector<int> graph[], int startNode ,int vertices , int edge){

      queue<int> q;

      q.push(startNode);
      visited[startNode] = 1;
        level[startNode] = 0;
      while(!q.empty()){
        int u = q.front();
        cout<<u<<"  ";
        ///<<level[u]<<endl;
        q.pop();

        for(int i = 0;i < graph[u].size();i++){
            if(visited[graph[u][i]] == 0){
                int v = graph[u][i];
                q.push(v);
                visited[v] = 1;
                ///level[v] = level[u] + 1;
            }
        }
      }
}




int main()
{

    int vertices = 6; int edge = 7,val_1,val_2;
    vector<int> graph[100];

    cout<<"vertices & edge :\n";
    cin>>vertices>>edge;
    cout<<"\nu->v :\n";
    for(int i = 1; i <= edge ;i++){
        cin>>val_1>>val_2;
        graph[val_1].push_back(val_2);
    }


/*
    graph[1].push_back(2);
    graph[1].push_back(5);

    graph[2].push_back(5);
    graph[2].push_back(3);
    graph[2].push_back(1);

    graph[3].push_back(2);
    graph[3].push_back(4);

    graph[4].push_back(5);
    graph[4].push_back(3);
    graph[4].push_back(6);

    graph[5].push_back(1);
    graph[5].push_back(4);
    graph[5].push_back(2);

    graph[6].push_back(4);

*/

///2nd input
/*

    graph[1].push_back(2);

    graph[2].push_back(3);
    graph[2].push_back(1);

    graph[3].push_back(4);
    graph[3].push_back(2);
    graph[3].push_back(4);


    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(4);
*/

    cout<<"Starting Vertices : \n";cin>>val_1;


    cout<<"\n\nBFS Result : ";
    bfs(graph , val_1 , vertices , edge);



    return 0;
}
