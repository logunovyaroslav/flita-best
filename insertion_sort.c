

void InsertionSort(int n, int *mass) {
    int newElement, location;

    for (int i = 1; i < n; i++) {
        newElement = mass[i];
        location = i - 1;
        while (location >= 0 && mass[location] > newElement) {
            mass[location + 1] = mass[location];
            location = location - 1;
        }
        mass[location + 1] = newElement;
    }
}