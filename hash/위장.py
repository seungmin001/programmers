def solution(clothes):
    d = {} # hash
    for (name,kind) in clothes:
        if kind in d:
            d[kind].append(name) 
        else:
            d[kind]=[name]
    
    answer = 1
    # 각 종류당 : len(v) C 1 (하나 고르는 조합)
    # 다 곱한 다음에 아무것도 고르지 않은 경우 -1
    for k,v in d.items():
        answer*=len(v)+1
        
    return answer-1
