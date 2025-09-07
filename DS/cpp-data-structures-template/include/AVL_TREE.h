#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <algorithm>

template <typename T>
class AVL_TREE
{
    struct AVLNode
    {
        T Data;
        AVLNode *Left, *Right;
        int Height;

        AVLNode(T val) : Data(val), Left(nullptr), Right(nullptr), Height(1) {}
    };

    AVLNode* root;

public:
    AVL_TREE()
    {
        root = nullptr;
    }

    ~AVL_TREE()
    {
        clear(root);
    }

    bool search(T val)
    {
        AVLNode* current = root;
        while (current != nullptr)
        {
            if (val == current->Data)
                return true;
            current = (val < current->Data) ? current->Left : current->Right;
        }
        return false;
    }

    void remove(T data)
    {
        root = remove(root, data);
    }

    void insert(T data)
    {
        root = insert(root, data);
    }

    void printInOrder() {
        inOrder(root);
        std::cout << std::endl;
    }

protected:

private:

    AVLNode* remove(AVLNode* root, T data)
    {
        if (root == nullptr) return nullptr;

        if (data < root->Data)
        {
            root->Left = remove(root->Left, data);
        }
        else if (data > root->Data)
        {
            root->Right = remove(root->Right, data);
        }
        else
        {
            if (root->Left == nullptr && root->Right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if (root->Left == nullptr)
            {
                AVLNode* temp = root->Right;
                delete root;
                return temp;
            }
            else if (root->Right == nullptr)
            {
                AVLNode* temp = root->Left;
                delete root;
                return temp;
            }
            else
            {
                AVLNode* successor = findMin(root->Right);
                root->Data = successor->Data;
                root->Right = remove(root->Right, successor->Data);
            }
        }

        return balance(root);
    }

    AVLNode* insert(AVLNode* node, T val)
    {
        if (node == nullptr)
            return new AVLNode(val);

        if (val < node->Data)
            node->Left = insert(node->Left, val);
        else if (val > node->Data)
            node->Right = insert(node->Right, val);
        else
            return node;

        updateHeight(node);
        return balance(node);
    }

    AVLNode* findMin(AVLNode* node)
    {
        while (node->Left != nullptr)
        {
            node = node->Left;
        }
        return node;
    }

    void clear(AVLNode* node)
    {
        if (node == nullptr) return;
        clear(node->Left);
        clear(node->Right);
        delete node;
    }

    int height(AVLNode* node)
    {
        return (node == nullptr) ? 0 : node->Height;
    }

    int balanceFactor(AVLNode* node)
    {
        if (node == nullptr) return 0;
        return height(node->Left) - height(node->Right);
    }

    void updateHeight(AVLNode* node)
    {
        node->Height = 1 + std::max(height(node->Left), height(node->Right));
    }

    AVLNode* rightRotate(AVLNode* y)
    {
        AVLNode* x = y->Left;
        AVLNode* T2 = x->Right;

        x->Right = y;
        y->Left = T2;

        updateHeight(y);
        updateHeight(x);
        return x;
    }

    AVLNode* leftRotate(AVLNode* x)
    {
        AVLNode* y = x->Right;
        AVLNode* T2 = y->Left;

        y->Left = x;
        x->Right = T2;

        updateHeight(x);
        updateHeight(y);
        return y;
    }

    AVLNode* leftRightRotate(AVLNode* A)
    {
        A->Left = leftRotate(A->Left);
        return rightRotate(A);
    }

    AVLNode* rightLeftRotate(AVLNode* A)
    {
        A->Right = rightRotate(A->Right);
        return leftRotate(A);
    }

    AVLNode* balance(AVLNode* node)
    {
        if (node == nullptr) return nullptr;

        updateHeight(node);
        int bf = balanceFactor(node);

        if (bf > 1)
        {
            if (balanceFactor(node->Left) >= 0)
            {
                return rightRotate(node);
            }
            else
            {
                return leftRightRotate(node);
            }
        }
        else if (bf < -1)
        {
            if (balanceFactor(node->Right) <= 0)
            {
                return leftRotate(node);
            }
            else
            {
                return rightLeftRotate(node);
            }
        }

        return node;
    }

    void inOrder(AVLNode* node) {
        if (node == nullptr) return;
        inOrder(node->Left);
        std::cout << node->Data << "(" << node->Height << ") ";
        inOrder(node->Right);
    }
};

#endif // AVL_TREE_H