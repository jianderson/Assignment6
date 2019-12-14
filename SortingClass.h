#include <iostream>
#include <array>
using namespace std;

class SortingClass
{
public:
    //declare functions
    static void bubbleSort(double *A, int n);
    static void insertionSort(double array[], int n);
    static void selectionSort(double array[], int n);
    static void quickSort(double *A, int start, int end);
    static double Partition(double *A, int start, int end);
};
