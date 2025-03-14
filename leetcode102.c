class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(students[i]); // Push all students into the queue
        }

        int j = 0, count = 0; // 'count' tracks consecutive students unable to eat

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x == sandwiches[j]) { // If student can eat the sandwich
                j++;
                count = 0; // Reset count since a student was able to eat
            } else { 
                q.push(x); // Push back if they can't eat
                count++;
            }

            if (count == q.size()) break; // If all students in queue are stuck, stop
        }
        
        return q.size(); // Remaining students who couldn't eat
    }
};