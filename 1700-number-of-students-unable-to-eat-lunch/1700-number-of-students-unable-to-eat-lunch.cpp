class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int m = sandwiches.size();
        queue<int>q;
        int top = 0, count = 0;//top points to the current sandwich

        for(int e : students)
            q.push(e);

        while(!q.empty() && count != q.size()){// count keeps the track of students processed in continuous empty
            if(q.front() == sandwiches[top]) {//if student at front can eat the sandwich at top
            count = 0;
            top++;//increment top pointer
            q.pop();
        } else {
            int front = q.front();
            q.pop();    
            q.push(front);//move the student to the rear
            count++;
        }
    }
    return q.size();
    }
};