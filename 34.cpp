#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
const int n = 3;
int numbermove = 0;

char winner;
int x,y;
string role1,role2;

char paint(char table[][n+1])
{
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }
}

pair<int, int> bot1(char table[][n+1])
{
    pair<int, int> p;

        if (table[1][1] == 'O')
        {
            p.first = 1;
            p.second = 3;
         //   break;
        }
        if (table[1][3] == 'O')
        {
            p.first = 3;
            p.second = 3;
           // break;
        }
        if (table[3][3] == 'O')
        {
            p.first = 3;
            p.second = 1;
          //  break;
        }
        if (table[3][1] == 'O')
        {
            p.first = 1;
            p.second = 1;
         //   break;
        }
        if ((table[1][1] != 'O') &&  (table[3][1] != 'O') && (table[3][3] != 'O') && (table[1][3] != 'O'))
        {
            p.first = 3;
            p.second = 3;
        }


           if ((table[3][1] == 'X') && (table[1][3] != 'O')&& (numbermove >= 6))
            {
                p.first = 1;
                p.second = 3;
            }

            if ((table[1][1] == 'X') && (table[3][3] != 'O')&& (numbermove >= 6))
            {
                p.first = 3;
                p.second = 3;
            }

            if ((table[3][1] == 'X') && (table[3][1] != 'O') && (numbermove >= 6))
            {
                p.first = 3;
                p.second = 1;
            }

            if ((table[1][1] != 'O') && (table[1][3] == 'X')&& (numbermove >= 6))
            {
                p.first = 1;
                p.second = 1;
            }
 /*
            if ((table[3][1] == 'X') && (table[1][3] == 'O')&& (numbermove >= 6))
            {
                p.first = ;
                p.second = ;
            }
            if ((table[1][1] == 'X') && (table[3][3] == 'O')&& (numbermove >= 6))
            {
                p.first = ;
                p.second = ;
            }
            if ((table[1][3] == 'X') && (table[1][1] == 'O') && (numbermove >= 6))
            {
                p.first = ;
                p.second = ;
            }
            if ((table[1][1] == 'O') && (table[3][1] == 'X')&& (numbermove >= 6))
            {
                p.first = ;
                p.second = ;
            }*/



    return p;
}
bool check(char table[][n+1])
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



            if ((table[i][1] == 'O') && (table[i][2] == 'O') && (table[i][3] == 'O'))
            {
                winner = 'o';
                return false;
            }

            if ((table[1][i] == 'O') && (table[2][i] == 'O') && (table[3][i] == 'O'))
            {

                winner = 'o';
                return false;
            }

            if ((table[1][1] == 'O') && (table[2][2] == 'O') && (table[3][3] == 'O'))
            {

                winner = 'o';
                return false;
            }
            if ((table[1][3] == 'O') && (table[2][2] == 'O') && (table[3][1] == 'O'))
            {

                winner = 'o';
                return false;
            }
    }
    return true;
}
int main()
{
    pair<int, int> f;
    char table[n+1][n+1];
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            table[i][j] = ' ';
        }
    }

    cout << "HOW U WONT PLAY?";
    cin >> role1 >> role2;
    if (role1 == "people" && role2 == "people")
    {
          while(check(table))
        {
            paint(table);
            if (numbermove % 2 == 0)
            {
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
                table[x][y] = 'O';

            }
            numbermove += 1;
            system ("cls");
            if (check(table) == false)
            {
                cout << winner;
                break;
            }
            if ((numbermove == n*n) && (check(table) != false))
            {
                cout << "tie";
                break;
            }
        }
    }



    if (role1 == "bot" && role2 == "people")
    {
     int x,y;
     int numbermove = 0;
        while(check(table))
        {
            paint(table);
           // sleep(5);
            if (numbermove == 0)
            {
                table[2][2] = 'X';
            }

            if (numbermove % 2 == 1)
            {

                cout << "PEOPLE MOVE ";
                cin >> x >> y;

                if (table[x][y] != ' ')
                {
                    cout << "BAD X AND Y.Try again" << endl << "PEOPLE MOVE ";
                    cin >> x >> y;
                }
                table[x][y] = 'O';
            }
            if (numbermove % 2 == 0 && numbermove > 0)
            {
                f = bot1(table);
                table[f.first][f.second] = 'X';
            }
            numbermove += 1;
           // sleep(5);
            system ("cls");

        }

    }
   // paint();
   // cout << winner;
}

