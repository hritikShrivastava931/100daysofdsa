#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int freq[26] = {0};

    for(int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';

        freq[index]++;

        if(freq[index] == 2)
        {
            cout << s[i];
            return 0;
        }
    }

    cout << -1;

    return 0;
}