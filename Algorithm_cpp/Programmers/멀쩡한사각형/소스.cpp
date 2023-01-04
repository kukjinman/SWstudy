#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    long c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
long long solution(int w, int h) {
    long long W = w;    
    long long H = h;

    return (W * H) - ((W + H) - gcd(W, H));
}

int main() {

    cout << solution(8, 12) << endl;

    return 0;
}


//이런문제는 나오면 못품.알고만있을것

//#include<cmath>
//#include<iostream>
//
//using namespace std;
//
//long long solution(int w, int h) {
//    long long answer = 1;
//    int space = w * h;
//
//    if (w > h)
//    {
//        long long tmp = ceil(double(w) / double(h)) * h;
//        answer = space - tmp;
//
//    }
//    else if (h > w)
//    {
//        long long tmp = ceil(double(h) / double(w)) * w;
//        answer = space - tmp;
//    }
//    else
//    {
//        answer = space - h;
//    }
//
//    return answer;
//}
        