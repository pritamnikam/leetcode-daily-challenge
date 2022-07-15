/*
1710. Maximum Units on a Truck
https://leetcode.com/problems/maximum-units-on-a-truck/

You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, 
where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. 
You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.


*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

namespace {

    class Solution {
    public:
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
            // sort by |numberOfUnitsPerBox|.
            sort(boxTypes.begin(),
                 boxTypes.end(), 
                 [](const vector<int>& a, const vector<int>& b) { 
                    return a[1] > b[1];
                });


            int units = 0;

            // for every box type
            for (auto& it : boxTypes) {
                int numberOfBoxes = it[0];
                int numberOfUnitsPerBox = it[1];

                // as long as there is space left for more boxes
                if (truckSize > 0) {
                    int boxes = min(truckSize, numberOfBoxes);
                    units += (numberOfUnitsPerBox * boxes);
                    truckSize -= boxes;
                }
            }
            return units;
        }
    };
}

void testMaximumUnitsOnATruck() {
    /*
        Example 1:
        Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
        Output: 8
    
    */

    vector<vector<int>> boxTypes = { {1, 3} , {2, 2}, {3, 1} }; int truckSize = 4;
    cout << "Maximum Units on a Truck: " << Solution().maximumUnits(boxTypes, truckSize) << endl;

    /*
        Example 2:
        Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
        Output: 91
    */
    boxTypes = { {5, 10},{2, 5},{4, 7},{3, 9} }, truckSize = 10;
    cout << "Maximum Units on a Truck: " << Solution().maximumUnits(boxTypes, truckSize) << endl;
}
