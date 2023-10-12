/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch1(int st,int en,MountainArray &mountainArr,int target)
    {
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            int element=mountainArr.get(mid);
            if(element==target)
                return mid;
            else if(element>target)
                en=mid-1;
            else 
                st=mid+1;
        }
        return -1;
    }
    int binarySearch2(int st,int en,MountainArray &mountainArr,int target)
    {
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            int element=mountainArr.get(mid);
            if(element==target)
                return mid;
            else if(element<target)
                en=mid-1;
            else 
                st=mid+1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int st=0;
        int en=mountainArr.length()-1;
        int mid;
        while(st<en)
        {
            mid=st+(en-st)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
                st=mid+1;
            else
                en=mid;
        }
        int peak=mid;
        int left=-1,right=-1;
        st=0,en=mountainArr.length()-1;
        left=binarySearch1(st,mid,mountainArr,target);
        right=binarySearch2(mid+1,en,mountainArr,target);
        return left==-1?right:left;
    }
};