// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int res = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++res;
      }
    }
  }
  return res;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int l = 0;
  int r = len - 1;
  while (l < r) {
    int sum = arr[l] + arr[r];
    if (sum == value) {
      if (arr[l] == arr[r]) {
        int n = r - l + 1;
        count += n * (n - 1) / 2;
        break;
      } else {
        int lValue = arr[l];
        int rValue = arr[r];
        int lCount = 0;
        while (l <= r && arr[l] == lValue) {
          ++lCount;
          ++l;
        }
        int rCount = 0;
        while (l <= r && arr[r] == rValue) {
          ++rCount;
          --r;
        }
        count += lCount * rCount;
      }
    } else if (sum < value) {
      ++l;
    } else {
      --r;
    }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int l = i + 1;
    int r = len;
    int first = -1;
    while (l < r) {
      int c = l + (r - l) / 2;
      if (arr[c] == target) {
        first = c;
        r = c;
      } else if (arr[c] < target) {
        l = c + 1;
      } else {
        r = c;
      }
    }
    if (first != -1) {
      l = first;
      r = len;
      int last = first;
      while (l < r) {
        int c = l + (r - l) / 2;
        if (arr[c] == target) {
          last = c;
          l = c + 1;
        } else if (arr[c] < target) {
          l = c + 1;
        } else {
          r = c;
        }
      }
      count += (last - first + 1);
    }
  }
  return count;
}
