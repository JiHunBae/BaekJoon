#include <iostream>
#include <stack>

using namespace std;

int graph[1001][1001];
int visit[1001];
stack <int> wait_list;

int main() {
    int n, m, u, v, cur, visit_cnt = 0, component_cnt = 0;
    scanf("%d%d", &n, &m);

    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    while(visit_cnt != n) {
        if(wait_list.empty()) {
            for(int j = n; j > 0; j--) {
                if(visit[j] == 0) {
                    wait_list.push(j);
                    break;
                }
            }
            ++component_cnt;
        }
        cur = wait_list.top();
        wait_list.pop();

        if(visit[cur] != 0)
            continue;

        visit[cur] = 1;
        ++visit_cnt;
        for(int target = n; target > 0; target--) {
            if(graph[cur][target] != 0 && visit[target] == 0)
                wait_list.push(target);
        }
    }
    printf("%d", component_cnt);
}