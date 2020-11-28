#include<iostream>
#include<stdlib.h>
using namespace std;
int cont=0;
int isCorrect(int i, int j, int (*Q)[4])
{
	int s, t;
	for (s = i, t = 0; t < 4; t++)
		if (Q[s][t] == 1 && t != j) return 0;
	for (s = 0, t = j; s < 4; sq++)
	{
		if (Q[s][t] == 1 && s != i) return 0;
	}
	for (s = i - 1, t = j - 1; s >= 0 && t >= 0; s--, t--)
	{
		if (Q[s][t] == 1) return 0;
	}
	for (s = i + 1, t = j + 1; s < 4 && t < 4; s++, t++)
	{
		if (Q[s][t] == 1)  return 0;
	}q
	for (s = i - 1, t = j + 1; s >= 0 && t < 4; s--, t++)
	{
		if (Q[s][t] == 1)   return 0;
	}
	for (s = i + 1, t = j - 1; s < 4 && t >= 0; s++, t--)
	{
		if (Q[s][t] == 1)   return 0;
	}
	return 1;
}


void Queen(int j,int (*Q)[4])
{
    if(j==4)
    {
        for(int i=0;i<4;i++)
        {
            for(int k=0;k<4;k++)
                cout<<Q[i][k]<<" ";
            cout<<endl;
        }
        cout <<endl;
        cont++;
    }
    for(int i=0;i<4;i++)
    {
        if(isCorrect(i,j,Q))
        {
            Q[i][j]=1;
            Queen(j+1,Q);
            Q[i][j]=0;
        }
    }

}
int main()
{
    int Q[4][4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            Q[i][j]=0;
    }
    Queen(0,Q);
    cout << "Hello world!" << " "<<cont;
    return 0;
}
