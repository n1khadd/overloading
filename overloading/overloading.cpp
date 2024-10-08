#include <iostream>
#include <cstdlib>
#include <ctime>

void fillArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = std::rand() % 100;  // 0-99 arasında random ədəd
    }
}

void fillArray(double array[], int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<double>(std::rand()) / RAND_MAX * 100.0;  // 0.0-100.0 arasında random ədəd
    }
}

void fillArray(float array[], int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<float>(std::rand()) / RAND_MAX * 100.0f;  // 0.0-100.0 arasında random ədəd
    }
}

void fillArray(char array[], int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = 'A' + std::rand() % 26;  // A-Z arasında random char
    }
}

template<typename T>
void fillArrayInRange(T array[], int size, T minValue, T maxValue) {
    for (int i = 0; i < size; ++i) {
        array[i] = minValue + static_cast<T>(std::rand()) / (RAND_MAX / (maxValue - minValue));
    }
}

template<typename T>
void printArray(const T array[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void bubbleSort(T array[], int size, bool ascending) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if ((ascending && array[j] > array[j + 1]) || (!ascending && array[j] < array[j + 1])) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

template<typename T>
int findElement(const T array[], int size, T target) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;  // tapılmadı
}

int main() {
    std::srand(std::time(nullptr));

    const int size = 10;

    int intArray[size];
    fillArray(intArray, size);
    std::cout << "Int massiv: ";
    printArray(intArray, size);

    double doubleArray[size];
    fillArray(doubleArray, size);
    std::cout << "Double massiv: ";
    printArray(doubleArray, size);

    float floatArray[size];
    fillArray(floatArray, size);
    std::cout << "Float massiv: ";
    printArray(floatArray, size);

    char charArray[size];
    fillArray(charArray, size);
    std::cout << "Char massiv: ";
    printArray(charArray, size);

    std::cout << "Int massiv 50-60 arasında doldurulub: ";
    fillArrayInRange(intArray, size, 50, 60);
    printArray(intArray, size);

    std::cout << "Double massiv 10.5-20.5 arasında doldurulub: ";
    fillArrayInRange(doubleArray, size, 10.5, 20.5);
    printArray(doubleArray, size);

    bubbleSort(intArray, size, true);
    std::cout << "Int massiv (Artan): ";
    printArray(intArray, size);

    bubbleSort(doubleArray, size, false);
    std::cout << "Double massiv (Azalan): ";
    printArray(doubleArray, size);

    int index = findElement(intArray, size, intArray[5]);
    if (index != -1) {
        std::cout << "Element " << intArray[5] << " massivdə " << index << " indeksində tapıldı." << std::endl;
    }
    else {
        std::cout << "Element tapılmadı." << std::endl;
    }
}
