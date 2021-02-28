def solution(brown, yellow):
    answer = []

    for i in range(int(yellow ** (1/2))): # i=1 i*i<=n
        if yellow % (i+1) == 0: # 1부터 시작
            row = i+1 # 세로 / 세로가 더 짧다
            col = yellow//row # 가로
            if 2*(col+2) + 2*row == brown: # 실제 카펫 모양이면
                return [col+2, row+2]
            
    return answer
