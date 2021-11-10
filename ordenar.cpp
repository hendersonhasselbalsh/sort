/////////// merge sort

#include <iostream>
#include "ordenar.h"

using namespace std;



int main(int argc, const char* argv[])
{

    int v[] = {45, 56, 12, 43, 95, 19, 8, 67};


    iterativo::quick_sort(v, 0, 7);    // 8


    cout << "sequencia ordenada quick_sort:  t ";
    for(int i : v) {cout << i << "  ";} cout << endl;

}