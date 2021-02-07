#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0;i<skill_trees.size();i++){
        bool isskill=true;
        int count=0;
        for(char c: skill_trees[i]){
            if(c==skill[count])
                count++;
            else if(skill.find(c)>count && skill.find(c)<skill.size()){ //실패
                isskill=false;
                break;
            }
            
            if(count>=skill.size()-1) //맨 마지막 비교 불필요, skill체크 후 진행불필요
                break;
        }    
        if(isskill)
            answer++;
    }
    
    return answer;
}
