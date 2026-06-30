#include <bits/stdc++.h>
using namespace std;

int main(void) {
    // 생성자: vector<자료형> v1(크기, 초기값);
    vector<int> v1(3, 5);       // {5,5,5};
    cout << v1.size() << '\n';  // 3

    // push_back(): 맨 뒤에 원소 추가 - O(1)
    v1.push_back(7);            // {5,5,5,7};

    // 기본 초기화: 크기만 주면 0으로 채워짐
    vector<int> v2(2);          // {0,0};

    // insert(위치, 값): 특정 위치에 삽입 - O(N)
    // begin(): 첫 원소를 가리키는 iterator
    v2.insert(v2.begin()+1, 3); // {0,3,0};
    
    // 초기화 리스트로 생성
    vector<int> v3 = {1,2,3,4}; // {1,2,3,4}

    // erase(위치): 해당 위치 원소 삭제 - O(N)
    v3.erase(v3.begin()+2);     // {1,2,4};

    // 대입: 깊은 복사 (데이터를 복사해서 새로 생성, 서로 독립)
    vector<int> v4;         // {}
    v4 = v3;                // {1,2,4}

    cout << v4[0] << v4[1] << v4[2] << '\n'; // 124

    // pop_back(): 맨 뒤 원소 제거 - O(1)
    v4.pop_back();         // {1,2}

    // clear(): 모든 원소 제거 (용량은 남을 수 있음)
    v4.clear();            // {}
// 메소드의 시간복잡도도 잘 고려하기



vector<int> v1 = {1,2,3,4,5,6};

// 1. range-based for (C++11 이상)
//   -> v1의 모든 원소를 앞에서부터 하나씩 꺼냄
for (int e : v1)
    cout << e << ' ';
// for (int& e : v1)  => 원본 변경

// 2. 인덱스 기반 for
//   -> 전통적인 방식, size() 미만까지만 접근하면 안전
for (int i = 0; i < v1.size(); i++)
    cout << v1[i] << ' ';


// 3. ***WRONG***
for (int i = 0; i <= v1.size() - 1; i++)
    cout << v1[i] << ' ';
}
// size()는 unsigned 타입(size_t)
// v1이 비어있으면(size=0), size()-1 에서 언더플로우 발생


