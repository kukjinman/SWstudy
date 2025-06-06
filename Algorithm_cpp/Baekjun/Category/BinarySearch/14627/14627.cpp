#include <iostream>
#include <vector>

using namespace std;

int s, c;
vector<long long> arr;
long long ans = 0;

long long sum = 0;

void binarySearch(){

    long long left = 1;
    long long right = 1000000000;

    while(left <= right){
        long long mid = (left + right) /2 ;

        long long cur_cnt = 0;

        for (auto i : arr) {
            cur_cnt += i / mid;
        }

        if( cur_cnt >= c){
            left = mid + 1;
            ans = mid;
        } else{
            right = mid -1;
        }

    }




}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> c;

    arr.resize(c, 0);

    for(int i = 0; i < s; i++){

        long long l;
        cin >> l;
        arr[i] = l;
        sum += l;
 
    }



    binarySearch();
 

    long long result = sum - (ans * c);
    cout << result << "\n";

 
    return 0;



}