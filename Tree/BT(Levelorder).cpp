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
int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int ls=height(root->left);
    int rs=height(root->right);

    return max(ls,rs)+1;
}
void printKthLevel(node* root,int k)
{
    if(root==NULL)
    return;

    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    
}
void printAllLevel(node*root)
{
  int H=height(root);

  for(int i=1;i<=H;i++)
  {
      printKthLevel(root,i);
      cout<<endl;
  }
}
int main() {
    node*root=buildTree();

    /*cout<<"Preorder Traversal:";
    print(root);

    cout<<endl<<"Inorder Traversal:";
    printIn(root);

    cout<<endl<<"Postorder Traversal:";
    printPost(root);
    cout<<endl;*/

    cout<<"Height: "<<height(root)<<endl;
    cout<<"3rd level: ";
    printKthLevel(root,3);
    cout<<endl;
    cout<<"Level Order Traversal:"<<endl;

   printAllLevel(root);

    return 0;

}
