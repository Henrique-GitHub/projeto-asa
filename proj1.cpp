#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void readVector(std::vector<int> *x) {
    int intRead;
    char c;

    do {
        std::cin >> intRead;
        (*x).push_back(intRead);
    } while ((c = getchar()) != '\n' && c != EOF);
}

void solveProbOne() {
    std::vector<int> x;
    readVector(&x);

    

    int maxSize = 1;
    long int numberOfSeq = x.size();
    std::vector<std::vector<int>> arr(x.size(), std::vector<int> (2, 1));

    for (long unsigned int i = 1; i < x.size(); i++) {
        arr[i][0] = 1;
        arr[i][1] = 1;
        for (long unsigned int j = 0; j < i; j++) {
            if (x[i] > x[j]) {
                int sum = arr[j][0] + 1;
                if (sum > arr[i][0]) {
                    arr[i][0] = sum;
                    arr[i][1] = arr[j][1];
                } else if(sum == arr[i][0]) {
                    arr[i][1] += arr[j][1];
                }

                if (sum > maxSize) {
                    maxSize = arr[i][0];
                    numberOfSeq = arr[i][1];
                } else if (sum == maxSize) {
                    numberOfSeq += arr[j][1];
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