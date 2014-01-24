# include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

//lli x = 0,y = 0,z = 0;
/*
    merge-sort: the input of the algorithm is an array of integers in some order
                a is the original array and b is the array where the algorithm is going
                to store the sorted array. low and high are the index where the array a
                is going to be accesed(the beginning and the end pointers).
                the key idea is to divide the array in smaller subarrays in order to solve
                the problem to smaller arrays merging them in order to have the solution
                to the big problem.
*/


int mergeCount(int*, int*, int, int, int);
int mergeSortInversionCount(int *a, int *b, int low, int high){
    int pivot; // the median of the array a.
    lli x = 0,y = 0,z = 0;
    if(low < high){ // if low is less than high its because we have a single element array 
        pivot = (low+high)/2; //the array a is going to be partioned  in two parts.
        x += mergeSortInversionCount(a, b, low, pivot);
        //cout<<x<<endl; //the left half of the array.
        y += mergeSortInversionCount(a, b, pivot+1, high);
        //cout<<y<<endl; //the right half of the array.
        z = mergeCount(a, b, low, pivot, high); //the merging part of the sort the algorithm needs to know where the left and right parts starts and ends respectively.
        //cout<<endl;
    }
    else return 0;
    
    return x+y+z;
}

int mergeCount(int *a, int *b, int low, int pivot, int high){
    int h,i,j,k;
    h = low; //Pointer to the first half of the array
    i = low; //pointer for all the array
    j = pivot + 1;//Pointer to the second half of the array
    int countInversions = 0;
    while((h <= pivot)){
        if(j > high){
            j = pivot+1;
            h++;
        }
        
        if(a[h] <= a[j])
            j++;
        else{
            //cout<<a[h]<<" by "<<a[j]<<" - ";
            j++;
            countInversions++;
        }
    }
    cout<<endl;
    return countInversions;
}


int main(){
    int n;cin >> n;
    int a[n];
    int b[n];
    //x = 0; y = 0; z = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    int low = 0, high = n - 1;
    cout<<"Number of Inversions: "<<mergeSortInversionCount(a, b, 0, n - 1)<<endl;
    
    /*for(int i = 0; i < n; ++i)
        cout<<a[i]<<" ";
    cout<<endl;*/
    return 0;
}
