/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);//记录所有课的入度
        vector<vector<int> > adjacency(numCourses);//记录临界表，未初始化的为0
        for (int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
            adjacency[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q; //0入度的点
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
                numCourses--;
            }
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for (int i = 0; i < adjacency[temp].size(); i++) {
                indegree[adjacency[temp][i]]--;
                if (indegree[adjacency[temp][i]] == 0) {
                    q.push(adjacency[temp][i]);
                    numCourses--;
                } 
            }
        } 
        if (numCourses == 0) return true;
        return false;
    }
};
// @lc code=end

