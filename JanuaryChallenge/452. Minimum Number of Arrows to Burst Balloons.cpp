bool cmp(vector<int>& a,vector<int>& b){
        return a[1] <b[1];
    }
class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0 || points.size()==1)
            return points.size();
        
        sort(points.begin(),points.end(),cmp);
        int count=1;
        int arrow = points[0][1];
        
        for(int i=1;i<points.size();i++){
            if(points[i][0]>arrow){
                count++;
                arrow = points[i][1];
            }
        }
        return count;
    }
};
