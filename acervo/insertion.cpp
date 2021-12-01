/////////////

#include <iostream>
using namespace std;


void troca(int& a, int& b)
{
    int aux = a;  a = b;  b = aux;
}

void insertion_sort(int* v, int size)
{
    for(int i = 1; i < size; i++)
    {
        int j = i;

        while(j-1 >= 0  &&  v[i] < v[j-1])
        {
            troca(v[i], v[j-1]); 
            j--;
        }
    }
}



int main(int argc, const char* argv[])
{
    int v[] = {45, 56, 12, 43, 95, 19, 8, 67};

    insertion_sort(v, 8);
    
    for(int i : v) {cout << i << "  ";} cout << endl;
}