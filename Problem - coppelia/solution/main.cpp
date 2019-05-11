#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
    int sol=0;

    int x,y,z;
    cin >> x >> y >> z;
    sol = max(sol,2*x+5*y+7*z);
    cin >> x >> y >> z;
    sol = max(sol,2*x+5*y+7*z);
    cin >> x >> y >> z;
    sol = max(sol,2*x+5*y+7*z);
    cin >> x >> y >> z;
    sol = max(sol,2*x+5*y+7*z);
    cout << sol << "\n";

    return 0;
}
/**
3
1 5 60
1 8 30
1 6 120
4
6 9
5 6
6 6
5 8
*****
0.000
42.000
168.000
70.000
0.000
140.000
0.000
0.000
210.000
60.000
30.000
120.000
*/
