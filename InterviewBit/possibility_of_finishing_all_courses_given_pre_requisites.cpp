// Possibility of finishing all courses given pre-requisites
/*

There are a total of A courses you have to take, labeled from 1 to A.
Some courses may have prerequisites, for example to take course 2 you have to first 
take course 1, which is expressed as a pair: [1,2].
Given the total number of courses and a list of prerequisite pairs, is it possible 
for you to finish all courses?
Return 1 if it is possible to finish all the courses, or 0 if it is not possible to 
finish all the courses.

Input 1:
    A = 3
    B = [1, 2]
    C = [2, 3]

Output 1:
    1

Explanation 1:
    It is possible to complete the courses in the following order:
        1 -> 2 -> 3

*/

#define MAXN 100005
#define BLACK 0
#define BLUE 1
#define GREY 2
vector<int> g[MAXN];
void check_cycle(int u, int visited[],bool &f) {
  visited[u] = BLUE;
  for(auto v : g[u]) {
    if(visited[v] == BLACK) {
      check_cycle(v, visited, f);
    } else if(visited[v] == BLUE) {
      //cycle found
      f = true;
    }
  }
  visited[u] = GREY;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    bool f = false;
    int visited[MAXN] = {0};
    for(int i = 1;i <= A; i++) {
      g[i].clear();
    }
    for(int i=0; i<B.size(); i++) {
      g[B[i]].push_back(C[i]);
    }
    for(int i = 1; i <= A; i++) {
      if(visited[i] == BLACK) {
        check_cycle(i, visited, f);
        if(f) {
          break;
        }
      }
    }
    return !f;
}
