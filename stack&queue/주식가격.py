def solution(prices):
    answer = []
    
    for i in range(len(prices)-1):
        temp_j=i+1
        # 자기보다 작은 것 만날 때까지 진행
        for j in range(i+1,len(prices)):
            temp_j=j
            if prices[j]<prices[i]:
                break   
        # 그 index 차이가 떨어지지 않은 기간
        answer.append(temp_j-i)
        
    # 마지막은 무조건 0    
    answer.append(0) 
    
    return answer
