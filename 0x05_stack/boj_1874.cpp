#include <bits/stdc++.h>
using namespace std;

int
main()
{
    int N;
    cin >> N;
    
    stack<int> S;       // push(), pop() 진행할 스택
    vector<char> Ans;   // +,- 연산 기록 저장용

    int cur = 1;
    // 다음에 push할 숫자 (처음에는 1부터 가능)
    
    while (N--) {
        int target;     // pop()으로 만들어야하는 숫자
        cin >> target;
        
        // (if) 스택의 top이 target보다 작은 경우
        // push()할 숫자(=cur)를 target까지 끌어올리기 => '+'
        // (이미 cur가 target보다 더 큰 경우엔 pass)
        while (cur <= target) {
            S.push(cur);
            Ans.push_back('+');
            cur++;
        }

        // 여기까지 왔으면 경우는 둘 중 하나:
        //   1. S.top() == target  -> 원하는 숫자 pop() 가능
        //   2. S.top() != target  -> 중간에 다른 숫자가 막고 있어서 불가능
            // (예) 스택에 {3,4} 가 남았는데, target=3 인 경우

        if (!S.empty() && S.top() == target) {
            S.pop();
            Ans.push_back('-');
        }
        else {
            cout << "NO" << '\n';
            return 0;   // NO 면 바로 리턴
        }
    }

    for (char c : Ans)
        cout << c << '\n';

    return 0;
}