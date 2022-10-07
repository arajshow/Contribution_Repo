/*
Program :Radix Sort
Author : Kunal Khairnar
*/

#include<iostream>
using namespace std;

int Getmax(int arr[],int size){
    int max=arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }

    }
    return max;
}

void CountingSort(int arr[],int size,int div){
    int output[size];
    int count[10]={0};

    for (int i = 0; i < size; i++)
    {
        count[(arr[i]/div)%10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i]+=count[i-1];
    }
    for (int i = size-1; i >= 0; i--)
    {
        output[count[(arr[i]/div)%10 ]-1]=arr[i];
        count[(arr[i]/div)%10]--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i]=output[i];
    }

}

void radixSort(int arr[],int size){
    int m = Getmax(arr,size);

    for (int div= 1; m/div >0; div*=10)
    {
        CountingSort(arr,size,div);
    }

}

int main(){
int size;
cout<<"Enter size of array: ";
cin>>size;

int arr[size];
cout<<"Enter "<<size<<" integers in any order : "<<endl;

for(int i=0;i<size;i++){
    cin >> arr[i];
}

for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}

    cout<<endl;
    radixSort(arr,size);

for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}
