import heapq
heap = []

def solution(jobs):
    answer = 0
    job_count=len(jobs)
    # 요청시점 순 정렬
    jobs=sorted(jobs, key=lambda x: x[0], reverse=True)     
    
    time = 0 # 현재 시간
    isworking=True
    while heap or jobs:       
        while jobs and time >= jobs[-1][0]: # 요청한 시간이 온 경우 다 넣음
            heapq.heappush(heap,(jobs[-1][1],jobs[-1][0]))
            jobs.pop()

        # 요청시간 지난 것 중 가장 소요시간 짧은 것 실행
        if heap : #and time >= heap[-1][0]
            pop_elm=heapq.heappop(heap)
            time += pop_elm[0]
            #print(pop_elm[1], pop_elm[0])
            answer += time - pop_elm[1]

        # heap이 비어있고 jobs에 요청시간이 안 된 작업이 남아있다면 그냥 time+1
        # if not heap and jobs: 위에서 힙이 비워졌을 경우 순서를 넘어가지 않고 그대로 실행되기 때문에 실패가 됨.
        # if문을 따로 쓰기 위해서는 위에 있는 if문에서 continue 필요
        else: 
            time=jobs[-1][0]
   
    return answer//job_count
