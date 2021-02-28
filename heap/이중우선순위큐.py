p_q=[]
def solution(operations):
    answer = []
    
    for op in operations:
        (op_name, op_value)=op.split()
        if op_name=="I": # 값 삽입
            insert_q(int(op_value))
        elif op_name=="D":
            # list에 값이 존재하면
            if p_q:                
                if op_value=='1': # 최대값 삭제                    
                    p_q.pop()
                else: # 최솟값 삭제
                    del p_q[0]
        
    # 큐가 비어있으면            
    if not p_q:              
        answer = [0,0]
    else:
        answer = [ p_q[-1] , p_q[0] ]
        
    return answer
    
def insert_q(x):
    isput=False
    for elm in p_q:
        # x가 현재 element보다 작거나 같을 때 insert
        if x > elm:
            continue
        else:
            p_q.insert(p_q.index(elm),x)
            isput=True
            break
    # x가 제일 큼(맨 뒤에 삽입)
    if not isput:
        p_q.append(x)
