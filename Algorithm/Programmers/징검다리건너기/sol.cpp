#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Can_Cross(int& n, int& k__, vector<int>& v__){
    int count = 0;
    
    for(int i = 0; i < v__.size(); i++){
        if(v__[i] - n <= 0)
            count++;
        else
            count = 0;
        if(count >= k__)
            return true;
    }
    return false;
}

int binary_search(vector<int> v_, int k_)
{
    int first = 1, last = *max_element(v_.begin(), v_.end());
    
    while(first <= last){
        int mid = (first + last) / 2;
        if(Can_Cross(mid, k_, v_))
            last = mid - 1;
        else
            first = mid + 1;
    }

    return first;
}


int solution(vector<int> stones, int k) {

    int ans = binary_search(stones,k);
    return ans;
}