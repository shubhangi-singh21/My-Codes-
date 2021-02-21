//To find pair with maximum GCD in an array  

#include <bits/stdc++.h> 
  
using namespace std; 
  
// function to find GCD of pair with 
// max GCD in the array 
int findMaxGCD(int arr[], int n) 
{ 
    // Computing highest element 
    int high = 0; 
    for (int i = 0; i < n; i++) 
        high = max(high, arr[i]); 
  
    // Array to store the count of divisors 
    // i.e. Potential GCDs 
    int divisors[high + 1] = { 0 }; 
  
    // Iterating over every element 
    for (int i = 0; i < n; i++) 
    { 
        // Calculating all the divisors 
        for (int j = 1; j <= sqrt(arr[i]); j++) 
        { 
            // Divisor found 
            if (arr[i] % j == 0) 
            { 
                // Incrementing count for divisor 
                divisors[j]++; 
  
                // Element/divisor is also a divisor 
                // Checking if both divisors are 
                // not same 
                if (j != arr[i] / j) 
                    divisors[arr[i] / j]++; 
            } 
        } 
    } 
  
    // Checking the highest potential GCD 
    for (int i = high; i >= 1; i--) 
      
        // If this divisor can divide at least 2 
        // numbers, it is a GCD of at least 1 pair 
        if (divisors[i] > 1) 
            return i;   
return 0;  
} 
  
// Driver code 
int main() 
{ 
    // Array in which pair with max GCD 
    // is to be found 
    int arr[1000000]; 
    int n;
    // Size of array 
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i]; 
  
    // cout << findMaxGCD(arr,n);
    
    int res=findMaxGCD(arr,n);
    if(res<1)
        cout<<-1;
    else
        cout<<res; 
    return 0; 
}
