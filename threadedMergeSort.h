/**
\file
\brief .h file of class ThreadedMergeSort

implementation of threaded merge sort algorithm
*/

#pragma once

/**
\brief class that contains functions for threaded merge sort algorithm
*/
class ThreadedMergeSort {
public:
    /**
    \brief function that traverses both arrays, copies to the original interval(source) and merges both arrays

    \param source first element first subarray pointer
    \param dest first element second subarray pointer
    \param min starting index
    \param mid middle of array
    \param max ending index (length - 1)
    */
    template<typename T>
    static void myMerge(const T* const source, T* const dest, const long min, const long mid, const long max);

    /**
    \brief function that does partitions of target array and distributes computing between threads(or not it depends on how much threads user uses)

    \param target target array in which sortings take place
    \param auxiliary explicit auxiliary temp stack
    \param min starting index
    \param max ending index (length - 1)
    \param numThreads number of threads which user has entered
    */
    template<typename T>
    static void myMergesortRecursive(T* target, T* auxiliary, const long min, const long max, const short numThreads);

    /**
    \brief function that implements parallel merge sort algorithm

    \param target target array in which sortings take place
    \param length length of array
    \param numThreads number of threads which user has entered
    */
    template<typename T>
    void myMergesort(T* target, const long length, const short numThreads = 1);
};

#include "utility.h"

template<typename T>
inline static void ThreadedMergeSort::myMerge(const T* const source, T* const dest, const long min, const long mid, const long max) {
    long destIndex = min;
    long lowerIndex = min;
    long upperIndex = mid;

    // traverse both arrays and in each iteration add smaller of both elements in dest 
    while (destIndex <= max) 
    {
        if (upperIndex > max || (lowerIndex < mid && source[lowerIndex] < source[upperIndex])) 
        {
            dest[destIndex] = source[lowerIndex];
            lowerIndex++;
        }
        else 
        {
            dest[destIndex] = source[upperIndex];
            upperIndex++;
        }
        destIndex++;
    }
}

template<typename T>
inline static void ThreadedMergeSort::myMergesortRecursive(T* target, T* auxiliary, const long min, const long max, const short numThreads)
{
    if (min == max) 
    {
        return;
    }
    long mid = (max + min + 1) / 2;
    if (numThreads >= 2)
    {
        thread f1(&ThreadedMergeSort::myMergesortRecursive<T>, auxiliary, target, min, mid - 1, numThreads / 2);
        thread f2(&ThreadedMergeSort::myMergesortRecursive<T>, auxiliary, target, mid, max, (numThreads + 1) / 2);
        f1.join();
        f2.join();
    }
    else 
    {
        myMergesortRecursive(auxiliary, target, min, mid - 1, 1);
        myMergesortRecursive(auxiliary, target, mid, max, 1);
    }
    ThreadedMergeSort::myMerge(auxiliary, target, min, mid, max);
}

template<typename T>
inline void ThreadedMergeSort::myMergesort(T* target, const long length, const short numThreads) {
    T* auxiliary = new T[length];
    for (long k = 0; k < length; k++) 
    {
        auxiliary[k] = target[k];
    }

    myMergesortRecursive(target, auxiliary, 0, length - 1, numThreads);

    delete[] auxiliary;
}