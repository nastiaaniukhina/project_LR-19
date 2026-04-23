// project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
#include <locale>

using namespace std;

void printArray(const vector<char>& arr) {
    for (char c : arr)
        cout << c << " ";
    cout << endl;
}

void merge(vector<char>& arr, int left, int mid, int right) {
    vector<char> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<char> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;

    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < L.size())
        arr[k++] = L[i++];

    while (j < R.size())
        arr[k++] = R[j++];
}

void mergeSort(vector<char>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    setlocale(LC_ALL, "ukr");

    const int size = 10;
    vector<char> arr(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 25);

    for (int i = 0; i < size; i++)
        arr[i] = 'A' + dist(gen);

    cout << "Початковий масив: ";
    printArray(arr);

    mergeSort(arr, 0, size - 1);

    cout << "Відсортований масив: ";
    printArray(arr);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
