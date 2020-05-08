/*
Check If It Is a Straight Line

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:
2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.

*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
        if(size <= 2)
            return true;
        int y2MinusY1 = coordinates[1][1]-coordinates[0][1];
        int x2MinusX1 = coordinates[1][0]-coordinates[0][0];
        
        //slope should be same for all 
        //y2-y1/x2-x1 = y3-y1/x3-x1
        // => (y2-y1)(x3-x1)=(x2-x1)(y3-y1)
        for(int i=2; i<size; i++)
        {
            if(y2MinusY1 * (coordinates[2][0] - coordinates[0][0]) != x2MinusX1 * (coordinates[2][1] - coordinates[0][1]))
                return false;
        }
        return true;
    }
};
