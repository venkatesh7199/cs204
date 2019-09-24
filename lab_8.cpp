#include<bits/stdc++.h>

using namespace std;

long long party(long long arr[], long long l, long long r, long long x)
{
    long long i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
      swap(arr[i], arr[r]);

    i = l;
    for (long long j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

long long FINDMOM(long long arr[], long long n)
{
    sort(arr, arr+n);
    return arr[n/2];
}

long long BLUM(long long arr[], long long l, long long r, long long k)
{
    if (k > 0 && k <= r - l + 1)
    {
        long long n = r-l+1;
        long long i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = FINDMOM(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = FINDMOM(arr+l+i*5, n%5);
            i++;
        }

        long long MOM = (i == 1)? median[i-1]:
                                 BLUM(median, 0, i-1, i/2);

        long long pos = party(arr, l, r, MOM);

        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return BLUM(arr, l, pos-1, k);

        return BLUM(arr, pos+1, r, k-pos+l-1);
    }

}

int main()
{
    long long n;
    cin>>n;
    while(n--){
      long long k;
      cin>>k;
      long long arr[k];
      for(long long i=0; i<k; i++){
            long long x,y;
            cin>>x>>y;
            arr[i]=x*x+y*y;
      }
      cout<<sqrt(BLUM(arr,0,k-1,(long long)ceil((long double)k/2)))<<endl;
    }
    return 0;
}
