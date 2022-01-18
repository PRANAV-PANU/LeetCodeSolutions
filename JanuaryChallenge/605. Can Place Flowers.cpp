class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int no) {
        int count=0;
        int n = flowerbed.size();
        
        for(int i=0;i<n;i++){
            if(flowerbed[i]==0 &&(i==0||flowerbed[i-1]==0) && (i==n-1 || flowerbed[i+1]==0)){
                flowerbed[i]=1;
                count++;
            }
        }
        
        return count>=no;
    }
};
