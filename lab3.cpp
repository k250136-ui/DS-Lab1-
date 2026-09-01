#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n){
    //{3,4,5,,2,1}
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
          if (arr[j] > arr[j+1])
          {
            swap(arr[j],arr[j+1]);
          }
         
        }
       
    }
   
}
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   
}

void selectionSort(int arr[], int n){
   
   for (int i = 0; i < n-1; i++)
   {
    int smallest_index=i;
    for (int j = i+1; j < n; j++)
    {   if (arr[j]<arr[smallest_index])
        {
            smallest_index=j;
        }  
    }
    swap(arr[i], arr[smallest_index]);
    }
}


void InsertionSort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
       int current=arr[i];
       bool isSwap=false;
       cout<<"initially current is"<< current<<endl;
       int prev=i-1;
       while (prev >= 0 && arr[prev] > current)
       {
        cout<<"currently array of previous is "<<arr[prev] << " and arr[previous+1] is "<< arr[prev+1]<<endl;;
        arr[prev+1] = arr[prev];
        prev--;
        isSwap=true;

       }
       arr[prev+1]=current;
       if (isSwap)
       {
        cout<<"Now current is"<< current<<endl;
       }
       
       
       printArray(arr,n);
    }
   
}

void ShellSort(int arr[], int n)
{
    // Start with a large gap
    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {    //int arr[]={2,1,3,1,5};
            cout<<"gap is : "<<gap<<endl;

        // Perform insertion sort with this gap

        for (int i = gap; i < n; i++)
        {
            int key = arr[i];
            cout<<"key is : "<<key<<endl;
            int j = i;
            cout<<"value of j is : "<<j<<endl;

            // Shift elements that are greater than key
            cout<<"array [j-gap] is : "<<arr[j-gap]<<endl;
            while (j >= gap && arr[j - gap] > key)
            {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            cout<<"array [j] is = : "<<arr[j]<<endl;
            // Put key at its correct position
            arr[j] = key;
           
            cout<<"key in 2nd loop is : "<<key<<endl;

        }
    }
}

void combSort(int arr[], int n)
{
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap = gap / 1.3;

        if (gap < 1)
            gap = 1;

        swapped = false;

        for (int i = 0; i + gap < n; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}


int main(){
    int n=5;
    int arr[]={2,1,3,1,5};
    //printArray(arr,n);
   BubbleSort(arr,n);
   //selectionSort(arr,n);
   //InsertionSort(arr, n);
  // ShellSort(arr, n);
    printArray(arr,n);
}