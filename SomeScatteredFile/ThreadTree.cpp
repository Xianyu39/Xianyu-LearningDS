#include <iostream>
using namespace std;

struct  Node
{
    char data;

    short Ltag;
    Node *Lchild;
    short Rtag;
    Node *Rchild;

    Node(char Data, short Ltag = 0, Node *Lchild = nullptr, short Rtag = 0, Node *Rchild = nullptr)
        : data(Data), Ltag(Ltag), Lchild(Lchild), Rtag(Rtag), Rchild(Rchild) { }
};

class ThreadTree{
private:
    Node *root;

public:
    ThreadTree() : root(nullptr) { }

    // Pre order
    void Initialize(const string& str, Node*& root){
        static size_t ix{0};
        if(str[ix]=='#'){
            root = nullptr;
            ++ix;
        }else{
            root = new Node(str[ix]);
            ++ix;
            // cout << root->data;
            Initialize(str, root->Lchild);
            Initialize(str, root->Rchild);
        }
    }
    void Destroy(Node *&root){
        if(root){
            if(root->Lchild){
                Destroy(root->Lchild);
            }     
            if(root->Rchild){
                Destroy(root->Rchild);
            }
            // cout << "delete " << root->data << endl;
            delete root;
        }
    }
    ThreadTree(const string& str){
        Initialize(str, root);
    }
    ~ThreadTree(){
        Destroy(root);
    }
    void Threaded(){
        Traverse(this->root);
    }

    void Traverse(Node* root){
        static Node *pre{nullptr};
        if(root){
            if(root->Lchild){
                Traverse(root->Lchild);
            }
            cout << root->data << endl;
            if(pre && !root->Lchild){
                root->Lchild = pre;
                root->Ltag = 1;
            }
            if(pre && !root->Rchild){
                pre->Rchild = root;
                pre->Rtag = 1;
            }
            pre = root;

            if(root->Rchild){
                Traverse(root->Rchild);
            }
        }
    }
};

int main(){
    ThreadTree tr("AB#D##C##");
    tr.Threaded();
    return 0;
}
