# 3
# 효율성 실패

def solution(n, k, cmd):
    answer = ''
    li=[i for i in range(n)] # n==8
    #print(li)
    n_stack=[] # 최근 삭제 행 내용물
    i_stack=[] # 최근 삭제 행 실제 인덱스
    for ins in cmd:
        ins_n=ins.split()
        if ins[0]=='U':
            k-=int(ins_n[1])           
            #print('u',k)
        elif ins[0]=='D':
            k+=int(ins_n[1])
            #print('d',k)
        elif ins=='C':
            n_stack.extend([li[k]]) # 선택 행 내용물 저장
            i_stack.extend([k]) # 선택 행 그 당시 인덱스 저장
            
            if k!=len(li)-1: #마지막 행이 아니면
                #li=li[:k]+li[k+1:] # 선택 행 삭제
                li.pop(k)
            else: #마지막 행이면
                li.pop()
                #li=li[:k]
                k=k-1
            
            #print('c',li,k)
        elif ins=='Z':
            nn=n_stack.pop() # 넣을 내용물
            i=i_stack.pop() # 넣을 인덱스
            if i<=k:
                k+=1
            li.insert(i,nn)
            #print('z',li,k)
    
    temp_li=[i for i in range(n)]
    not_same=set(temp_li)-set(li)
    #answer=list("O"*n)
    for iterate in range(n):
        if iterate in not_same:
            answer+="X"
        else:
            answer+="O"
    #for n_s in not_same:
        #answer[n_s].replace("X")

    return answer


