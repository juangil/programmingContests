# include <bits/stdc++.h>

using namespace std;



/*
    merge-sort: the input of the algorithm is an array of integers in some order
                a is the original array and b is the array where the algorithm is going
                to store the sorted array. low and high are the index where the array a
                is going to be accesed(the beginning and the end pointers).
                the key idea is to divide the array in smaller subarrays in order to solve
                the problem to smaller arrays merging them in order to have the solution
                to the big problem.
*/


void merge(int*, int*, int, int, int);
void mergeSort(int *a, int *b, int low, int high){
    int pivot; // the median of the array a.
    if(low < high){ // if low is less than high its because we have a single element array 
        pivot = (low+high)/2; //the array a is going to be partioned  in two parts.
        mergeSort(a, b, low, pivot); //the left half of the array.
        mergeSort(a, b, pivot+1, high); //the right half of the array.
        merge(a, b, low, pivot, high); //the merging part of the sort the algorithm needs to know where the left and right parts starts and ends respectively.
    }
}

void merge(int *a, int *b, int low, int pivot, int high){
    int h,i,j,k;
    h = low; //Pointer to the first half of the array
    i = low; //pointer for all the array
    j = pivot + 1;//Pointer to the second half of the array
    while((h <= pivot) && (j <= high)){
        if(a[h] <= a[j]){//if the element in the first half of the array is already less than in the second half we make not inversion.
            b[i] = a[h];
            h++;// we increment the pointer to the array
        }
        else{
            b[i] = a[j];//if the element in the first half of the array greater that in the second half we make an inversion.
            j++;//we increment the pointer of teh first half.
        }
        i++;
    }
    if(h > pivot){//processing the second half of the array when everything in the first half is ordered.
        for(k = j; k <= high; k++){
            b[i] = a[k];//the algorithm needs to store right part of the arrray in the sorted array.
            i++;
        }
    }
    else{//processing what lefts in the left side of the array
        for(k = h; k <= pivot; k++){
            b[i] = a[k];
            i++;
        }
    }
    for(k = low; k <= high; k++)a[k] = b[k];//updating all the array(a) with sorted part.
    
}






int main(){
    int n;cin >> n;
    int a[n];
    int b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    int low = 0, high = n - 1;
    mergeSort(a, b, 0, n - 1);
    
    for(int i = 0; i < n; ++i)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
