#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    if(n==0){
        return answer;
    }
    else{
        int d=n%3;
        char c;
        if(d==0){
            c= '4';
            n = n/3 - 1;
        }
    else if(d==1){
        c= '1';
        n = n/3;
    }
    else if(d==2){
        c= '2';
        n = n/3;
    }

        
    answer+=solution(n);
   
    answer+=c;
    
    return answer;
    }
}
