#include "main.h"

int main() {
    SortingBenchmark();
    return 0;
}

void ShowArray(SortData_t *sortData) {
    for (int i = 0; i < sortData->length; ++i) {
        printf("%d\n", sortData->arr[i]);
    }
}

void SortingBenchmark() {
    FILE *fp;
    SortData_t *sortData = (SortData_t *) calloc(1, sizeof(SortData_t));
    int startTime; // Время работы программы замеряем как разницу между временем начала программы и временем её окончания
    int endTime;

    if ((fp = fopen("../insertion_sort_times.txt", "w")) == NULL) {
        puts("Can't open file times.txt for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = START_DATA_SIZE; i <= END_DATA_SIZE; i = i + RANDOM_DATA_SIZE_STEP) {
        sortData->arr = (int *) calloc(1, sizeof(int));
        GiveRandFile(i);
        GetFileData(sortData);
        startTime = clock();
        InsertionSort(sortData->length, sortData->arr);
        endTime = clock();
        ShowArray(sortData);
        free(sortData->arr);
        fprintf(fp, "%d -> %d\n", i, endTime - startTime);
    }

    fclose(fp);

    if ((fp = fopen("../shell_sort_times.txt", "w")) == NULL) {
        puts("Can't open file times.txt for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = START_DATA_SIZE; i <= END_DATA_SIZE; i = i + RANDOM_DATA_SIZE_STEP) {
        sortData->arr = (int *) calloc(1, sizeof(int));
        GiveRandFile(i);
        GetFileData(sortData);
        startTime = clock();
        ShellSort(sortData->length, sortData->arr);
        endTime = clock();
        ShowArray(sortData);
        free(sortData->arr);
        fprintf(fp, "%d -> %d\n", i, endTime - startTime);
    }

    fclose(fp);
    free(sortData);

}