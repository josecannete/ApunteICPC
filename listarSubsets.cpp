#include <bits/stdc++.h>
using namespace std;
// Dado un vector, genera todos los subconjuntos
vector<vector<int>> subsets(vector<int>& nums) {
    int subsets = 1 << nums.size();
    vector<vector<int> > ret;
    for (int i = 0; i < subsets; i++) {
        int aux = i;
        int add = 0;
        vector<int> sub;
        while (aux != 0 && add < nums.size()) {
            if (aux & 1)
                sub.push_back(nums[add]);
            aux >>= 1;
            add++;
        }
        ret.push_back(sub);
    }
    return ret;
}

int main(){
  vector<int> nums(3);
  nums[0] = 1;
  nums[1] = 2;
  nums[2] = 3;

  vector<vector<int> > subst = subsets(nums);
}
