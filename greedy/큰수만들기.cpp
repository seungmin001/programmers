#include <string>
#include <vector>
#include<iostream>
using namespace std;

//아마도! 시간 복잡도 n * n
string solution(string number, int k) {
    string answer = "";

    int cur_pos = 0; //max search 시작점
    int n = number.size();
    
    for(int i=n-k;i>0;i--) { //cur_pos ~  까지 중에 max를 n-k번 뽑기
        //총 n-k를 뽑아야하므로 처음에는 뒤에 n-k-1개 수를 남겨놔야한다.
        //그러므로 max 서치 끝 index는 k부터 1씩 증가하는 범위에서만 고려해야함.
        
        //string sub=number.substr(cur_pos, (k+i)-cur_pos+1); 처음에는 substr이용했다가 cur_pos 계산이 꼬여서 바꿈
        char local_max = number[cur_pos];
        int local_max_i=cur_pos;
        for (int j = cur_pos; j <= n-i; j++) { //cur_pos부터 
            if (number[j] > local_max) {
                local_max = number[j];
                local_max_i = j;
            }
        }
        answer += local_max; //앞자리부터 추가
        cur_pos = local_max_i+1; //다음에는 뽑은 애 다음부터 시작
        //cout << local_max_i <<" "<<local_max<< "\n";
    }

    return answer;
}
