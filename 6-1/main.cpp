#include <iostream>

using namespace std;

template <typename T> void sortirovka (T* array, int razmer) {
    for (int i = 1; i < razmer; ++i)
        for (int j = razmer - 1; j >= i; --j)
            if (array[j-1] > array[j])
                swap(array[j], array[j-1]);
}

int main () {
    int array_1[] = {1, 6, 2, 9, 3};
    string array_2[] = {"lumos", "volandemort", "avadakedavra", "potter" };
    double array_3[] = {52.3, 14.6, 15.2, 4.7};
    int razmer_1 = sizeof(array_1) / sizeof(array_1[0]);
    int razmer_2 = sizeof(array_2) / sizeof(array_2[0]);
    int razmer_3 = sizeof(array_3) / sizeof(array_3[0]);
    cout << "Значения типа int: ";
    for (int i = 0; i<razmer_1; i++)
        cout << array_1[i] << ", ";
    cout << endl << "Значения типа string: ";
    for (int i = 0; i<razmer_2; i++)
        cout << array_2[i] << ", ";
    cout << endl << "Значения типа double: ";
    for (int i = 0; i<razmer_3; i++)
        cout << array_3[i] << ", ";
    cout << endl;
    sortirovka(array_1, razmer_1);
    sortirovka(array_2, razmer_2);
    sortirovka(array_3, razmer_3);
    cout << "Сортировка значений типа int: ";
    for (int i = 0; i<razmer_1; i++)
        cout << array_1[i] << ", ";
    cout << endl << "Сортировка значений типа string: ";
    for (int i = 0; i<razmer_2; i++)
        cout << array_2[i] << ", ";
    cout << endl << "Сортировка значений типа double: ";
    for (int i = 0; i<razmer_3; i++)
        cout << array_3[i] << ", ";
    cout << endl;
    return 0;
}