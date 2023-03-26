// Copyright 2021 NNTU-CS
int binarySearch(int* arr, int low, int right, int value) {
  int c = 0;
  while (right - low > 1) {
    int mid = (low + right) / 2;

    if (arr[mid] < value) {
      low = mid;
    }
    if (arr[mid] > value) {
      right = mid;
    }
    if (arr[mid] == value) {
      c += 1;
      int a = mid + 1;
      while (arr[a] == value && a < right) {
        c += 1;
        a += 1;
      }
      a = mid - 1;
      while (arr[a] == value && a > low) {
        c += 1;
        --a;
      }
      break;
    }
  }
  return c;
}

int countPairs2(int *arr, int len, int value) {
  int sum = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[j] + arr[i] == value) {
        sum+=1;
      }
    }
  }
  return sum;
}
int countPairs1(int *arr, int len, int value) {
  int sum = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] + arr[j] == value) {
        sum += 1;
      }
    }
  }
  return sum;
}
int countPairs3(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; ++i) {
    k += binarySearch(arr, i, len, value - arr[i]);
  }
  return k;
}
