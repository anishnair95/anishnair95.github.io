#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node*buildTree()
{
    int d;
    cin>>d;

    if(d==-1)
    {
        return NULL;
    }

    node*root=new node(d);
    root->left=buildTree();
    root->right=buildTree();

    return root;
}

void print(node*root)
{

    if(root==NULL)
    return ;

    cout<<root->data<<" ";
   print(root->left);
   print(root->right);

}

void printIn(node*root)
{
    if(root==NULL)
    return ;

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);

}
void printPost(node*root)
{
    if(root==NULL)
    return ;

    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";

}

int main() {
    node*root=buildTree();

    cout<<"Preorder Traversal:";
    print(root);

    cout<<endl<<"Inorder Traversal:";
    printIn(root);

    cout<<endl<<"Postorder Traversal:";
    printPost(root);
    return 0;

}
