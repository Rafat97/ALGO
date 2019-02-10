#include<bits/stdc++.h>

using namespace std;

///this is input as a index not size
int pretision_Last_Element(int arr[] , int start_val , int end_val)
{
    int pivot = arr[end_val];

    ///
    int i = start_val - 1;
    for(int j = start_val ; j <= end_val - 1 ;j++ ){
        if(arr[j] <= pivot){
            i++;
            int temp  = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp  = arr[end_val];
    arr[end_val] = arr[i+1];
    arr[i+1] = temp;

    return (i + 1);
}

///this is input as a index not size
int pretision_First_Element(string arr[] , int start_val , int end_val)
{
    string pivot = arr[start_val];

    ///
    int i = start_val + 1;
    for(int j = start_val + 1  ; j <= end_val  ;j++ ){
        if(arr[j] < pivot){

            string temp  = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
        }
    }
    string temp  = arr[start_val];
    arr[start_val] = arr[i-1];
    arr[i-1] = temp;

    return (i - 1);
}

void Quick_Sort(string arr[] , int start_val, int end_val)
{
    if(start_val >= end_val){
        return;
    }
    else{
        int part = pretision_First_Element(arr , start_val , end_val );

        Quick_Sort(arr , start_val , part - 1);
        Quick_Sort(arr , part + 1 , end_val);

    }
}
int main()
{
    int arr[] ={9,8,7,6,6,5,4,4};
    string s[] = {"q","r","m","f","g","k","621","a"};

    Quick_Sort(s , 0 ,7);

    for(int i = 0; i < sizeof(s)/sizeof(s[0]) ;i++){
        cout<<s[i]<<"  "<<s[i].length()<<endl;

    }


    return 0;
}
