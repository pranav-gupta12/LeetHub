class Solution {
public:
    string countOfAtoms(string formula) {
        string element;
        stack<unordered_map<string,int>> s;
        s.push(unordered_map<string,int>());
        int i=0;
        int n = formula.length();
        while(i<n){
            if(formula[i]=='('){
                //new map in stack
                s.push(unordered_map<string,int>());
                i++;
             }
            else if(formula[i]==')'){
// upar wale map k elements update * multi
                unordered_map<string,int> curr = s.top();
                s.pop();
                i++;
                string multi;
                while(i<n && isdigit(formula[i])){
                    multi.push_back(formula[i++]);
                   }
               if(!multi.empty()){
                   int m  = stoi(multi);
                   for(auto &it: curr){
                       string first = it.first;
                       int second = it.second;
                       curr[first] = second*m;
                   }
               }
                  for(auto &it: curr){
                       string first = it.first;
                       int second = it.second;
                       s.top()[first] += second;
                   }
            }
            else
            {
              string element ; 
                element.push_back(formula[i++]);
                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    element.push_back(formula[i++]);
                }
                string multi;
                while(i<n && isdigit(formula[i])){
                    multi.push_back(formula[i++]);
                   }
                int m = 1;
               if(!multi.empty()) m  = stoi(multi);
                s.top()[element] += m;
                
                
            }
            
        }
map<string,int> final(begin(s.top()), end(s.top()));
        string result ; 
        for(auto &it : final){
            string element = it.first;
            int c = it.second;
            result += element;
            if(c>1)
result += to_string(c);
            
            
            
        }
        return result;
    }
};