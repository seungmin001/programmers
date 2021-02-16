#include<iostream>
#include<string>
#include<vector>
using namespace std;

int move_num(char ch) {
    //if(index[0]==0){
        // if(name[0]-'A' <= 13){ //위로
        //     answer+=name[0]-'A';
        // }
        // else{ //아래로
        //     answer+='Z'-name[0]+1; //'A'에서 'Z'로 가는 횟수 +1
        // }
    //}
    if (ch - 'A' <= 13) { //위로
        cout << "상하 " << ch - 'A' << endl;
        return ch - 'A';
    }
    else { //아래로
        cout << "상하 " << 'Z' - ch + 1 << endl;
        return 'Z' - ch + 1; //'A'에서 'Z'로 가는 횟수 +1
    }
}

int solution(string name) {
    int answer = 0;
    vector<int> index; //'A' 아닌 index 저장
    for (int i = 0; i < name.size(); i++) {
        if (name[i] != 'A')
            index.push_back(i);
    }

    
    if (index[0] != 0) {
        //0과 index[0]사이 이동
        int temp = index[0] < name.size() - index[0] ? index[0] : name.size() - index[0]; //앞 뒤 더 작은거
        answer += temp;
    }
    
    bool isfront = true; //현재 커서가 맨 앞인가 / false : 맨 뒤
    while (!index.empty()) {
        //상하이동
        if (isfront) {
            answer += move_num(name[index[0]]);
        }
        else {
            answer += move_num(name[index.back()]);
        }

        //좌우 이동
        if (index.size() > 1) {
            int front = 0; //index로 가기 위해서 앞으로 이동
            int back = 0; //뒤로 이동
            if (isfront) {
                front = index[1] - index[0];
                back = name.size() - (index.back() - index[0]);
                index.erase(index.begin());
            }
            else {
                front = name.size() - (index.back() - index[0]); //오른쪽진행
                back = index.back() - index[index.size() - 2];
                index.erase(index.end() - 1);
            }

            if (front <= back) { //앞으로가는게 더 짧음
                isfront = true;
                cout << "앞 " << front << endl;
                answer += front;
            }
            else {
                isfront = false;
                cout << "뒤 " << back << endl;
                answer += back;
            }
        }
        else {
            index.pop_back();
        }

    }

    return answer;
}

int main() {

    cout << solution("AAB") << endl;
    return 0;
}
