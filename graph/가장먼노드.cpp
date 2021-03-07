#include <string>
#include <vector>
#include <queue>
#include <climits>
#include<algorithm>
using namespace std;
int node=20000;
int dist[20001];
bool visit[20001];
vector<int> adj[20001];

queue<int> q;

void BFS(int x){
    q.push(x);
    visit[x]=true;
    
    while(!q.empty()){
        int f=q.front(); q.pop();
        //인접 node 검사
        for(int i=0;i<adj[f].size();i++){
            if(visit[adj[f][i]]==false){
                visit[adj[f][i]]=true;
                //최단거리 저장
                dist[adj[f][i]]=dist[f]+1;  //나와 연결되어있는것보다+1              
                q.push(adj[f][i]);
            }            
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    //edge정보 저장
    for(int i=0;i<edge.size();i++){
        //양방향 저장
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    //BFS실행    
    BFS(1);
    
    //max값 추출 후 비교해서 answer구하기
    int max=*max_element(dist,dist+(node+1));
    for(int i=1;i<node+1;i++){
        if(max==dist[i]){
            answer++;
        }
    }
    return answer;
}
