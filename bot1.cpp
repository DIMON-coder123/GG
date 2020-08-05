#include <bits/stdc++.h>

using namespace std;
const int n = 3;
char winner;
char table[n+1][n+1];
bool check()
{

    for (int i = 1;i <= n;i++)
    {
            if ((table[i][1] == 'X') && (table[i][2] == 'X') && (table[i][3] == 'X'))
            {
                winner = 'x';
                return false;

            }

            if ((table[1][i] == 'X') && (table[2][i] == 'X') && (table[3][i] == 'X'))
            {
                winner = 'x';
                return false;

            }

            if ((table[1][1] == 'X') && (table[2][2] == 'X') && (table[3][3] == 'X'))
            {
                winner = 'x';
                return false;

            }
            if ((table[1][3] == 'X') && (table[2][2] == 'X') && (table[3][1] == 'X'))
            {
                winner = 'x';
                return false;

            }



            if ((table[i][1] == 'Y') && (table[i][2] == 'Y') && (table[i][3] == 'Y'))
            {

                winner = 'y';
                return false;
            }

            if ((table[1][i] == 'Y') && (table[2][i] == 'Y') && (table[3][i] == 'Y'))
            {

                winner = 'y';
                return false;
            }

            if ((table[1][1] == 'Y') && (table[2][2] == 'Y') && (table[3][3] == 'Y'))
            {

                winner = 'y';
                return false;
            }
            if ((table[1][3] == 'Y') && (table[2][2] == 'Y') && (table[3][1] == 'Y'))
            {

                winner = 'y';
                return false;
            }
            else
            {
                return true;
            }
    }
}
int main()
{
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            table[i][j] = ' ';
        }
    }

    int numbermove = 0;

    while(true)
    {
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                cout << table[i][j] << ' ';
            }
            cout << endl;
        }

        if (numbermove % 2 == 0)
        {
            int x,y;
            cout << "X MOVE ";
            cin >> x >> y;
            if (table[x][y] != ' ')
            {
                cout << "BAD X AND Y.Try again" << endl << "X MOVE ";
                cin >> x >> y;
            }
            table[x][y] = 'X';

        }
        if (numbermove % 2 == 1)
        {
            int x,y;
            cout << "Y MOVE ";
            cin >> x >> y;
            if (table[x][y] != ' ')
            {
                cout << "BAD X AND Y.Try again" << endl << "Y MOVE ";
                cin >> x >> y;
            }
            table[x][y] = 'Y';

        }
        numbermove += 1;
        system ("cls");
        if (check() == false)
        {
            cout << winner;
            break;
        }
        if ((numbermove == n*n) && (check() != false))
        {
            cout << "tie";
            break;
        }

    }
}
