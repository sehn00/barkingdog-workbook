#include <bits/stdc++.h>
using namespace std;

int main(void) {
    list<int> L = {1, 2};       // 이중 연결 리스트 생성: [1, 2]

    list<int>::iterator t = L.begin();
    // 이터레이터 t는 첫 원소(1)를 가리킴
    // iterator가 주소 역할을 한다!
    // (C++11 이상) auto t = L.begin()  ...으로 써도 됨

    L.push_front(10);       // 맨 앞에 10 추가 → [10, 1, 2]
    // 주의: list는 삽입/삭제 시 기존 iterator가 무효화되지 않음

    cout << *t << '\n';     // t는 여전히 1을 가리킴 → 1 출력

    L.push_back(5);         // 맨 뒤에 5 추가 → [10, 1, 2, 5]

    L.insert(t, 6);         // t가 가리키는 원소(1) "앞"에 6 삽입
                            // → [10, 6, 1, 2, 5]

    t++;    // t를 다음 원소로 이동 (1 → 2)

    t = L.erase(t);         // t가 가리키는 원소(2) 삭제
    // erase는 "삭제된 원소의 다음 iterator"를 반환
    // → [10, 6, 1, 5], t는 5를 가리킴

    cout << *t << '\n';     // 5 출력

    // range-based for (C++11 이상): 내부적으로 iterator 사용
    for (auto i : L) cout << i << ' ';

    // 전통적인 iterator 순회
    for (list<int>::iterator it = L.begin(); it != L.end(); it++)
        cout << *it << ' ';
}
