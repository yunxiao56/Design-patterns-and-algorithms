#include <iostream>
#include "math.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"

using namespace std;


double Data(int n)
{
    double x,y;
    time_t t;
    int num=0;
    srand((unsigned)time(&t));
    for(int i;i<n;i++)
    {
        x=rand()%100/100.0;
        y=rand()%100/100.0;
        if(y<1-pow(x,2))
        {
            num++;
        }
    }
    return double(num)/double(n);
}

int main()
{
    int n;
    cout<<"Please input the number of n:";
    cin>>n;
    double result=Data(n);
    cout <<"The result is about" <<" "<<result;
    cout << "Hello world!" << endl;
    return 0;
}
