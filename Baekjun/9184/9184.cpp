#include <iostream>

using namespace std;



void w(int a_, int b_, int c_)
{
    if(a<= 0 || b<= 0 || c<= 0)
    {

        return 1;
    }


}

int main()
{
    bool runflag = true;
    while(runflag)
    {
        int a, b, c;

        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1)
        {
            runflag = false;

        }
        else
        {
            w(a, b, c);
            cout << a << b << c << endl;
        }
        

    }



    return 0;
}