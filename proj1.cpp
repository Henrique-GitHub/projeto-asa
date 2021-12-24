#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void readVector(std::vector<int> *x) {
    int intToRead;

    do {
        std::cin >> intToRead;
        (*x).push_back(intToRead);
    } while (getchar() != '\n');
}

void solveProbOne() {
    std::vector<int> x;
    readVector(&x);

    int maxSize = 1;
    int numberOfSeq = x.size();
    std::vector<int> arr(x.size(), 1);

    for (long unsigned int i = 1; i < x.size(); i++) {
        for (long unsigned int j = 0; j < i; j++) {
            if (x[i] > x[j]) {
                int sum = arr[j] + 1;
                if (sum > arr[i]) {
                    arr[i] = sum;
                }
                if (sum == arr[i]) {
                    if (sum > maxSize) {
                        numberOfSeq = 1;
                        maxSize = arr[i];
                    } else if (sum == maxSize) {
                        numberOfSeq++;
                    }
                }
            }
        }
    }

    std::cout << maxSize << ' ' << numberOfSeq << '\n';
}

void solveProbTwo() {
    std::vector<int> x;
    std::vector<int> y;
    readVector(&x);
    readVector(&y);

    std::vector<int> arr(y.size(), 0);

    int maxSize = 0;

    for (long unsigned int i = 0; i < x.size(); i++) {
        int previousBiggerSize = 0;
        for (long unsigned int j = 0; j < y.size(); j++) {
            if (x[i] > y[j] && arr[j] > previousBiggerSize) {
                previousBiggerSize = arr[j];
            }

            else if (x[i] == y[j] && previousBiggerSize + 1 > arr[j]) {
                arr[j] = previousBiggerSize + 1;
                if (previousBiggerSize + 1 > maxSize)
                    maxSize = previousBiggerSize + 1;
            }
        }
    }

    std::cout << maxSize << '\n';
}

int main() {
    int problemNum;
    std::cin >> problemNum;

    if (problemNum == 1)
        solveProbOne();
    else if (problemNum == 2)
        solveProbTwo();

    return 0;
}