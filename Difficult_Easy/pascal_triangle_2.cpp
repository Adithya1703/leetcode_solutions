#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rows(rowIndex + 1, 1);
        
        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                rows[j] += rows[j - 1];
            }
        }
        return rows;
    }
};
