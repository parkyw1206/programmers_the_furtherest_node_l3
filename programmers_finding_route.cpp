/************************************************************
 *  name : Youngwoo Park
 *  date : 10-05-2020
 *  level: l3
 *  problem source: programmers
 *  lang: C++
 *  skill:  bfs
 * *********************************************************/
#include <queue>
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int d[20001][20001];
int dist[20001];
bool visited[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int point;
    int max = 0;
    
    queue<int> q;
    
    for(int i = 0 ; i < edge.size() ; i++){
        d[edge[i][0]][edge[i][1]] = 1;
        d[edge[i][1]][edge[i][0]] = 1;
    }
    
    q.push(1);
    dist[1] = 0;
    visited[1] = true;
    
    while(!q.empty()){
        point = q.front();
        q.pop();
        for(int i = 2 ; i <= n ; i++){
            if(d[point][i]== 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
                dist[i] = dist[point]+1;
                if(max < dist[i])
                    max = dist[i];
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(max == dist[i])
            answer++;
    }    
    return answer;
}