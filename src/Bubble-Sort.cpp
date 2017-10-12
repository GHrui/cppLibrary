#include<iostream>

using namespace std;

void bubbleSort(int array[], int length);
void swap(int *a, int *b);
void outPut(int array[], int length);

int main(void){
    int array[10] = {10,9,8,7,6,5,4,3,2};
    int length = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, length);
    outPut(array, length);
    getchar();
    return 0;
}

void bubbleSort(int array[], int length){
    for (int i = 0; i < length; ++i){
        for (int j = 0; j < length - i - 1; ++j){
            // Descending
            if (array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
            // Ascending
            //if (array[j] < array[j + 1]){
            //    swap(&array[j], array[j + 1]);
            //}
        }
    }
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void outPut(int array[], int length){
    for (int i = 0; i < length; ++i){
        cout << array[i] << " ";
    }
    cout << endl;
}