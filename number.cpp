#include <bits/stdc++.h>

using namespace std;
int n[16];
int minimax(int x,int player)
{
    int rez = 0;
    if (x >= 8)
    {
        return n[x];
    }
    if (player == 1 )
    {
        rez = min(minimax(x*2,2),minimax(x*2+1,2));
    }
    if (player == 2)
    {
        rez = max(minimax(x*2,1),minimax(x*2+1,1));
    }
    return rez;
}
int main()
{

    for (int i = 8;i<=15;i++)
    {
        cin >> n[i];
    }

    cout << minimax(1,1);

}
