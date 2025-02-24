
#include <iostream>

class ShellSort final {
    static const int size = 14;
    int arr[size] = { 32, 95, 16, 82, 24, 66, 35, 19, 75, 54, 40, 43, 93, 68 };

public:

    void sort() {
        int step, i, j, tmp;

        for (step = size / 2; step > 0; step /= 2) {
            for (i = step; i < size; i++) {
                for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step) {
                    tmp = arr[j];
                    arr[j] = arr[j + step];
                    arr[j + step] = tmp;
                }
            }
        }
    }

    ShellSort() {
        sort();
        for (int i = 0; i < size; i++)
            cout << arr[i] << ' ';
    }
    ~ShellSort() = default;
};

int main() {
    ShellSort();
    return 0;
}