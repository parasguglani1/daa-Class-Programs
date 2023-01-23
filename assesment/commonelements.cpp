#include <bits/stdc++.h>
using namespace std;

void commonElements(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (ar1[i] == ar2[j] && ar2[j] == ar3[k])
        {
            cout << ar1[i] << " ";
            i++;
            j++;
            k++;
        }
        else if (ar1[i] < ar2[j])
            i++;
        else if (ar2[j] < ar3[k])
            j++;
        else
            k++;
    }
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int java[n1], dbms[n2], daa[n3];
    for (int i = 0; i < n1; i++)
        cin >> java[i];
    for (int i = 0; i < n2; i++)
        cin >> dbms[i];
    for (int i = 0; i < n3; i++)
        cin >> daa[i];

    cout << "students in all three courses are: ";
    commonElements(java, dbms, daa, n1, n2, n3);
    return 0;
}
