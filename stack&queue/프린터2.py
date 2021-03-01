from collections import deque
def solution(priorities, location):
    answer = 0  # 빠져나간 개수
    
    deq=deque(priorities) # deque
    l=location # location값
    
    while deq:
        m = max(deq) # 현재 우선순위 max
        cur=deq.popleft() # 현재 맨 앞
        if cur < m : # 우선순위 낮음
            deq.append(cur)
            # location 한 칸 앞으로
            if l==0:
                l=len(deq)-1
            else:
                l-=1
        else: # 우선순위 가장 높음
            answer+=1
            if l==0:
                return answer
            else:
                l-=1
            

    return answer
