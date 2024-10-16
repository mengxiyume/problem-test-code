#define _CRT_SECURE_NO_WARNINGS
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        //≥ı ºªØ
        vv.resize(numRows);
        for (int i = 0; i < numRows; ++i) {
            vv[i].resize(i + 1, 0);
            vv[i][0] = vv[i][i] = 1;
        }
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < vv[i].size(); ++j) {
                if (vv[i][j] == 0) {
                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
                }
            }
        }
        return vv;
    }
};

int main() {
    Solution s;
    vector<vector<int>> temp = s.generate(5);

    return 0;
}