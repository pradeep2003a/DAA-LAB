#include <bits/stdc++.h>

using namespace std;

struct node 
{
    int data;
    node *left, *right;
};
typedef node *NODE;
class BST
{
    public:
        NODE root;
        BST() {
            root = NULL;
        }
        void insert();
        void delet();
        void search(int);
        void inorder(NODE);
        void preorder(NODE);
        void postorder(NODE);
};

void BST::insert(){
    NODE temp,cur,prev;
    int item;
    cout << "Enter element to insert: ";
    cin >> item;
    temp = new node;
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
    {
        // If tree is empty the first entered element becomes root 
        root = temp;
        return;
    }
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        // Iterating towards leaf nodes by comparing the element entered
        prev = cur;
        if (item == cur->data)
        {
            cout << "Duplicate items are not allowed" <<endl;
            delete(temp);
            return;
        }
        cur = (item < cur->data) ? cur->left : cur->right;
    }
    // Placing the entered element to the leaf node
    (item < prev->data) ? prev->left = temp : prev->right = temp;
}

void BST::delet() {
    NODE cur,prev,next,temp;
    int item;

    cout << "Enter item to be deleted: ";
    cin >> item;

    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        if (item == cur->data)
            break;
        prev = cur;
        cur = (item < cur->data) ? cur->left : cur->right;   // Traverse through the tree and find key
    }   
    if (cur == NULL)    {
        cout << "Item not found in the tree." << endl;
        return;
    }
    
    if (cur->left == NULL)
    {
        // If left pointer of current element is null move right pointer to temp 
        temp = cur->right;
    }
    else if (cur->right == NULL)
    {
        // If right pointer of current element is null move left pointer to temp 
        temp = cur->left;
    }
    else
    {
        // If both left and right pointers are present move the right pointer to next
        NODE next = cur->right;
        // Traverse towards the leaf node of the moved right pointer
        while(next->left != NULL)
            next = next->left;
        // Connect the left pointer of current to the left of next
        next->left = cur->left;
        temp = cur->right;
    }

    if (prev == NULL)
    {
        root = temp;
    }
    else if (prev->left == cur)
    {
        prev->left = temp;
    }
    else
    {
        prev->right = temp;
    }
    
    delete(cur);
}

void BST::inorder(NODE root) {
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << "->";
        inorder(root->right);
    }
}

void BST::preorder(NODE root) {
    if (root != NULL)
    {
        cout << root->data << "->";
        preorder(root->left);
        preorder(root->right);
    }
}

void BST::postorder(NODE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "->";
    }
}

void BST::search(int key){
    if (root == NULL)
    {
        cout << "Tree is empty and key is not found." << endl;
        return;
    }
    NODE cur = root;
    while(cur != NULL && cur->data != key)
        cur = (key < cur->data) ? cur->left : cur->right;
    
    if (cur == NULL)
    {
        cout << "Key item not found" << endl;
        return;
    }
    cout << "Key item found in the tree" << endl;
}

int main() {
    BST bst;
    int ch,key;
    while (1)
    {
        cout << "\n1.Insert 2.Delete\n3.Inorder, Preorder & PostOrder\n4.Search 5.Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            bst.insert();
            break;
        case 2:
            bst.delet();
            break;
        case 3:
            cout << "Inorder Traversal :"<<endl;
            bst.inorder(bst.root);
            cout<<endl;
            cout << "Preorder Traversal :"<<endl;
            bst.preorder(bst.root);
            cout<<endl;
            cout << "Postorder Traversal :"<<endl;
            bst.postorder(bst.root);
            cout<<endl;
            break;
        case 4:
            cout << "\nEnter element to be searched: ";
            cin >> key;
            bst.search(key);
            break;
        case 5:
            exit(0);
        default:
            cout << "Enter correct choice.";
            break;
        }
    }
    return 0;
}