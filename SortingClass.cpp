#include <iostream>
#include "SortingClass.h"
using namespace std;
//sorting class
void SortingClass::bubbleSort(double *A, int n)
{
    //swapped variable
    bool swapped;
    for(int i = 0; i < n-1; ++i)
    {
        swapped = false;
        for(int j = 0; j < n-i-1; ++j)
        {
            if(A[j] > A[j+1])
            {
                swap(A[j], A[j+1]);
                swapped = true;
//go through each element
            }
        }
        if(swapped == false)
        {
            break;
        }
    }
}
//insertion sort
void SortingClass::insertionSort(double array[], int n)
{
    //declare values for k and j
    double k;
    int j;
    for(int i = 1; i < n; ++i)
    {
        k = array[i];
        j = i;
        //both must be true to enter loop
        while(j > 0 && array[j-1] > k)
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = k;
    }
}
//selection sort
void SortingClass::selectionSort(double arr[], int n)
{
    //for loop
    for(int i = 0; i < n-1; ++i)
    {
        int minIdx = i;
        for(int j = i+1; j < n; ++j)
        {
            if(arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        //temp variable to store
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}
//quick sort algorithm
void SortingClass::quickSort(double *A, int start, int end)
{
    //if the start is less than the end
    if(start < end)
    {
        int pIndex = Partition(A, start, end);
        quickSort(A, start, pIndex-1);
        quickSort(A, pIndex+1, end);
    }
}
//function to aid quick sort
double SortingClass::Partition(double *A, int start, int end)
{
    //declare pivot point
    int pivpoint = A[end];
    int pIndex = start;
    for(int i = start; i < end; ++i)
    {
        if(A[i] <= pivpoint)
        {
            //swap the two
            swap(A[i], A[pIndex]);
            pIndex++;
        }
    }

    swap(A[pIndex], A[end]);
    return pIndex;
}
