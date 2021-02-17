#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool check[50001]; //처음에는 map 사용했지만 접근시간때문에 효율성에서 실패해서 스택오버플로우 나지 않게 전역배열 선언함.
int solution(vector<int> people, int limit) {
    int answer = 0;
   
    sort(people.begin(), people.end()); //오름차순 정렬
    
    //가장 앞에 것과 뒤에서부터 가까워지며 뺄 수 있는 짝을 모두 뺀다
    int back = people.size() - 1;
    int front = 0;
    while (back > front) {
        if (!check[back] && people[front] + people[back] <= limit) { //뒤에서부터 뺄 수 있는 가장 첫번째 거를 짝지어서 뺌.
            check[back--] = true;
            check[front++] = true;
            answer++;
        }
        else if (check[back]) { //짝지어 나간애들 pass
            continue;
        }
        else { //뒤에서부터 검사했을 때, 무거워서 혼자 들어가야하는 경우. 반복문을 한번만 돌기 위해 미리 고려함.
            check[back--] = true;
            answer++;
        }
    }
    
    //back==front 하나 남거나, 모두 고려함
    if (!check[front]) {
        answer++;
    }
    
    return answer;
}
