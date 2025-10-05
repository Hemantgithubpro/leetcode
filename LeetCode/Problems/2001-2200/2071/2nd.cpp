#include <bits/stdc++.h>
using namespace std;
// could not do it.
int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength);

int main(){
    vector<int> tasks = {5,9,8,5,9};
    vector<int> workers = {1,6,4,2,6};
    int pills = 1;
    int strength = 5;
    
    // vector<int> tasks = {10,15,30};
    // vector<int> workers = {0,10,10,10,10};
    // int pills = 3;
    // int strength = 10;
    cout << maxTaskAssign(tasks, workers, pills, strength) << endl;
}

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,int strength) {
    int n = tasks.size();
    vector<int> a(n);
    unordered_set<int> workersused;
    unordered_set<int> tasksdone;
    sort(workers.begin(), workers.end());
    sort(tasks.begin(), tasks.end());
    for (int i = 0; i < n; i++) {
        for(int j=0; j<n; j++){
            if(tasks[i]<=workers[j] && (workersused.find(j)==workersused.end() && tasksdone.find(i)==tasksdone.end())){
                workersused.insert(j);
                tasksdone.insert(i);
            }
        }
        for (int j = 0; j < n; j++) {
            if(tasks[i]<=workers[j] && (workersused.find(j)==workersused.end() && tasksdone.find(i)==tasksdone.end())){
                workersused.insert(j);
                tasksdone.insert(i);
            }
            else if(tasks[i]>workers[j] && (workersused.find(j)==workersused.end() && tasksdone.find(i)==tasksdone.end())){
                if ((tasks[i] <= workers[j] + strength) && pills>0) {
                    workersused.insert(j);
                    tasksdone.insert(i);
                    pills--;
                }
            }
        }
    }
    return tasksdone.size();
}