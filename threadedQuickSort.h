/**
\file
\brief .h file of class ThreadedQuickSort

implementation of threaded quick sort algorithm
*/

#pragma once
#include "utility.h"


/**
\brief class that contains functions for threaded quick sort algorithm
*/
class ThreadedQuickSort {
public:
    /**
    \brief function that implements parallel quicksort algorithm

    \param arr first element array pointer
    \param min starting index
    \param max ending index (length - 1)
    \param numThreads number of threads which user has entered
    */
    template<typename T>
    static void quicksortRecursive(T* const arr, const long min, const long max, const short numThreads = 1);

    /**
    \brief function that implements parallel quicksort algorithm

    \param arr first element array pointer
    \param length length of array
    \param numThreads number of threads which user has entered
    */
    template<typename T>
    void myQuicksort(T* const arr, const long length, const short numThreads = 1);
};

template<typename T>
inline static void ThreadedQuickSort::quicksortRecursive(T* const arr, const long min, const long max, const short numThreads) {
    if (max <= min) 
    {
        return;
    }
    long high = max;
    long low = min;
    long pivotIndex = (max + min + 1) / 2;
    T pivotValue = arr[pivotIndex];
    while (high > low) 
    {
        if (high > pivotIndex) 
        {
            if (arr[high] < pivotValue) 
            {
                arr[pivotIndex] = arr[high];
                pivotIndex++;
                arr[high] = arr[pivotIndex];
            }
            else 
            {
                high--;
            }
        }
        if (low < pivotIndex) 
        {
            if (pivotValue < arr[low]) 
            {
                arr[pivotIndex] = arr[low];
                pivotIndex--;
                arr[low] = arr[pivotIndex];
            }
            else 
            {
                low++;
            }
        }
    }
    arr[pivotIndex] = pivotValue;

    if (numThreads == 1) 
    {
        quicksortRecursive(arr, min, pivotIndex - 1, 1);
        quicksortRecursive(arr, pivotIndex + 1, max, 1);
    }
    else 
    {
        short numThreadsOnFirstHalf = 1;
        if (numThreads > 2) 
        {
            long problemSize1 = pivotIndex - min;
            long problemSize2 = max - pivotIndex;
            numThreadsOnFirstHalf = ((numThreads * problemSize1) + (problemSize2 >> 1)) / (problemSize2 + problemSize1);
            if (numThreadsOnFirstHalf <= 0) 
            {
                numThreadsOnFirstHalf = 1;
            }
            else if (numThreadsOnFirstHalf >= numThreads - 1) 
            {
                numThreadsOnFirstHalf = numThreads - 1;
            }
        }
        thread t1(&ThreadedQuickSort::quicksortRecursive<T>, arr, min, pivotIndex - 1, numThreadsOnFirstHalf);
        thread t2(&ThreadedQuickSort::quicksortRecursive<T>, arr, pivotIndex + 1, max, numThreads - numThreadsOnFirstHalf);
        t1.join();
        t2.join();
    }
}

template<typename T>
inline void ThreadedQuickSort::myQuicksort(T* const arr, const long length, const short numThreads) 
{
    quicksortRecursive(arr, 0, length - 1, numThreads);
}
