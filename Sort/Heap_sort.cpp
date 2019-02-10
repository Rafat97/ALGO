#include<bits/stdc++.h>
using namespace std;

// this print array use the Array total size not index
void print_array(int arr[],int arr_size)
{
    for(int i = 0 ;i < arr_size ; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

}

//this right element is pass array index not size of array
int right_element(int parent_index){
    return (parent_index * 2) + 1;
}

//this built heap is pass array index not size of array
int left_element(int parent_index){
    return (parent_index * 2) ;
}

//this built heap is pass array index not size of array
void heapfy(int arr[] , int arr_size ,int parent_index){
    int Large_element_index = parent_index;

    int parent_Leftelement_index = left_element(parent_index);
    int parent_rightelement_index = right_element(parent_index);

    if(arr[Large_element_index] < arr[parent_Leftelement_index]   &&   parent_Leftelement_index < arr_size){
        Large_element_index = parent_Leftelement_index;
    }
    if(arr[Large_element_index] < arr[parent_rightelement_index]  && parent_rightelement_index < arr_size){
         Large_element_index = parent_rightelement_index;
    }

    if(Large_element_index != parent_index){
         swap(arr[parent_index], arr[Large_element_index]);
         heapfy(arr , arr_size , Large_element_index);
    }
}

//this built heap is pass array index not size of array
void Built_Heap(int arr[] , int arr_size){

    for(int i = floor(arr_size/2) ; i>=0 ;i--){
        heapfy(arr,arr_size , i);
    }
}

// this hear sort use the Array total size not index
void Heap_Sort(int arr[] , int arr_size){
    int siz = arr_size;
   /* for(int i = 0 ;i < siz ;i++){
        Built_Heap(arr , siz);
        swap(arr[0] , arr[siz-1]);
        siz -= 1;
        i = 0;
    }
    */
    Built_Heap(arr , siz);
    for(int i = siz - 1; i >= 0;i--){
        swap(arr[0] , arr[i]);
        heapfy(arr , i , 0);

    }
}


int main()
{

    //int arr[] ={9,8,7,6,85,15,6,5,100,4,4};
/*
    int n;
    cout<<"Enter the size of array : " ;
    cin>>n;
    int arr[n];
    cout<<"\nEnter the array element: "<<endl;
    for(int i =0;i<n ;i++){
        cin>>arr[i];
    }
*/
    int arr[] = {12, -11, 13,-6, 5, -6, 7 , 13};

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    Heap_Sort(arr , arr_size);

    print_array(arr,arr_size);

    return 0;
}
