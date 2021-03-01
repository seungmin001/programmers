import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while len(scoville) > 1 and scoville[0]<K:
        top=heapq.heappop(scoville)
        top2=heapq.heappop(scoville)
        heapq.heappush(scoville, top+top2*2)
        answer+=1
    
    # 하나 남았는데 K보다 작을 경우
    if scoville[0] <K:
        return -1
        
    return answer
