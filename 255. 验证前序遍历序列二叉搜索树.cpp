class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        //if(preorder.size() == 0) return true;
        int new_min = INT_MIN;
        stack<int> s;
        int minus = preorder[0];
        int i = 0;
        while(preorder[i] <= minus){
            s.push(preorder[i]);
            minus = preorder[i];
            i++;
            if(i > preorder.size()-1) break;
        }
        for(int j = i; j < preorder.size(); j++){
            if(new_min > preorder[j]) return false;
            while(true){
                while(!s.empty()){
                    if(preorder[j] > s.top()) {
                        new_min = s.top();
                        s.pop();
                    }
                    else break;
                }
                s.push(preorder[j]);
                break; 
            }                               
        }
        return true;
    }
};
