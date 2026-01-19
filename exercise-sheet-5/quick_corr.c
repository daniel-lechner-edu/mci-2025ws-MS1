/**
5.2 Makros und Konstanten (50%)
Im Ordner dieses Übungsblattes finden Sie die Quellcode-Datei "quick.c", welche eine Implementierung des QuickSort Sortieralgorithmus beinhaltet. In dieser Datei wurden einige Konstanten und Makros definiert, nur leider haben sich in den Code diverse Fehler eingeschlichen, welche eine erfolgreiche Kompilierung verhindern. Ihre Aufgabe ist es nun den Quellcode so zu ändern, dass eine erfolgreiche Kompilierung und Ausführung möglich ist. Es ist dabei nicht gestattet Konstanten und Makros zu entfernen, die bestehenden können aber abgeändert werden. Als Ausgabe des Programms wird das aufsteigend sortierte Array erwartet, wobei die einzelnen Elemente durch Tabulatoren getrennt werden sollen.
 */

/* C implementation QuickSort */
#include<stdio.h>

#define NUMBERS 4, \
                6, \
                2, \
                11, \
                3, \
                7

#define SWAP(x,y) { int t = *x; *x = *y; *y = t; }

#define PRINTINT(x) printf("%d", x)

#define TAB printf("\t")

#define NEWLINE printf("\n")

#define FOR(a,b,c,d,e) for(int a = b; a <= c; d) e

#define QUICK(x,y,z) quickSort(x,y,z)

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    FOR (j, low, high-1, j++, {
        if (arr[j] <= pivot)
        {
            i++;
            SWAP(&arr[i], &arr[j]);
        }
    })
    SWAP(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        QUICK(arr, low, pi - 1);
        QUICK(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    FOR(i,0,size-1,i++,{
        PRINTINT(arr[i]);
        TAB;
    })
}

int main()
{
    int arr[] = {NUMBERS};
    int n = sizeof(arr)/sizeof(arr[0]);
    QUICK(arr, 0, n-1);
    NEWLINE;
    printArray(arr, n);
    NEWLINE;
    return 0;
}
