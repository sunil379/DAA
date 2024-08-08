#include<iostream>
using namespace std;

int binary_search(int array[],int key,int low,int high){
    int mid = 0;
    while (low<=high){
        int mid = low + (high-low)/2;
    if (array[mid]==key){
        return mid;
    }
    else if(array[mid]<key){
        low = mid + 1;
    }
    else{
        high = mid -1;
    }
    }
}

int main()
{
    int arr[] = {26,57,60,61,64,77,88};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 88;
    int result = binary_search(arr,key,0,n-1);
    if (result==-1){
        cout<<"Target element is not present in Array."<<endl;
    }
    else{
        cout<<"Target element is present at index : "<<result<<endl;
    }

    return 0;
}
