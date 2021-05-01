#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int64_t val;
    int64_t height;
};

int main()
{
    int64_t n;
    int64_t temp;
    cin >> n;
    int64_t root;
    int64_t final_height;

    vector<vector<int64_t>> vec(n);

    queue<node> q;

    for (int64_t i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == -1)
        {
            root = i;
        }
        else
        {
            vec[temp].push_back(i);
        }
    }

    node *tree_root = new node();
    node *temp_node;
    tree_root->val = root;
    tree_root->height = 1;
    q.push(*tree_root);
    while (!q.empty())
    {
        if (vec[q.front().val].size() != 0)
        {
            while (vec[q.front().val].size() > 0)
            {
                temp_node = new node();
                temp_node->val = vec[q.front().val].back();
                vec[q.front().val].pop_back();
                temp_node->height = q.front().height + 1;
                final_height = temp_node->height;
                q.push(*temp_node);
            }
        }
        q.pop();
    }
    cout << final_height;
}