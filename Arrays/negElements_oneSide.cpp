//An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

#include <bits/stdc++.h>
using namespace std;
 
void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}
 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
 
int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}

//Output: -1 -3 -7 4 5 6 2 8 9
//Time complexity: O(N) 
//Auxiliary Space: O(1)


//using double pointer approach

 
#include <iostream>
using namespace std;
 
// Function to shift all the
// negative elements on left side
void shiftall(int arr[], int left,
              int right)
{
   
  // Loop to iterate over the
  // array from left to the right
  while (left<=right)
  {
    // Condition to check if the left
    // and the right elements are
    // negative
    if (arr[left] < 0 && arr[right] < 0)
      left+=1;
     
    // Condition to check if the left
    // pointer element is positive and
    // the right pointer element is negative
    else if (arr[left]>0 && arr[right]<0)
    {
      int temp=arr[left];
      arr[left]=arr[right];
      arr[right]=temp;
      left+=1;
      right-=1;
    }
     
    // Condition to check if both the
    // elements are positive
    else if (arr[left]>0 && arr[right] >0)
      right-=1;
    else{
      left += 1;
      right -= 1;
    }
  }
}
 
// Function to print the array
void display(int arr[], int right){
   
  // Loop to iterate over the element
  // of the given array
  for (int i=0;i<=right;++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
 
// Driver Code
int main()
{
  int arr[] = {-12, 11, -13, -5,
               6, -7, 5, -3, 11};
  int arr_size = sizeof(arr) /
                sizeof(arr[0]);
   
  // Function Call
  shiftall(arr,0,arr_size-1);
  display(arr,arr_size-1);
  return 0;
}