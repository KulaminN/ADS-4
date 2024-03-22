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
    int iLeft = 0;
    int iRight = size - 1;
    int iCounter = 0;
    while (iLeft < iRight) {
        int iMid = (iLeft + iRight) / 2;
        if (iRight - iLeft == 1) {
            return 0;
        }
        if (value > arr[iMid]) {
            iLeft = iMid;
        } else if (value < arr[iMid]) {
            iRight = iMid;
        } else {
            while (arr[iMid] == value) {
                iMid--;
            }
            iMid++;
            while (arr[iMid] == value) {
                iMid++;
                iCounter++;
            }
            break;
        }
    }
    return iCounter;
}

int countPairs3(int *arr, int len, int value) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += cbinsearch(&arr[i + 1], len - i - 1, value - arr[i]);
    }
    return sum;
}
