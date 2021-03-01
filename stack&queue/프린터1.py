def solution(priorities, location):
    answer = 0
    
    # 현재 비교 index
    idx=0
    # 몇번째
    count=0
    while priorities:
        if max(priorities) is not priorities[idx]:
            if idx<len(priorities)-1:
                idx+=1
            else:
                idx=0
            continue
        else:
            priorities.pop(idx)
            count+=1
            if idx==location:
                return count
            elif idx<location:
                location-=1

            if idx==len(priorities):
                idx=0   
                
    return answer
