#include "logger.h"

#include "ordinaryMergeSort.h"
#include "threadedMergeSort.h"
#include "ordinaryQuickSort.h"
#include "threadedQuickSort.h"

#include <random>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

template<typename T>
bool sorted(T* arr, int size) {
    bool is_sorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            is_sorted = false;
        }
    }
    return is_sorted;
}

TEST_CASE("MS string sort test") {
    ThreadedMergeSort ThreadedMergeSort;
    OrdinaryMergeSort OrdinaryMergeSort;

    std::string arr1[10] = { "Apple", "Boris",
                              "Cider", "Hello",
                              "Russian", "Yes",
                              "No", "Jaques",
                              "Rome", "Italy"};
    std::string arr2[10] = { "Apple", "Boris",
                              "Cider", "Hello",
                              "Russian", "Yes",
                              "No", "Jaques",
                              "Rome", "Italy" };
    std::string temp[10];

    LOG_DURATION("Ordinary merge sort strings: ") { OrdinaryMergeSort.merge_sort(arr1, 0, 9); }
    LOG_DURATION("Threaded merge sort strings: ") { ThreadedMergeSort.myMergesortRecursive(arr2, temp, 0, 9, 2); }
    CHECK(sorted(arr1, 10));
    CHECK(sorted(arr2, 10));
}

TEST_CASE("QS string sort test") {
    OrdinaryQuickSort OrdinaryQuickSort;
    ThreadedQuickSort ThreadedQuickSort;

    std::string arr1[10] = { "Apple", "Boris",
                              "Cider", "Hello",
                              "Russian", "Yes",
                              "No", "Jaques",
                              "Rome", "Italy" };
    std::string arr2[10] = { "Apple", "Boris",
                              "Cider", "Hello",
                              "Russian", "Yes",
                              "No", "Jaques",
                              "Rome", "Italy" };

    LOG_DURATION("Ordinary quick sort strings: ") { OrdinaryQuickSort.quickSort(arr1, 0, 9); }
    LOG_DURATION("Threaded quick sort strings: ") { ThreadedQuickSort.myQuicksort(arr2, 10, 2); }
    CHECK(sorted(arr1, 10));
    CHECK(sorted(arr2, 10));
}

TEST_CASE("MS 10 elements") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 10000);

    ThreadedMergeSort ThreadedMergeSort;
    OrdinaryMergeSort OrdinaryMergeSort;

    int arr1[10], arr2[10], temp[10];
    for (int i = 0; i < 10; i++) {
        arr1[i] = distrib(gen);
        arr2[i] = distrib(gen);
    }
    LOG_DURATION("Ordinary merge sort test 10 elements: ") { OrdinaryMergeSort.merge_sort(arr1, 0, 9); }
    LOG_DURATION("Threaded merge sort test 10 elements: ") { ThreadedMergeSort.myMergesortRecursive(arr2, temp, 0, 9, 2); }
    CHECK(sorted(arr1, 10));
    CHECK(sorted(arr2, 10));
}

TEST_CASE("MS 100 elements") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 10000);

    ThreadedMergeSort ThreadedMergeSort;
    OrdinaryMergeSort OrdinaryMergeSort;

    int arr1[100], arr2[100], temp[100];
    for (int i = 0; i < 100; i++) {
        arr1[i] = distrib(gen);
        arr2[i] = distrib(gen);
    }
    LOG_DURATION("Ordinary merge sort test 100 elements: ") { OrdinaryMergeSort.merge_sort(arr1, 0, 99); }
    LOG_DURATION("Threaded merge sort test 100 elements: ") { ThreadedMergeSort.myMergesortRecursive(arr2, temp, 0, 99, 2); }
    CHECK(sorted(arr1, 100));
    CHECK(sorted(arr2, 100));
}

TEST_CASE("MS 1000 elements") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 10000);

    ThreadedMergeSort ThreadedMergeSort;
    OrdinaryMergeSort OrdinaryMergeSort;

    int arr1[1000], arr2[1000], temp[1000];
    for (int i = 0; i < 1000; i++) {
        arr1[i] = distrib(gen);
        arr2[i] = distrib(gen);
    }
    LOG_DURATION("Ordinary merge sort test 1000 elements: ") { OrdinaryMergeSort.merge_sort(arr1, 0, 999); }
    LOG_DURATION("Threaded merge sort test 1000 elements: ") { ThreadedMergeSort.myMergesortRecursive(arr2, temp, 0, 999, 2); }
    CHECK(sorted(arr1, 1000));
    CHECK(sorted(arr2, 1000));
}

