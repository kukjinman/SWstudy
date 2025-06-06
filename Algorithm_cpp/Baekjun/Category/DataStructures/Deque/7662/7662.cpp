#include <iostream>
#include <queue>
#include <map>
using namespace std;

int T;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    queue<string> ans;

    for(int i = 0; i < T; i++){

        int n;
        cin >> n;

        priority_queue<int> pq;        
        priority_queue<int, vector<int>, greater<int>> min_pq; 
        map<int,int> m;

        for(int j = 0; j < n; j++){
            char cmd;
            int cur_num;
            cin >> cmd >> cur_num;

            if(cmd == 'I') {
                pq.push(cur_num);
                min_pq.push(cur_num);
                m[cur_num]++;
            }
            else if( cmd == 'D'){
    
                if(pq.empty() && min_pq.empty()) {
                    continue;
                }
    
                if(cur_num == 1){

                    if(!pq.empty()) {
                        m[pq.top()]--; // decrease the count of the top element
                        pq.pop(); // pop the top element
                    }

                    while(!pq.empty() && m[pq.top()] == 0) {
                        pq.pop(); // pop until we find a valid number
                    }

                    while(!min_pq.empty() && m[min_pq.top()] == 0) {
                        min_pq.pop(); // pop until we find a valid number
                    }


                }
                else{

                    if(!min_pq.empty()) {
                        m[min_pq.top()]--; // decrease the count of the top element
                        min_pq.pop(); // pop the top element
                    }

                    while(!pq.empty() && m[pq.top()] == 0) {
                        pq.pop(); // pop until we find a valid number
                    }

                    while(!min_pq.empty() && m[min_pq.top()] == 0) {
                        min_pq.pop(); // pop until we find a valid number
                    }
                }
            }
        }


        if(pq.empty() && min_pq.empty()) {
            ans.push("EMPTY");
        }
        else{
            int max_num = pq.top();
            int min_num = min_pq.top();
            ans.push(to_string(max_num) + " " + to_string(min_num));
        }
    }

    while(!ans.empty()){
        cout << ans.front() << "\n";
        ans.pop();
    }



}