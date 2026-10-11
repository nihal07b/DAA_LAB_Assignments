#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

struct Compare
{
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string code)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main()
{
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++)
        cin >> chars[i];

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(new Node(chars[i], freq[i]));
    }

    while (pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}