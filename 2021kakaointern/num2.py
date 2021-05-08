#2
def solution(places):
    answer = []
    #print(list(range(8)))
    
    for place in places: # 한 대기실 [""한줄,"",]
        iscorrect=True
        person_tuple=[] #(행,열)
        
        for i in range(5): # 사람 위치 저장
            for j in range(5):
                if place[i][j]=='P':
                    #print('tuple ',i,j)
                    person_tuple.append((i,j))
        for i in range(len(person_tuple)):
            for j in range(i+1,len(person_tuple)):
                rw=abs(person_tuple[i][0]-person_tuple[j][0]) #행 비교
                cl=abs(person_tuple[i][1]-person_tuple[j][1]) # 열 차이                
                if rw+cl > 2: # 통과
                    #print(person_tuple[i]," and ",person_tuple[j],'pass')
                    continue
                elif rw+cl==1:
                    answer.append(0)
                    iscorrect=False
                    break
                else:
                    if rw==0:
                        col_std= i if person_tuple[i][1]<person_tuple[j][1] else j
                        right=place[person_tuple[col_std][0]][person_tuple[col_std][1]+1]
                        #right=place[person_tuple[i][0]][person_tuple[i][1]+1]
                        if right!='X':
                            print(person_tuple[i]," and ",person_tuple[j])
                            answer.append(0)
                            iscorrect=False
                            break
                    elif cl==0:
                        row_std= i if person_tuple[i][0]<person_tuple[j][0] else j
                        down=place[person_tuple[row_std][0]+1][person_tuple[row_std][1]]
                        #down=place[person_tuple[i][0]+1][person_tuple[i][1]]
                        if down!='X':
                            print(person_tuple[i]," and ",person_tuple[j])
                            answer.append(0)
                            iscorrect=False
                            break
                    else:
                        if person_tuple[i][1]>person_tuple[j][1]:
                            
                            right=place[person_tuple[i][0]][person_tuple[i][1]-1]
                            row_std= i if person_tuple[i][0]<person_tuple[j][0] else j
                            down=place[person_tuple[row_std][0]+1][person_tuple[row_std][1]]
                            if down!='X' or right!='X':
                                print(person_tuple[i]," and ",person_tuple[j])
                                answer.append(0)
                                iscorrect=False
                                break
                            
                        else:
                            col_std= i if person_tuple[i][1]<person_tuple[j][1] else j
                            right=place[person_tuple[col_std][0]][person_tuple[col_std][1]+1]
                            row_std= i if person_tuple[i][0]<person_tuple[j][0] else j
                            down=place[person_tuple[row_std][0]+1][person_tuple[row_std][1]]
                            if down!='X' or right!='X':
                                print(person_tuple[i]," and ",person_tuple[j])
                                answer.append(0)
                                iscorrect=False
                                break
                #print(person_tuple[i]," and ",person_tuple[j],'pass')
            if not iscorrect:
                break
        if iscorrect:
            answer.append(1)        
    return answer
