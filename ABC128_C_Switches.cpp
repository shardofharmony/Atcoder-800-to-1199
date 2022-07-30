/* As soon as I saw the problem I thought of using a solution similar to bitmask
I can represent all the switches in the form of mask, like 2 i.e 10 means 2nd switch is on while the rest
is off.

Iterate from 0 to 2^n-1

Using the inputs check whether the current mask is a correct solution or not
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> arr[m];
  int s, a;
  for (int i = 0; i < m; i++)
  {
    cin >> s;
    for (int j = 0; j < s; j++)
    {
      cin >> a;
      arr[i].push_back(a);
    }
  }
  int parity[m];
  for (int i = 0; i < m; i++)
    cin >> parity[i];
  int sth[n + 1];
  int ans = 0;
  for (int i = 0; i < pow(2, n); i++)
  {
    for (int j = 0; j <= n; j++)
      sth[j] = 0;
    int j = 1;
    int mask = i;

//while loop to set on or off state of switch
    while (mask > 0)
    {
      sth[j] = mask % 2;
      j++;
      mask /= 2;
    }
    int ret = 1;
    for (int j = 0; j < m; j++)
    { int p = 0;

      for (int k = 0; k < arr[j].size(); k++)
        p += sth[arr[j][k]];                         //sum the state of switches that are required for the current bulb
      if (p % 2 != parity[j])         //if parity is different this mask is not to be considered
      { ret = 0;
        break;
      }
    }
    if (ret)
      ans++;
  }
  cout << ans;

}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t = 1;
  //cin >> t;
  while (t--)
  {
    solve();
    cout << "\n";
  }

}