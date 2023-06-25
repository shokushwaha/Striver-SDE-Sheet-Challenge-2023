struct Node
{
    Node *links[26];
    bool flag = false;

    void put(char ch, Node *newNode)
    {
        links[ch - 'a'] = newNode;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};
class Trie
{

public:
    /** Initialize your data structure here. */
    Node *root;
    Trie() { root = new Node(); }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (auto c : word)
        {
            if (!node->containsKey(c))
                node->put(c, new Node());

            node = node->get(c);
        }

        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        for (auto c : word)
        {
            if (!node->containsKey(c))
                return false;

            node = node->get(c);
        }

        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (auto c : prefix)
        {
            if (!node->containsKey(c))
                return false;
            node = node->get(c);
        }

        return true;
    }
};