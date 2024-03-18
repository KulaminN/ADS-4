// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
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
    int iTemp = 0;
    while (i < j) {
        if (arr[i] + arr[j] == value) {
            count++;
            iTemp++;
            j--;
        } else {
            if (iTemp != 0) {
                i++;
                j += iTemp;
                iTemp = 0;
            }
            if (arr[i] + arr[j] > value) {
                j--;
            } else if (arr[i] + arr[j] < value) {
                i++;
            }
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        int count = 0;
        int iTemp = value - arr[i];
        int l = i + 1;
        int r = len - 1;
        if (l < iTemp) {
            while (l < r) {
                int mid = (l + r) / 2;
                if (r - l == 1) {
                    if (arr[r] == iTemp) {
                        sum++;
                    }
                    if (arr[l] == iTemp) {
                        sum++;
                    }
                    break;
                }
                if (arr[mid] < iTemp) {
                    l = mid;
                } else if (arr[mid] > iTemp) {
                    r = mid;
                } else if (arr[mid] == iTemp) {
                    while (arr[mid] == iTemp) {
                        mid--;
                    }
                    mid++;
                    while (arr[mid] == iTemp) {
                        mid++;
                        count++;
                    }
                    break;
                }
            }
        }
        sum += count;
    }
    return sum;
}
