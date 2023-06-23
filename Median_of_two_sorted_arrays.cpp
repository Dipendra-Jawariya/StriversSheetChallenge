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

//biNARY SEARCH

double median(vector<int> &a, vector<int> &b) {

  if (a.size() > b.size())
    median(b, a);

  int n1 = a.size();

  int n2 = b.size();

  int l = 0, r = n1;

  while (l <= r) {

    int m1 = l + (r - l) / 2;

    int m2 = (n1 + n2 + 1) / 2 - m1;

    int l1 = m1 == 0 ? INT_MIN : a[m1 - 1];

    int l2 = m2 == 0 ? INT_MIN : b[m2 - 1];

    int r1 = m1 == n1 ? INT_MAX : a[m1];

    int r2 = m2 == n2 ? INT_MAX : b[m2];

    if (l1 <= r2 and l2 <= r1) {

      if ((n1 + n2) % 2 == 0) {

        return ((max(l1, l2)) + (min(r1, r2))) / 2.0;

      } else {

        return max(l1, l2);
      }

    } else if (l1 > r2) {

      r = m1 - 1;

    } else {

      l = m1 + 1;
    }
  }
}