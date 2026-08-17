class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];

            graph[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty())
        {
            int course = q.front();
            q.pop();

            ans.push_back(course);

            for(int next : graph[course])
            {
                indegree[next]--;

                if(indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        if(ans.size() != numCourses)
        {
            return {};
        }

        return ans;
    }
};