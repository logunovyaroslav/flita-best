#include "file_operations.h"

void GiveRandFile(int numberOfNumbers) {
    FILE *fp;
    if ((fp = fopen("../data.txt", "w")) == NULL) {
        puts("Can't open file data.txt");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL)); // Функция чтоб rand() каждый раз генерировал новые числа
    for (int i = 0; i < numberOfNumbers - 1; i++) { // Генерируем и записываем числа в файл
        fprintf(fp, "%d ", rand() % DENOMINATOR);
    }
    fprintf(fp, "%d\n", rand() % DENOMINATOR);
    fclose(fp);
}

void GetFileData(SortData_t *sortData) {
    FILE * fp;
    if ((fp = fopen("../data.txt", "r")) == NULL) { // Открываем файл и смотрим нормально ли открылось
        puts("Can't open data.txt for reading");
        exit(EXIT_FAILURE);
    }
    int character, i = 0;
    char nextSymbol;
    while (fscanf(fp, "%d%c", &character, &nextSymbol)) { // Считываем символы для каждого нового символа снова выделяем память
        sortData->arr = (int * ) realloc(sortData->arr, (i + 1) * sizeof(int));
        sortData->arr[i] = character;
        i++;
        if (nextSymbol == '\n')
            break;
    }
    sortData->length = i;
    if (nextSymbol != '\n') { // Проверка на валидность данных
        puts("The data is not avialable");
        exit(EXIT_FAILURE);
    }
    fclose(fp);
}
