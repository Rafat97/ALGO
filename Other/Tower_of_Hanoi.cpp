#include<bits/stdc++.h>
using namespace std;
int totalmove = 0;
void TowerRec(int n,int from,int to,int via){

    if(n == 1){
       // printf("\n Move disk 1 from rod %d to rod %d\n", from, to);
        totalmove++;
        return;
    }else{
        TowerRec(n-1,from,via,to);
        //printf("\n Move disk %d from rod %d to rod %d\n", n,from, to);
         totalmove++;
        TowerRec(n-1,via,to,from);
    }
}


struct LinkList{
    int n;
    int i;
    int j;
    int k;
    LinkList *link;
    void print(){
        cout<<n<<" "<<i<<" "<<j<<" "<<k<<"\n";
    }
};
int n = 1,i = 1,j = 2 , k = 3;
LinkList *First = 0;
LinkList *Last = 0;
void push(int n,int i,int j,int k){

    LinkList *L = (LinkList*)malloc(sizeof(LinkList));
    //int val = 0;
    //cout<<"Enter The Value : ";
    //cin>>val;

    if(First == 0 && Last == 0){

        L->n = n;
        L->i = i;
        L->j = j;
        L->k = k;


        L->link = 0;
        First = L;
        Last = L;
    }
    else{
        Last->link = L;
        L->n = n;
        L->i = i;
        L->j = j;
        L->k = k;
        L->link = 0;
        Last = L;
    }
}
void pop(){

    if(First != 0 && Last != 0){
            if(First->link == 0){
                //cout<<"\n"<<First->data<<endl;
                n = First->n;
                i = First->i;
                j = First->j;
                k = First->k;
                //First->print();
                First = 0;Last = 0;
            }else{
                LinkList *pre = First;
                LinkList *post = 0;
                while(pre->link != 0){
                    post = pre;
                    pre = pre->link;
                }
                post->link = 0;

                n = pre->n;
                i = pre->i;
                j = pre->j;
                k = pre->k;
               // pre->print();
                Last = post;
            }
    }
    else{
         cout<<"Stack List Is Empty"<<endl;
    }
}
void display(){
    LinkList *l = First;
    if(First != 0){
        while(l != 0){
            l->print();
            l = l->link;
        }
    }else{
    cout<<"Stack List Is Empty"<<endl;
    }
}
bool stackEmpty(){
    if(First == 0){
        return false;
    }
    else{
        return true;
    }
}

int withoutRec(){
    int cnt = 0;
    push(n,i,j,k);
    //display();
    while(stackEmpty()){
        pop();
        if(n == 1){
           // printf("\n Move disk %d from rod %d to rod %d\n", n,i, k);
            cnt++;
        }
        else{
            push(n-1,j,i,k);
            push(1,i,j,k);
            push(n-1,j,k,j);
        }
    }
  return cnt;

    //display();
    //cout<<5%4<<endl;
}



int main(){

    cout<<"Enter the disk number : ";cin>>n;
    ///from->to->via (Recursion Code);
    TowerRec(n,i,k,j);
    cout<<"Total Movement With Recursion: "<<totalmove<<endl;
      ///from->via->to (Normal Code);
    cout<<"Total Movement Without Recursion: "<<withoutRec()<<endl;

    return 0;
}
