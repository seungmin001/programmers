#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end());

    for(; answer<citations.size(); answer++){
        int res= citations.size()-answer; //자신 포함 개수
        if(res <= citations[answer])
            break;
    }
    answer= citations.size()-answer;
    return answer;
}
