#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <string>
#include "Timer.h"

using namespace std;

template <int*& a, int*& b>
void swap() {
    int* tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void SortPointers(vector<T*> list) {
    std::vector<int*> original = list;
    std::sort(list.begin(), list.end(), [](const int* a, const int* b) {
        return *a < *b;
        });
    std::vector<int> xfer;
    for (auto ptr : list) {
        xfer.push_back(*ptr);
    }
    auto it = std::begin(xfer);
    for (auto ptr : original) {
        *ptr = *it++;
    }
    
}


int main() {
    int a = 1;
    int b = 2;
    int* ptr1 = &a;
    int* ptr2 = &b;
    cout << *ptr1 << *ptr2 << endl;
    swap(ptr1, ptr2);
    cout << *ptr1 << *ptr2 << endl;

    vector<int> numbers;
    vector<int*> pointers;
    int* ptr;
    int c = 0;
    for (int i = 0; i < 100; i++) {
        c = rand();
        numbers.push_back(c);
    }
   
    for (int i = 0; i < 100; i++) {
        ptr = &numbers[i];
        pointers.push_back(ptr);
    }
    for (int i = 0; i < 100; i++) {
        cout << *pointers[i] << " ";
    }
    cout << "\n";
    cout << "\n";
    SortPointers(pointers);
    for (int i = 0; i < 100; i++) {
        cout << *pointers[i] << " ";
    }

    ifstream file("d:\\War and peace.txt");
    char letter;
    string word;
    vector<char> warpeace;
    while (!file.eof()){
        letter = file.get();
        warpeace.push_back(letter);
    }
    file.close();

    string const vs("aeiouAEIOU");

    Timer timer("Count_if & find");
    int count = count_if(warpeace.begin(), warpeace.end(),
        [&](char c) { return vs.end() != find(vs.begin(), vs.end(), c); });
    timer.print();

    Timer timer("Count_if & for");
    int count1 = count_if(warpeace.begin(), warpeace.end(),
        [&](char c) { 
            for (int i = 0; i < vs.size(); i++) {
                 return vs[i] == c;
            }
        });
    timer.print();

    int count2 = 0;
    Timer timer("for & find");
    for (int i = 0; i < warpeace.size(); i++) {
        if (vs.end() != find(vs.begin(), vs.end(), warpeace[i])) ++count2;
    }
    timer.print();

    int count3 = 0;
    Timer timer("for & for");
    for (int i = 0; i < warpeace.size(); i++) {
        for (int j = 0; j < vs.size(); j++) {
            if (warpeace[i] == vs[j]) ++count3;
        }
    }
    timer.print();
}