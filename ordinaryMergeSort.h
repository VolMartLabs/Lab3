/**
\file
\brief .h file of class OrdinaryMergeSort

implementation of ordinary merge sort algorithm
*/

#pragma once
#include "utility.h"

/**
\brief class that contains functions for ordinary merge sort algorithm
*/
class OrdinaryMergeSort {
public:
    /**
    \brief function that merges subarrays into one sorted array

    \param v first element first array pointer
    \param p starting index (pivot)
    \param q middle of array
    \param r ending index
    */
    template<class T>
    void merge(T* v, int p, int q, int r);

    /**
    \brief function that implements ordinary(not multithreaded) merge sort algorithm

    \param v first element first array pointer
    param p left index of subarray (pivot)
    \param r right index of subarray
    */
    template<class T>
    void merge_sort(T* v, int p, int r);
};

template<class T>
inline void OrdinaryMergeSort::merge(T* v, int p, int q, int r)
{
    int size1 = q - p + 1;
    int size2 = r - q;
    std::vector<T> L(size1);
    std::vector<T> R(size2);

    for (int i = 0; i < size1; i++)
    {
        L[i] = v[p + i];
    }
    for (int j = 0; j < size2; j++)
    {
        R[j] = v[q + j + 1];
    }

    int i = 0, j = 0;
    int k;
    for (k = p; k <= r && i < size1 && j < size2; k++)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }
    for (i = i; i < size1; ++i)
    {
        v[k] = L[i];
        k++;
    }

    for (j = j; j < size2; j++)
    {
        v[k] = R[j];
        k++;
    }
}

template<class T>
inline void OrdinaryMergeSort::merge_sort(T* v, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(v, p, q);
        merge_sort(v, q + 1, r);
        merge(v, p, q, r);
    }
}