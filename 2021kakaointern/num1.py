#1
def solution(s):
    answer = 0
    eng={'zero':'0','one':'1','two':'2','three':'3','four':'4',
	'five':'5',
	'six':'6',
	'seven':'7',
	'eight':'8',
	'nine':'9'}

    while(1): #key가 s에 없을 때 까지
        isdone=True 
        for key in eng.keys():
            if s.find(key)!=-1:
                s=s.replace(key,eng[key])
            
            if s.find(key)!=-1: # 한번 더 검사해서 똑같은 key에 대해 또 있는지 검사
                isdone=False
                break
            else:
                isdone=True
                
        if isdone:
            return int(s)

    
    return answer
