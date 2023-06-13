double median(vector<int> &a, vector<int> &b) {
  int n = a.size(), m = b.size();
  int mid;
  bool even = false;
  if ((n + m) % 2 == 0) {
    even = true;
    mid = (n + m) / 2;
  } else {
    mid = ((n + m) / 2) + 1;
  }
  int i = 0, j = 0;
  int last = 0;
  double result = 0;
  while (i < n && j < m) {
    if (a[i] > b[j]) {
      last = b[j];
      j++;
    } else {
      last = a[i];
      i++;
    }
    mid--;
    if (mid == 0) {
      if (even) {
        if (i < n && j < n) {
          int num = min(a[i], b[j]);
          result = (double)(last + num) / 2;
        } else {
          if (i < n) {
            result = (double)(last + a[i]) / 2;
          } else {
            result = (double)(last + b[j]) / 2;
          }
        }
      } else {
        result = last;
      }
    }
  }
  return result;
}