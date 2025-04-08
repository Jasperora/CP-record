/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    public:
        Node* connect(Node* root) {
            if(!root) return nullptr;
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                int n = q.size();
                Node* Right = q.front();
                for(int i = 0; i < n-1; ++i){
                    if(Right->right) q.push(Right->right);
                    if(Right->left) q.push(Right->left);
    
                    q.pop();
                    q.front()->next = Right;
                    Right = q.front();
                }
                if(Right->right) q.push(Right->right);
                if(Right->left) q.push(Right->left);
                q.pop();
            }
            return root;
        }
    };