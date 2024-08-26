#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
    int kq = 0;
    queue<char> que;
    map<char, bool> mp;
    
    int t = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(mp[s[i]] == true)
        {
            while(mp[s[i]] == true)
            {
                t--;
                mp[que.front()] = false;
                que.pop();
            }
        }

        t++;
        kq = max(kq, t);
        mp[s[i]] = true;
        que.push(s[i]);
    }

    return kq;
}

int main() {
    string s;

    cin >> s;

    cout << lengthOfLongestSubstring(s);
}