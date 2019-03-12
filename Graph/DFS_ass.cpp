#include<bits/stdc++.h>

#define GRAY 1
#define WHITE 0
#define BLACK 2
#define ArraySizeMax 100000000

using namespace std;


int color[ArraySizeMax];
void dfs(vector<int> graph[], int startNode ,int vertices , int edge){
    color[startNode] = GRAY;

    for(int i = 0 ;i < graph[startNode].size() ; i++){
        int v = graph[startNode][i];

        if(color[v] == WHITE){
            dfs(graph,v,vertices,edge);
        }
    }
    color[startNode] = BLACK;
    cout<<startNode<<" ";
}

int main()
{

    int vertices = 5; int edge = 4,val_1,val_2;
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


    cout<<"\nDFS Result : ";
    dfs(graph , val_1 , vertices , edge);



    return 0;
}
