#include "SortingClass.h"
#include <array>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <time.h>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    //declare variables for the time
    typedef std::chrono::high_resolution_clock Time;

    typedef std::chrono::milliseconds ms;

    typedef std::chrono::duration <float> fsec;
    //declare file name
    string fileName;
    //get the file name from the args
    fileName = argv[1];
    //create the file streamer
    ifstream inputStreamer;
    //open the file with the filestreamer
    inputStreamer.open(fileName);
    //test if it could open
    if(!inputStreamer)
    {
        cout << "Unable to open file" << fileName << endl;
        
        exit(1);
    }
    //declare the line variable
    string line = "";
    //get the first line
    getline(inputStreamer,line);
    //check the format
    if(line == "")
    {
        cerr << "File was not correct." << endl;

        exit(1);
    }
//declre the numcounter
    int numCount = 0;
//try to turn the string into an integer and catch the exception if it is not the right format
    try
    {
        numCount = stoi(line);
    }
    catch(invalid_argument e)
    {
        cout << "This is not the right format." << endl;

    }

//declare your array
    double* myBubble = new double[numCount];
    //declare the line count
    int numLine = 0;
//add the numbers to the first array
    while(getline(inputStreamer,line))
    {
         myBubble[numLine] = stod(line);
        numLine++;
    }
    //declare the next array
    double*mySelection = new double[numCount];
    //populate the array aka copy it over
    for(int i = 0; i < numCount; ++i)
    {
        mySelection[i] = myBubble[i];
    }
//declare the third array
    double*myInsertion = new double[numCount];
    //populate it
    for(int i = 0; i < numCount; ++i)
    {
        myInsertion[i] = myBubble[i];
    }
//declare the next array
    double*myQuickSort = new double[numCount];
    //populate the next array
    for(int i = 0; i < numCount; ++i)
    {
        myQuickSort[i] = myBubble[i];
    }


    //Bubble Sort
    cout << "Beginning Bubble Sort At: " << endl;
//start the clock
    auto start = chrono::system_clock::now();
    time_t startTime = chrono::system_clock::to_time_t(start);
    //print the start time
    cout << "Start Time: " << ctime(&startTime);
//call the sorting function
    SortingClass::bubbleSort(myBubble, numCount);
//end the clock
    auto end = chrono::system_clock::now();
    //tell the user it has completed
    cout << "BubbleSort Completed" << endl;
    time_t endTime = chrono::system_clock::to_time_t(end);
    //print out the end time
    cout << "End Time: " << ctime(&endTime);
    //print the time it took
    cout << "Time it took: " << endl;
    fsec seconds = end - start;
    cout << seconds.count() << "seconds. " << endl;


cout << endl;

    //Selection Sort
    cout << "Beginning Selection Sort At: " << endl;
//start the clock
    start = chrono::system_clock::now();
    startTime = chrono::system_clock::to_time_t(start);
    //print the start time
    cout << "Start Time: " << ctime(&startTime);
//run the algorthm
    SortingClass::selectionSort(mySelection, numCount);
//start the clock
    end = chrono::system_clock::now();
    //tell the user it is completed
    cout << "SelectionSort Completed" << endl;
    //end the clock
    endTime = chrono::system_clock::to_time_t(end);
    //print out the time
    cout << "End Time: " << ctime(&endTime);
    cout << "Time it took: " << endl;
    seconds = end - start;
    cout << seconds.count() << "seconds. " << endl;

cout << endl;

    //Insertion Sort
    cout << "Beginning Insertion Sort At: " << endl;
//start the clock
    start = chrono::system_clock::now();
    startTime = chrono::system_clock::to_time_t(start);
    //print the start time
    cout << "Start Time: " << ctime(&startTime);
//run the algorithm
    SortingClass::insertionSort(myInsertion, numCount);
//end the clock
    end = chrono::system_clock::now();
    cout << "InsertionSort Completed" << endl;

    endTime = chrono::system_clock::to_time_t(end);
    //print out the time
    cout << "End Time: " << ctime(&endTime);
    cout << "Time it took: " << endl;
    seconds = end - start;
    cout << seconds.count() << "seconds. " << endl;

cout << endl;

    //Quick Sort
    cout << "Beginning Quick Sort At: " << endl;
//start the clock
    start = chrono::system_clock::now();
    startTime = chrono::system_clock::to_time_t(start);
    //print out the start time
    cout << "Start Time: " << ctime(&startTime);
//call the function
    SortingClass::quickSort(myQuickSort, 0, numCount -1);
//edn the clock
    end = chrono::system_clock::now();
    //let the user know it was completed
    cout << "QuickSort Completed" << endl;
    //pint out the results
    endTime = chrono::system_clock::to_time_t(end);
    cout << "Emd Time: " << ctime(&endTime);
    cout << "Time it took: " << endl;
    seconds = end - start;
    cout << seconds.count() << "seconds. " << endl;







}
