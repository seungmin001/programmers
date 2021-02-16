#include<iostream>
#include<string>
#include<vector>
using namespace std;

//'A'에서 얼마나 이동해야하는가 반환
int move_num(char ch) { 
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
        //처음 위치는 0이므로, 0과 index[0]사이 이동
        answer += index[0];
    }
    
    bool isfront = true; //현재 커서가 맨 앞인가 / false : 맨 뒤
    while (!index.empty()) {
        //상하이동(알파벳)
        if (isfront) {
            answer += move_num(name[index[0]]);
        }
        else {
            answer += move_num(name[index.back()]);
        }

        //좌우 이동
        if (index.size() > 1) {
            int front = 0; //index로 가기 위해서 오른쪽으로 이동
            int back = 0; //왼쪽으로 이동
            if (isfront) { //현재 첫번째 요소위치면
                front = index[1] - index[0]; //2번째요소까지 거리
                back = name.size() - (index.back() - index[0]); //마지막요소까지 거리
                index.erase(index.begin()); //값 구했으므로 벡터에서 지움
            }
            else {
                front = name.size() - (index.back() - index[0]); //오른쪽진행
                back = index.back() - index[index.size() - 2];
                index.erase(index.end() - 1);
            }

            if (front <= back) { //앞으로가는게 더 짧음. 다음 위치는 맨 앞
                isfront = true;
                //cout << "앞 " << front << endl;
                answer += front;
            }
            else { //다음 기준 위치 맨 뒤
                isfront = false;
                //cout << "뒤 " << back << endl;
                answer += back;
            }
        }
        else { //하나 남았으므로 비교할 필요 없어서 빼고 while문 빠져나가기
            index.pop_back();
        }

    }

    return answer;
}
