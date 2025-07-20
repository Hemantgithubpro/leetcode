#include <bits/stdc++.h>
using namespace std;

struct trienode
{
    string folder;
    bool remove = false;
    map<string, trienode *> child;
    trienode(string folder)
    {
        this->folder = folder;
    }
};
void trieinsert(trienode *root, vector<string> &path)
{
    for (auto &s : path)
    {
        if (!root->child.count(s))
            root->child[s] = new trienode(s);
        root = root->child[s];
    }
}
string markrepeating(trienode *root, unordered_map<string, trienode *> &visited)
{
    string subfolder;
    for (auto &[childfolder, childnode] : root->child)
        subfolder += markrepeating(childnode, visited);

    if (subfolder.size())
    {
        if (visited.count(subfolder))
        {
            visited[subfolder]->remove = true;
            root->remove = true;
        }
        else
            visited[subfolder] = root;
    }
    return "[" + root->folder + subfolder + "]";
}
void savepath(trienode *root, vector<string> &currpath, vector<vector<string>> &res)
{
    if (root->remove)
        return;

    currpath.push_back(root->folder);
    res.push_back(currpath);
    for (auto &[subfolder, childnode] : root->child)
        savepath(childnode, currpath, res);

    currpath.pop_back();
}

vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
{
    // insert all paths in trie
    trienode *root = new trienode("/");
    for (auto &path : paths)
        trieinsert(root, path);

    // mark all repeating paths
    unordered_map<string, trienode *> visited;
    markrepeating(root, visited);

    // save all path after deletion
    vector<vector<string>> res;
    vector<string> currpath;
    for (auto &[subfolder, childnode] : root->child)
        savepath(childnode, currpath, res);

    return res;
}

int main()
{
}