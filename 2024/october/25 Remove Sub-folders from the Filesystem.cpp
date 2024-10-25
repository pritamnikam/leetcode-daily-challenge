// 1233 Remove Sub-folders from the Filesystem
// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // sort the folders alphabetically
        sort(folder.begin(), folder.end());

        // Initialize the result vector and add the first folder
        vector<string> result;
        result.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string lastFolder = result.back();
            lastFolder += '/';

            // check whether the current folder start with the last added folder path
            if (folder[i].compare(0, lastFolder.size(), lastFolder) != 0) {
                result.push_back(folder[i]);
            }
        }

        return result;
    }
};
