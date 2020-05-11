/*
Flood Fill

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

Hide Hint #1  
Write a recursive function that paints the pixel if it's the correct color, then recurses on neighboring pixels.

*/

class Solution {
public:
    int rows, cols;
    
    bool isValid(int x, int y)
    {
        if(x >= 0 && x < rows && y >= 0 && y < cols)
            return true;
        return false;
    }
    
    void fillUtil(vector<vector<int>>& image, int sr, int sc, int orgColor, int newColor) {
        int rowOp[4]={0, -1, 0, 1};    //left, up, right, down
        int colOp[4]={-1, 0, 1, 0};    //left, up, right, down
        int tpx, tpy;
        
        for(int i=0; i<4; i++)
        {
            tpx = sr + rowOp[i];
            tpy = sc + colOp[i];
            if(isValid(tpx, tpy) && image[tpx][tpy] == orgColor)
            {
                image[tpx][tpy] = newColor;
                fillUtil(image, tpx, tpy, orgColor, newColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        rows = image.size();
        if(!rows)
            return {};
        cols = image[0].size();
        int tp = image[sr][sc];
        image[sr][sc] = newColor;
        // SAURABH - very very important check as avoiding this will cause stack
        //           overflow as it'll become infinite loop
        if(newColor != tp)  
            fillUtil(image, sr, sc, tp, newColor);
        return image;
    }
};
