#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    
    // constuctor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

// everytime we build a tree it will make two new node but will be NULL

node* buildTree(node* root)
{
    // building tree in a recursive way
    cout<<"Enter data for node: "<<endl;
    int data;
    cin>>data;

    // root node created with data taken as user input
    root = new node(data);

    if(data == -1)
        return NULL;
    
    cout<<"Enter left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root; 
}

void levelOrderTraversal(node* root) // BFS
{
    // print the tree in level order
    queue<node*> q;
    q.push(root); 
    // after pushing the root node we know we are at the level below it therefore we will put a seprator there
    q.push(NULL);
    // main is when to put "enter"


    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            // if this happens the older level is traversed completely
            // means all child are pushed in queue;
            cout<<endl;
            if(!q.empty()) //if queue still has some child nodes
                q.push(NULL);
        } // to seprate the levels (enter)
        else
        {
            // i will only print the data of the node, when there is the data not when it is null 
            cout<<temp->data<<" ";
            if(temp -> left)
            {
                q.push(temp->left);
            }
            if(temp -> right)
            {
                q.push(temp->right);
            }
        }
    }
}

// HW
// reverse level order traversal
// iterative way of inorder postorder and preorder 

 

// inorder

void inorder(node* root) // LNR
{
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root) // NLR
{
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) // LRN
{
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


// build from level order
void buildFromLevelOrder(node* &root)
{
    queue<node*> q;
    cout<<"Enter data for root node: "<<endl;
    int data;
    cin >>data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"Enter data for left child of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter data for right child of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
        
    }
}

int main()
{
    node* root = NULL;
    
    // // creating a tree
    // root = buildTree(root); 
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // //level order
    // cout<< "\nPriniting tree in level order: "<<endl;
    // levelOrderTraversal(root);

    // // inorder  
    // cout<< "\nPriniting tree in inorder: "<<endl;
    // inorder(root);

    // // preorder
    // cout<< "\nPriniting tree in preorder: "<<endl;
    // preorder(root);

    // cout<< "\nPriniting tree in postorder: "<<endl;
    // postorder(root);

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    return 0;
}