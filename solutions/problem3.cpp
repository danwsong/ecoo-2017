/*
 Your first instinct to solve this problem might be to loop through the 
 mountains, then compare each of the mountains to that mountain, seeing if any 
 mountains intersect the line of sight of between the mountains. However, this 
 algorithm would require O(n³) time to run, and thus the program would take way 
 too long to run with a dataset of N = 10000.
 
 A much simpler solution exists, which involves comparing the slopes of the
 line connecting the peaks of the mountains to the highest slope so far. If
 the next slope is higher, then the peak is visible, and if not, the peak is
 not visible. This algorithm only requires O(n²) time to run, which is perfectly
 reasonable considering the maximum size of the dataset.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int visibility(vector<int> heights, int mountain) {
    double highestSlope = -0x7FFFFFFF;
    int visibility = 0;
    for (int i = mountain + 1; i < heights.size(); i++) {
        // Slope for the line connecting the peaks the current monutain and the mountains after the current mountain
        double slope = (double) (heights[i] - heights[mountain]) / (double) (i - mountain);
        // Mountain is visible if the slope is higher than the largest slope so far
        if (slope > highestSlope) {
            highestSlope = slope;
            visibility++;
        }
    }
    highestSlope = -0x7FFFFFFF;
    // Compare mountains before the current mountain
    for (int i = mountain - 1; i >= 0; i--) {
        double slope = -((double) (heights[i] - heights[mountain]) / (double) (i - mountain));
        if (slope > highestSlope) {
            highestSlope = slope;
            visibility++;
        }
    }
    return visibility;
}

int main(int argc, const char * argv[]) {
    freopen("DATA31.txt", "r", stdin);
    
    int N;
    while (cin >> N) {
        vector<int> heights(N);
        // Read in the heights of the mountains
        for (int i = 0; i < N; i++) {
            cin >> heights[i];
        }
        int maxVisibility = 0, maxMountain = 0;
        // Determine the mountain with the maximum visibility, with preference for the leftmost mountain in the case of ties
        for (int i = 0; i < N; i++) {
            int cuurentVisibility = visibility(heights, i);
            if (cuurentVisibility > maxVisibility) {
                maxVisibility = cuurentVisibility;
                maxMountain = i;
            }
        }
        cout << maxMountain + 1 << endl;
    }
    
    return 0;
}
