def solution(answers):
    answer = []
    num2_pattern=[2, 1, 2, 3, 2, 4, 2, 5]
    num3_pattern=[3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    d={1:0,2:0,3:0}
    for i,ans in enumerate(answers):
        if ans == num1(i):
            d[1]+=1
        if ans == num2_pattern[i%8]:
            d[2]+=1
        if ans == num3_pattern[i%10]:
            d[3]+=1
            
    m=max(d.values())
    
    for i in range(len(d)):
        if m == d[i+1]:
            answer.append(i+1)
             
    
    return answer

def num1(idx):
    return idx%5+1
