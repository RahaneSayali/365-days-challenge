class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int ans = 0;
        priority_queue<int> pq , student;
        for(int i=0;i<seats.size();i++){
            pq.push(seats[i]);
            student.push(students[i]);
        }
        for(int i=0;i<seats.size();i++){
            int a = pq.top();
            int b = student.top();
            pq.pop();
            student.pop();
            ans+=abs(a-b);
        }
        return ans;
    }
};