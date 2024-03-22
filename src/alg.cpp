// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int j = len - 1;
    int i = 0;
    int count = 0;
    while (arr[j] > value) {
        j--;
    }
    for (int m = i; m < j; m++) {
        for (int n = j; n > m; n--) {
            if (arr[m] + arr[n] == value) {
                count++;
            }
        }
    }
    return count;
}

int cbinsearch(int *arr, int size, int value) {
    int iTemp = size / 2;
    int counter = 0;
    bool bFlag = true;
    if (arr[iTemp] == value) {
        while (arr[iTemp] == value && iTemp >= 0) {
            iTemp--;
        }
        iTemp++;
        while (arr[iTemp] == value && iTemp < size) {
            iTemp++;
            counter++;
        }
        return counter;
    }
    while (iTemp >= 0 && iTemp < size && bFlag) {
        if (arr[iTemp] == value) {
            while (iTemp >= 0 && iTemp < size && arr[iTemp] == value) {
                counter++;
                if (arr[iTemp] < arr[size / 2]) {
                    iTemp--;
                } else {
                    iTemp++;
                }
            }
            bFlag = false;
        } else if (arr[iTemp] > value && arr[iTemp - 1] < value) {
            return 0;
        } else if (arr[iTemp + 1] > value && arr[iTemp] < value) {
            return 0;
        } else if (arr[iTemp] > value) {
            iTemp--;
        } else {
            iTemp++;
        }
    }
    return counter;
}

int countPairs3(int *arr, int len, int value) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += cbinsearch(&arr[i + 1], len - i - 1, value - arr[i]);
    }
    return sum;
}
