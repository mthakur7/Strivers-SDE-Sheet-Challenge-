string kthPermutation(int n, int k) {
    // Write your code here.
      vector<int>arr;
        int fac=1;
        for(int i=1;i<=n;i++){
            fac=fac*i;
            arr.push_back(i);
        }
        fac=fac/n;
        k=k-1;
      string ans;
      while (true) {
        ans += to_string(arr[k / fac]);
        arr.erase(arr.begin() + k / fac);
        if (arr.size() == 0)
          break;
        k = k % fac;
        fac = fac / arr.size();
      }
      return ans;
}
