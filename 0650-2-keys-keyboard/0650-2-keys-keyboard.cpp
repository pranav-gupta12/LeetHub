class Solution {
public:
    int minSteps(int n) {
         if(n == 1)
            return 0;
        
        //copy A, and then paste A
        if(n == 2)
            return 2;
        
      
        
    
            int i = n/2; //start from largest factor
            while(i >= 1) {
                if(n%i == 0) {
                    //wow, largest factor and that will give me optimal solution.
                    //stop right there
                    int steps_to_reach_factor = minSteps(i);
                    int copy_that_first       = 1;
                    int paste_frequency       = (n/i) - 1;
                   
                return steps_to_reach_factor + copy_that_first + paste_frequency;
                }
                else
                i--;
            }
        
        
        return n;
    }
};