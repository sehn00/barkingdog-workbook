#include <bits/stdc++.h>
using namespace std;

int
main()
{
    string init;
    cin >> init;

    list<char> L;
    for (char c : init)
        L.push_back(c);
    auto cursor = L.end();
    // cursor = 이터레이터! (원형은 list<char>::iterator)
    // 만약, [ a b c | d ] 일때
    // 커서(|)가 c를 가리키는지 d를 가리키는지는 사용자가 설정!

    // 다만, L.insert(cursor, x) 의 insert, erase 메소드가
    // cursor 앞에 삽입하고, 앞을 지우므로
    // 편의상 [ a b c | d ] 에서는, cursor가 d (뒤 원소)를 가리킨다고 보는게 편할듯
    // (그래야 삽입하면 [ a b c x | d ], 즉 d 앞에 삽입됨)

    int M;
    cin >> M;

    while (M--) {
        char op;
        cin >> op;

        if (op == 'L') {
            // 커서가 맨 앞이 아니면, 왼쪽 한 칸 이동
            if (cursor != L.begin()) cursor--;
        }
        else if (op == 'D') {
            // 커서가 맨 뒤가 아니면, 오른쪽 한 칸 이동
            if (cursor != L.end()) cursor++;
        }
        else if (op == 'B') {
            // 커서 왼쪽 문자를 삭제 (커서 위치부터 한 칸 왼쪽으로)
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
                // erase는 지운 후, 삭제한 원소의 다음 위치를 반환
            }
        }
        else if (op == 'P') {
            char x;
            cin >> x;
            L.insert(cursor, x);
        }
    }

    for (char c : L)
        cout << c;
    
    return 0;
}