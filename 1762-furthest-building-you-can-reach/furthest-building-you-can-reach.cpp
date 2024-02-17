class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        int index=0, difference=0;
        for(index=0; index<heights.size()-1; index++)
        {
            difference = heights[index+1] - heights[index];
            if(difference <= 0)
                continue;
            
            bricks = bricks-difference;
            q.push(difference);
            if(bricks < 0)
            {
                bricks = bricks + q.top();
                q.pop();
                ladders--;
            }

            if(ladders < 0)
                break;
        }
        return index;
    }
};