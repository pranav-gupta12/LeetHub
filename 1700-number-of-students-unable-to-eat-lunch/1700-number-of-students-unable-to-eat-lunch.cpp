class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i=0,j=0;
        while(j<sandwiches.size()){
            if(students[i]==sandwiches[j]){
                i++;
                j++;
            }
            else
            {
                int n = students.size();
                while(students[i]!=sandwiches[j] ){
                       if(i==n){
                           return sandwiches.size()- j;
                       }
                    students.push_back(students[i]);
                    i++;
                    // if(i)
                }
            }
        }
        return 0;
    }
};