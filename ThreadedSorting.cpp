/**
\file
\brief .cpp file with main
*/
#include "threadedMergesort.h"
#include "threadedQuicksort.h"
#include "ordinaryMergeSort.h"
#include "ordinaryQuickSort.h"

void getInput(short& alg, short& numThreads, long& dataSize) 
{
    cout << "Select sorting algorithm (0-quit 1-quicksort 2-mergesort): ";
    cin >> alg;
    if (alg > 0) 
    {
        cout << "# threads (0 to quit): ";
        cin >> numThreads;
        if (numThreads > 0) 
        {
            cout << "# data elements (0 to quit): ";
            cin >> dataSize;
        }
    }
}

int main() 
{
    short numThreads;
    long dataSize;
    short alg;
    getInput(alg, numThreads, dataSize);

    while (numThreads > 0 && dataSize > 0 && alg > 0) 
    {
        long* bob = new long[dataSize];
        bool failure = false;
        for (long j = 0; j < dataSize; j++) 
        {
            bob[j] = rand() % dataSize;
        }
        cout << endl;

        long* test = new long[dataSize];
        for (unsigned i = 0; i < dataSize; i++)
            test[i] = bob[i];

        chrono::time_point<std::chrono::system_clock> start, end;
        chrono::duration<double> elapsed_seconds;

        switch (alg) 
        {
        case 1:
            start = chrono::system_clock::now();
            myQuicksort(bob, dataSize, numThreads);
            end = chrono::system_clock::now();
            elapsed_seconds = end - start;
            cout << elapsed_seconds.count() << " seconds." << endl;

            start = chrono::system_clock::now();
            quickSort(test, 0, dataSize - 1);
            end = chrono::system_clock::now();
            elapsed_seconds = end - start;
            cout << elapsed_seconds.count() << " seconds." << endl;

            break;

        case 2:
            start = chrono::system_clock::now();
            myMergesort(bob, dataSize, numThreads);
            end = chrono::system_clock::now();
            elapsed_seconds = end - start;
            cout << elapsed_seconds.count() << " seconds." << endl;

            start = chrono::system_clock::now();
            merge_sort(test, 0, dataSize - 1);
            end = chrono::system_clock::now();
            elapsed_seconds = end - start;
            cout << elapsed_seconds.count() << " seconds." << endl;
            break;
        }

        for (long k = 0; k < dataSize - 1; k++) 
        {
            if (bob[k + 1] < bob[k] && test[k + 1] < test[k]) 
            {
                failure = true;
                break;
            }
        }

        cout << (failure ? "test failed" : "test passed") << endl;
        cout << endl;
        delete[] bob;
        delete[] test;

        getInput(alg, numThreads, dataSize);
    }

    return 0;
}