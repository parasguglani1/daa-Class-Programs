#include <iostream>
#include <vector>
using namespace std;
void find_immediate_friends(vector<vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << "User " << i << "'s friends: ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> graph = {{1, 2, 3, 4, 5}, {0, 2, 5, 6}, {0, 1, 6}, {0}, {0}, {0, 1}, {1, 2}};
    find_immediate_friends(graph);
    return 0;
}
