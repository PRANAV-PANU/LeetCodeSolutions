class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v;
        string word="";
        
        //converting senetence to array of str
        for(auto it:s){
            if(it==' '){
                v.push_back(word);
                word="";
            }else{
                word+=it;
            }
        }
        v.push_back(word);
        
        if(v.size()!=pattern.size())
            return false;
        
        unordered_map<string,char>W2C;
        unordered_map<char,string>C2W;
        
        for(int i=0;i<v.size();i++){
            //word is not appeared before
            if(W2C.count(v[i])==0){
                //char is not appeared before in pattern
                if(C2W.count(pattern[i])==0){
                    //setting in both map
                    W2C[v[i]]=pattern[i];
                    C2W[pattern[i]]=v[i];                    
                }
                else{
                    //means word not exists but char exists
                    return false;
                }
            }else{
                
                //means word exists but char not exists  (or)  word , char pair mismatched
                if(C2W.count(pattern[i])==0||W2C[v[i]]!=pattern[i]){
                  return false;
                }
            }
        }
        return true;
    }
};