TEST_CASE("MS 10000 elements") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 10000);

    ThreadedMergeSort ThreadedMergeSort;
    OrdinaryMergeSort OrdinaryMergeSort;

    int arr1[10000], arr2[10000], temp[10000];
    for (int i = 0; i < 10000; i++) {
        arr1[i] = distrib(gen);
        arr2[i] = distrib(gen);
    }
    LOG_DURATION("Ordinary merge sort test 10000 elements: ") { OrdinaryMergeSort.merge_sort(arr1, 0, 9999); }
    LOG_DURATION("Threaded merge sort test 10000 elements: ") { ThreadedMergeSort.myMergesortRecursive(arr2, temp, 0, 9999, 2); }
    CHECK(sorted(arr1, 10000));
    CHECK(sorted(arr2, 10000));
}

TEST_CASE("QS 10 elements") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 10000);

    OrdinaryQuickSort OrdinaryQuickSort;
    ThreadedQuickSort ThreadedQuickSort;

    int arr1[10], arr2[10];
    for (int i = 0; i < 10; i++) {
        arr1[i] = distrib(gen);
        arr2[i] = distrib(gen);
    }
    LOG_DURATION("Ordinary quick sort test 10 elements: ") { OrdinaryQuickSort.quickSort(arr1, 0, 9); }
    LOG_DURATION("Threaded quick sort test 10 elements: ") { ThreadedQuickSort.myQuicksort(arr2, 10, 2); }
    CHECK(sorted(arr1, 10));
    CHECK(sorted(arr2, 10));
}

TEST_CASE("QS 100 elements") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 10000);

    OrdinaryQuickSort OrdinaryQuickSort;
    ThreadedQuickSort ThreadedQuickSort;

    int arr1[100], arr2[100];
    for (int i = 0; i < 100; i++) {
        arr1[i] = distrib(gen);
        arr2[i] = distrib(gen);
    }
    LOG_DURATION("Ordinary quick sort test 100 elements: ") { OrdinaryQuickSort.quickSort(arr1, 0, 99); }
    LOG_DURATION("Threaded quick sort test 100 elements: ") { ThreadedQuickSort.myQuicksort(arr2, 100, 2); }
    CHECK(sorted(arr1, 100));
    CHECK(sorted(arr2, 100));
}

TEST_CASE("QS 1000 elements") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 10000);

    OrdinaryQuickSort OrdinaryQuickSort;
    ThreadedQuickSort ThreadedQuickSort;

    int arr1[1000], arr2[1000];
    for (int i = 0; i < 1000; i++) {
        arr1[i] = distrib(gen);
        arr2[i] = distrib(gen);
    }
    LOG_DURATION("Ordinary quick sort test 1000 elements: ") { OrdinaryQuickSort.quickSort(arr1, 0, 999); }
    LOG_DURATION("Threaded quick sort test 1000 elements: ") { ThreadedQuickSort.myQuicksort(arr2, 1000, 2); }
    CHECK(sorted(arr1, 1000));
    CHECK(sorted(arr2, 1000));
}

TEST_CASE("QS 10000 elements") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 10000);

    OrdinaryQuickSort OrdinaryQuickSort;
    ThreadedQuickSort ThreadedQuickSort;

    int arr1[10000], arr2[10000];
    for (int i = 0; i < 10000; i++) {
        arr1[i] = distrib(gen);
        arr2[i] = distrib(gen);
    }
    LOG_DURATION("Ordinary quick sort test 10000 elements: ") { OrdinaryQuickSort.quickSort(arr1, 0, 9999); }
    LOG_DURATION("Threaded quick sort test 10000 elements: ") { ThreadedQuickSort.myQuicksort(arr2, 10000, 2); }
    CHECK(sorted(arr1, 10000));
    CHECK(sorted(arr2, 10000));
}

TEST_CASE("QS 100000 elements") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 10000);

    OrdinaryQuickSort OrdinaryQuickSort;
    ThreadedQuickSort ThreadedQuickSort;

    int arr1[100000], arr2[100000];
    for (int i = 0; i < 100000; i++) {
        arr1[i] = distrib(gen);
        arr2[i] = distrib(gen);
    }
    LOG_DURATION("Ordinary quick sort test 100000 elements: ") { OrdinaryQuickSort.quickSort(arr1, 0, 99999); }
    LOG_DURATION("Threaded quick sort test 100000 elements: ") { ThreadedQuickSort.myQuicksort(arr2, 100000, 2); }
    CHECK(sorted(arr1, 100000));
    CHECK(sorted(arr2, 100000));
}