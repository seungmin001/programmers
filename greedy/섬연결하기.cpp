//kruskal, Union-Find
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> parent; //parent저장배열

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2]; //cost끼리만 비교
}

//parent 찾는 함수
int find_p(int a) {
    //자기자신이면 부모임(연결할 때 큰 수를 부모로 두니까)
    if (parent[a] == a) return a; 
    return find_p(parent[a]); //재귀로 계속 거슬러가며 찾음
}

//parent 비교 함수
bool cmp_p(int a, int b) {
    return find_p(a) == find_p(b);
}

//parent맞추기
void connect(int a, int b) {
    //부모
    int a_p = find_p(a);
    int b_p = find_p(b);

    //a parent가 더 크면 b parent가 a_p로 바뀜.
    a_p > b_p ? parent[b_p] = a_p : parent[a_p] = b_p;

    return;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    //정렬 후 cost 작은 값부터 연결
    sort(costs.begin(), costs.end(), compare);

    //Union-Find 이용
    
    //parent초기화 섬 개수만큼. 자기자신이 초기parent
    for (int i = 0; i < n; i++) {
        parent.push_back(i);
    }

    //
    for (vector<int> cost : costs) {
        if (!cmp_p(cost[0], cost[1])) {
            //연결하기
            answer += cost[2]; 
            connect(cost[0], cost[1]);
        }
    }

    return answer;
}
