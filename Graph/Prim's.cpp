#include<bits/stdc++.h>

#define ArraySizeMax 100000000
using namespace std;

vector< pair<int , int> > graph[100];
int n ;


void prims(int startNode){

    priority_queue <int> MinHeap;


    vector<int> key(n , INT_MAX);
    vector<bool> inMST(n, false);

    vector<int> parent(n, -1);


    key[startNode] = 0;
    inMST[startNode] = true;
    MinHeap.push(-(startNode));



    while(!MinHeap.empty()){

        int u =  (MinHeap.top()) * -1;

        MinHeap.pop();
        inMST[u]  = true;


        for(int i = 0;i < graph[u].size() ;i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;


            if(inMST[v] == false && key[v] >= w  ){
                key[v] = w;
                int val = v * (-1);
                MinHeap.push(val);
                parent[v] = u;
            }

        }


    }

    cout<<"\n\n";
    //vector<int>:: iterator it ;
    int index = 0;
    int mst = 0;
    for(int i = 0; i < parent.size()   ;i++){
        cout<<index<<"->"<<i<<" "<<key[index]<<endl;
        mst += key[index];
        index++;

    }

    cout<<"\n\nMST is : "<<mst<<endl;




}

int main()
{
    /*
    4 5
    0 1 4
    0 2 8
    1 2 8
    1 3 2
    2 3 5
    1
*/


    int node,edge,u,v,w,startingNode;
    cin>>node>>edge;
    n = node;
    for(int i = 0;i<edge;i++){
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
    cin>>startingNode;
    prims(startingNode);



   /*
    n = 4;
    graph[0].push_back(make_pair(1,4));
    graph[1].push_back(make_pair(0,4));

    graph[0].push_back(make_pair(2,8));
    graph[2].push_back(make_pair(0,8));

    graph[1].push_back(make_pair(2,8));
    graph[2].push_back(make_pair(1,8));


    graph[2].push_back(make_pair(3,5));
    graph[3].push_back(make_pair(2,5));

    graph[3].push_back(make_pair(1,2));
    graph[1].push_back(make_pair(3,2));

    prims(1);

*/

    return 0;
}
