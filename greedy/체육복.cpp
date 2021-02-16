#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n; //체육수업을 들을 수 있는 학생들. 
    
    map<int,bool> res_info; //key: 몇번째 학생, value: 여벌 있는지
    for(int i=0;i<reserve.size();i++){ 
        res_info[reserve[i]]=1; //여벌 있음 . 다른 번호는 bool default값 0이라 상관 x
    }
    
    for(int i=0;i<lost.size();i++){
        //자기꺼 사용해야하므로 그 경우 먼저 처리
        if(res_info[lost[i]]){
            res_info[lost[i]]=0;
            lost.erase(lost.begin()+i); //여벌 있으므로 lost에서 제외
            i--; //erase해서 element들이 다 앞당겨짐
        }
    }
    
    for(int i=0;i<lost.size();i++){
        if(res_info[lost[i]-1]){ //앞 사람 있는지 먼저 검사(최대값)
            res_info[lost[i]-1]=0;
            lost.erase(lost.begin()+i); //여벌 있으므로 lost에서 제외
            i--; //erase해서 element들이 다 앞당겨짐
        }
        else if(res_info[lost[i]+1]){ //뒷 사람
            res_info[lost[i]+1]=0;
            lost.erase(lost.begin()+i); //여벌 있으므로 lost에서 제외
            i--;
        }
    }

    return answer-lost.size();
}
