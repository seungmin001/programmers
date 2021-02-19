#include <string>
#include <vector>
#include<algorithm>
using namespace std;

//들어간 순서 오름차순 정렬
bool compare(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;

    //들어오는 순서대로 정렬. 순서대로 가면 나가는 지점만 비교하면 된다.
    sort(routes.begin(), routes.end(), compare);
    //현재 제일 뒤
    int recent_end = routes[0][1];
    for (int i = 0; i < routes.size()-1;i++) {
     
        //현재 차의 끝보다 뒤의 차의 앞이 더 뒤면 거리가 공유되지 않는 거기 때문에 카메라가 필요함.
        if (recent_end < routes[i + 1][0]) {
            answer++;
            recent_end = routes[i + 1][1]; //끝 값 갱신
        }
        //현재 차 거리 안에 다음 차가 속해있다면, 
        //비교는 현재 거리를 달리는 차 중 가장 먼저 나가는 차와 비교해야하므로(교집합) 값 갱신
        else if (recent_end > routes[i + 1][1]) {
            recent_end = routes[i + 1][1];
        }
        
        //이 외에는 

    }
    //마지막 나가는 차는 위에서 전의 차 기준 비교만 해줘서 카메라+1
    return answer+1;
}
