#include <bits/stdc++.h>
using namespace std;

int
main()
{
    int n, x, cnt=0;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cin >> x;

    sort(arr.begin(), arr.end());

    int st = 0;
    int en = n-1;
    
    while (st < en) {
        int sum = arr[st] + arr[en];

        if (sum == x) {
            cnt++;
            st++;
            en--;
        }   // arr[st] + arr[en] 이 sum이 됨을 확인했다!
        // 모든 수가 서로 다르다고 했으니,
        // st와 en은 더이상 답을 만드는 인덱스가 될 수 없음
        //   => st++와 en--를 동시에 진행한다
        else if (sum < x)
            st++;
        else
            en--;
    }
    cout << cnt << '\n';

    // 아래처럼 하면 O(n^2)... -시간초과-
    // for (int i=0; i<n; i++) {
    //     int num = arr[i];
    //     for (int j=1; j<n-i; j++) {
    //         if (num + arr[i+j] == x) cnt++;
    //     }
    // }

    return 0;
}