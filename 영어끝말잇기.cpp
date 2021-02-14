#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int wrong;
    bool iswrong=false;
    
    for(int i=1;i<words.size();i++){
        int last=words[i-1].size(); //전 단어 길이
        if(words[i][0]!=words[i-1][last-1]){ //현재 단어 맨 앞 글자, 전 단어 맨 뒤 글자 비교
            wrong=i;
            iswrong=true;
            break;
        }
        vector<string>::iterator it=find(words.begin(), words.end(), words[i]);
        if(it-words.begin()!=i) 
        // 현재 단어가 앞에 나왔으면 틀림
        {   wrong=i;
            iswrong=true;
            break;
        } 
    }
    
    if(iswrong){ //탈락자 생긴 경우
        answer.push_back(wrong%n+1);
        answer.push_back(wrong/n+1);
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    
    
    return answer;
}
