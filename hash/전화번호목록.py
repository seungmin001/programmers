def solution(phone_book):
    answer = True
    dict={}
    phone_book.sort()
    before='a' # 첫번째
    
    for p in phone_book:
        if before in p:
            return False
        before=p
        
    
    return answer
