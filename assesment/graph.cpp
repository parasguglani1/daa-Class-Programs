#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Usersgraph;

void getfriends(int person)
{
    cout << "Immediate friends of user " << person << ": ";
    for (int i = 0; i < Usersgraph[person].size(); i++)
    {
        cout << Usersgraph[person][i] << " ";
    }
    cout << endl;
}

int main()
{
    int NumOfUsers, NumOfEdges;

    cin >> NumOfUsers >> NumOfEdges;

    Usersgraph.resize(NumOfUsers);

    for (int i = 0; i < NumOfEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        Usersgraph[u].push_back(v);
        Usersgraph[v].push_back(u);
    }

    for (int i = 0; i < NumOfUsers; i++)
    {
        getfriends(i);
    }

    return 0;
}
