
/* Solution 1 : As soon as I was the questions I thought of using recursion to solve
problem, but as expected I got TLE*/


//Recursion solution

string arr[4] = {"dream", "dreamer", "erase", "eraser"};

bool fn(string s, string t, int i)
{
  if (t.length() > s.length())
    return false;
  if (t.length() == s.length())
    return s == t;
  bool b1, b2;
  if (s[i] == 'd')
  {
    b1 = fn(s, t + arr[0], i + arr[0].length());
    b2 = fn(s, t + arr[1], i + arr[1].length());
  }
  else
    return false;
  return b1 | b2;
}
void solve()
{
  string s;
  cin >> s;
  string t = "";
  if (fn(s, t, 0))
    cout << "Yes";
  else
    cout << "No";
}



/* Try 2 :

30/07

Not yet able to come up with any solution, should I try to make the recursion
faster.
Should I just check when I am trying to insert the 4 different strings into the new
string.
For example : If I encounter 'd' as the current character, will check if the next
character after 'dream' or 'dreamer' is :
for 'dream' next character could be 'e' as in 'dreameraser' or 'dreamererase' or 'dreamereraser'
for 'dreamer' next characters could be 'a' as in 'dreameraser'

The implementation of this will be very hard I think.

Fast recursion? : something like DP?

one thing I miscalculate was that there is no choice in erase and eraser like dream
and dreamer

If current character is 'd' and I consider, 'dream'
then, 'dreameraser' 'dreamerase' is the only thing i need to be concerned with
if i chose 'dreamer'
then, 'dreamereraser' and 'dreamererase'

if current character is e then check for 'erase' or 'eraser'

*/

//Second attempt solution : 11 ACs 9 WAs


string arr[4] = {"dream", "dreamer", "erase", "eraser"};
bool fn(string s)
{
  int i = 0;
  for (i; i < s.length();)
  {
    if (s[i] == 'd')
    {
      string a = s.substr(i, arr[0].length());
      string b = s.substr(i, arr[1].length());
      if (a == "dream")
      {
        if (b == "dreamer")
        {
          if (s[i + arr[1].length()] == 'a')
            i = i + arr[0].length();
          else if (s[i + arr[1].length()] == 'e')
            i = i + arr[1].length();
          else
            return false;

        }
        else
          i = i + arr[0].length();
      }
      else
        return false;
    }
    else if (s[i] == 'e')
    {
      string a = s.substr(i, arr[2].length());
      string b = s.substr(i, arr[3].length());
      if (a == "erase")
      {
        if (b == "eraser")
          i = i + arr[3].length();
        else
          i = i + arr[2].length();
      }
      else
        return false;
    }
    else
      return false;
  }
  return i == s.length();
}

