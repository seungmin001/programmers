def solution(genres, plays):
    answer = []
    
    total_dict={} # 총 재생횟수 정렬용
    index_dict={} # index, 재생횟수 튜플 저장
    for i in range(len(genres)):
        if genres[i] not in total_dict:
            total_dict[genres[i]]=plays[i]
            index_dict[genres[i]]=[(plays[i],i)]
        else:
            total_dict[genres[i]]+=plays[i]
            index_dict[genres[i]].append((plays[i],i))
    # 장르 전체 재생횟수 순 정렬                       
    total_dict=sorted(total_dict.items(),key=lambda x:x[1],reverse=True)
    
    # 총 재생횟수 높은 장르부터 2,3번 조건 정렬
    for (genre, total_play) in total_dict:
        # play횟수 내림차순, index 오름차순 << 이 부분 참고함
        index_dict[genre]=sorted(index_dict[genre], key=lambda x:(-x[0],x[1]))
        # 장르 내 재생횟수 순 첫번째 두번째 index 추가
        answer += [ idx for (play, idx) in index_dict[genre][:2] ]
                         
    return answer
