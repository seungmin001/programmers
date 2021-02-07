#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;    
    queue<int> q;
    
    for(int i=0;i<progresses.size();i+=1){
        //작업 일 수 계산 : 남은 일 수 / speed + (나머지 존재할 시 1)
        int res=100-progresses[i]; //남은 일수        
        int push; //작업 일 수
    
        if(res%speeds[i]>0){            
            push = res/speeds[i] + 1;
        }
        else{
            push = res/speeds[i];
        }
        
        q.push(push);
    }
    
    while(!q.empty()){
        int pro_std=q.front(); //최상단
        q.pop();
        
        int count=1;
        
        while(q.front() <= pro_std && !q.empty()){ //뒤 작업 중 끝난 것 같이 출력
            count++;
            q.pop();
        }
        
        answer.push_back(count);
    }
    
    return answer;
}
