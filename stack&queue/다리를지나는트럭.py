def solution(bridge_length, weight, truck_weights):
    answer = 0
    
    bridge=[0]*bridge_length

    while bridge:
        # 맨 앞 삭제
        bridge.pop(0)
        
        # 못 들어올 경우: 0(count를 위한 빈 도로용) / 들어오는 경우: 맨 앞 트럭 append
        if truck_weights:
            if sum(bridge)+truck_weights[0] <= weight:
                bridge.append(truck_weights.pop(0))   
            else: # 들어올 트럭이 없으면 0을 추가하지 않는다. bridge 0되면 while문 빠져나감
                bridge.append(0)    
        answer+=1
            
    return answer
