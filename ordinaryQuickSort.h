/**
\file
\brief .h file of class OrdinaryQuickSort

implementation of ordinary quick sort algorithm
*/

#pragma once
#include "utility.h"


/**
\brief class that contains functions for ordinary quick sort algorithm
*/
class OrdinaryQuickSort {
public:
    /**
    \brief function that swaps two elements

    \param a first element
    \param b second element
    */
	template<class T>
	void swap(T* a, T* b);

    /**
    \brief This function takes last element as pivot, places the pivot element at its correct position in sorte array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot

    \param A first element
    \param p first element
    \param r ending pivot index (length)
    */
	template<class T>
	int partition(T* A, int p, int r);

    /**
    \brief function that implements ordinary(not multithreaded) quicksort algorithm

    \param A array to be sorted
    \param p starting index
    \param r ending index (length)
    */
	template<class T>
	void quickSort(T* A, int p, int r);
};

template<class T>
inline void OrdinaryQuickSort::swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template<class T>
inline int OrdinaryQuickSort::partition(T* A, int p, int r)
{
    T x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return (i + 1);
}

template<class T>
inline void OrdinaryQuickSort::quickSort(T* A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}