#include <bits/stdc++.h>
using namespace std;

int main() {
vector<int> v;
int i;
for(i=0;i<100000;i++)
{
v.push_back(i);
}
for(i=0;i<v.size();i++)
{
cout<<v[i]<<endl;
}
return 0;
}
