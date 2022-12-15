#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[50];
    char str2[50];
    cin.getline(str, 50);
    // cin.getline(str2, 50);
    // cout << str << endl;
    // cout << str2 << endl;

    // sort strings using bubble sort
    int i = 0;
    int j = 0;
    while (*(str + i) != '\0')
    {
        j = 0;
        while (*(str + j) != '\0')
        {
            if (*(str + i) < *(str + j))
            {
                char temp = *(str + i);
                *(str + i) = *(str + j);
                *(str + j) = temp;
            }
            j++;
        }
        i++;
    }


    cout << str << endl;




    return 0;
}
