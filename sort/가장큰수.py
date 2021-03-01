from functools import cmp_to_key
def solution(numbers):
    answer = ''

    temp_arr=sorted(numbers, key=cmp_to_key(cmp_func),reverse=True)

    for number in temp_arr:
        answer+=str(number)
        
    # "0000"인 경우 처리
    answer=str(int(answer))
    return answer

def cmp_func(n1,n2):
    if int(str(n1)+str(n2)) < int(str(n2)+str(n1)):
        return -1
    elif int(str(n1)+str(n2)) > int(str(n2)+str(n1)):
        return 1
    else:
        return 0
