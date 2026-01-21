#include <bits/stdc++.h>

using namespace std;

int main()
{
int N;
cin >> N;
string A, B, diff;
cin >> A >> B;
for (int i; i<N; i++)
{
    if (A[i] == B[i])
    {
        diff.append("0"); // 0 means the same
    } else
    {
        diff.append("1"); // 1 means different
    }
}
cout << diff;
}