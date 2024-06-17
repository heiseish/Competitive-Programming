#include <bits/stdc++.h>
using namespace std;

/****
      If auto - completions exists, output all of
      them in lexicographical order(lowercase) else
      output "No  suggestions" without quotes.

****/

const int ALPHABET_SIZE = 26;
using ll = long long;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    ll sz;
    bool isEndOfWord; // represent end of word
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    pNode->sz = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
        pCrawl->sz += 1;
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

ll search(struct TrieNode *root, string key)
{
    ll ans = 0;
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return ans;
        pCrawl = pCrawl->children[index];
        ans += pCrawl->sz;
    }
    return ans;
}

void dfs(struct TrieNode *curNode, string curString, vector<string> &res)
{
    for (int letter = 0; letter < ALPHABET_SIZE; letter++)
    {
        if (curNode->children[letter] != NULL)
        {
            string tmp = curString;
            tmp.push_back(letter + 'a');
            dfs(curNode->children[letter], tmp, res);
        }
    }

    if (curNode->isEndOfWord)
        res.push_back(curString);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    struct TrieNode *root = getNode();
    int n;
    ll ans = 0;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        ans += search(root, s);
        insert(root, s);
    }
    cout << ans << '\n';
    return 0;
}