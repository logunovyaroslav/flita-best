#ifndef FLITAGROUP_FILE_OPERATIONS_H
#define FLITAGROUP_FILE_OPERATIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Array {
    int length;
    int *arr;
} SortData_t;

#define START_DATA_SIZE 10
#define END_DATA_SIZE 300
#define RANDOM_DATA_SIZE_STEP 10
#define DENOMINATOR 100001

void GetFileData(SortData_t *sortData); // Ввод данных с файла
void GiveRandFile(int numberOfNumbers); // Запись рандомных значений в файл для считывания

#endif //FLITAGROUP_FILE_OPERATIONS_H
