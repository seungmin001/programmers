#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    const int truck_num=truck_weights.size();
    
    queue<int> truck_q; //현재 다리위에 있는 트럭 index
    vector<int> truck_length; //트럭마다 다리 어느 정도 지났는지
    for(int i=0;i<truck_num;i++){ 
        truck_length.push_back(0); // 지나간 길이 0으로 초기화
    }
    
    int left_w=weight; //현재 다리에 수용 가능 무게
    int back_i=1; //다음에 올라올 트럭 index
    int front_i=0; //다리 제일 앞의 트럭 index
    
    truck_q.push(0); //첫번째 트럭
    left_w-=truck_weights[0];
    int answer = 0;
    while(!truck_q.empty()){ 
        answer++; //초 증가
        
        //원래 다리 위에 있던 것 +1씩     
        for(int i=front_i;i<back_i;i++){
            truck_length[i]+=1;
        }
    
         if(truck_length[front_i]==bridge_length) //맨 앞 트럭 통과 여부 조사
        {
            left_w+=truck_weights[front_i++];
            truck_q.pop();
        }
                    
        if(back_i == truck_num){
            //뒤에 트럭 더 없을 때 그냥 패스
            continue;
        }
        int next=truck_weights[back_i]; //다음에 올라올 트럭 무게
        //cout<<left_w<<" "<<next<<"\n";
        if(left_w - truck_weights[back_i] >= 0){ //next로 하면 안됨..
            //다리 진입
            left_w-=next;
            truck_q.push(back_i++);            
        }
  
    }
 
    return answer+1;
}
