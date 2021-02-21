# Dictionary
def solution(participant, completion):
    answer = ''
    dict = {}
    for p in completion:
        if p in dict:
            dict[p]+=1
        else:
            dict[p]=1
             
    for p in participant:
        if p in dict:
            if dict[p]==0:
                return p
            else:
                dict[p]-=1
        else:
            return p
        
        
    return answer
