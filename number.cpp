#include <bits/stdc++.h>

using namespace std;
int n[16];
int minimax(int x,int player)
{
    if (player == 1)
    {
        minimax(n[x/2],2);
    }
    if (player == 2)
    {
        minimax(n[x/2],1);
    }
    return minimax(n[1],1);
}
int main()
{

    for (int i = 8;i<=15;i++)
    {
        cin >> n[i];
    }

    cout << minimax(15,1);

}
