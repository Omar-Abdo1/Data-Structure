#ifndef ITIBST_H
#define ITIBST_H

template <typename T>
class ITIBST
{
    struct Node {
        T Data;
        Node *Left, *Right;
        Node(T Data) {
            this->Data = Data;
            Left = Right = nullptr;
        }
    };

    Node *root;

public:
    ITIBST() {
        root = nullptr;
    }

    ~ITIBST() {
        clear(root);
    }

    void insert(T data) {
        Node *node = new Node(data);
        if (root == nullptr) {
            root = node;
        } else {
            Node *current = root, *parent;
            while (current != nullptr) {
                parent = current;
                if (data > current->Data)
                    current = current->Right;
                else
                    current = current->Left;
            }
            if (data > parent->Data)
                parent->Right = node;
            else
                parent->Left = node;
        }
    }

    void remove(T data) {
        root = remove(root, data);
    }

    bool search(T data) {
        return getNodeByData(data) ? true : false;
    }

    void inOrder() {
        inOrder(root);
        std::cout << "\n";
    }

    void preOrder() {
        preOrder(root);
        std::cout << "\n";
    }

    void postOrder() {
        postOrder(root);
        std::cout << "\n";
    }

    void bfs() {
        bfs(root);
        std::cout << "\n";
    }

    int height() {
        return height(root);
    }

    bool isBalanced() {
        return checkHeight(root) != -1;
    }

protected:

private:
    Node* remove(Node *root, T data) {
        if (root == nullptr) return root;

        if (data < root->Data) {
            root->Left = remove(root->Left, data);
        } else if (data > root->Data) {
            root->Right = remove(root->Right, data);
        } else {
            if (root->Left == nullptr && root->Right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->Left == nullptr) {
                Node *temp = root;
                root = root->Right;
                delete temp;
            } else if (root->Right == nullptr) {
                Node *temp = root;
                root = root->Left;
                delete temp;
            } else {
                Node* successor = findMin(root->Right);
                root->Data = successor->Data;
                root->Right = remove(root->Right, successor->Data);
            }
        }
        return root;
    }

    void clear(Node* node) {
        if (node == nullptr) return;
        clear(node->Left);
        clear(node->Right);
        delete node;
    }

    Node* getNodeByData(T data) {
        Node *current = root;
        while (current != nullptr) {
            if (data == current->Data) return current;
            if (data > current->Data)
                current = current->Right;
            else
                current = current->Left;
        }
        return nullptr;
    }

    void inOrder(Node *cur) {
        if (cur == nullptr) return;
        inOrder(cur->Left);
        std::cout << cur->Data << " ";
        inOrder(cur->Right);
    }

    void preOrder(Node *cur) {
        if (cur == nullptr) return;
        std::cout << cur->Data << " ";
        preOrder(cur->Left);
        preOrder(cur->Right);
    }

    void postOrder(Node *cur) {
        if (cur == nullptr) return;
        postOrder(cur->Left);
        postOrder(cur->Right);
        std::cout << cur->Data << " ";
    }

    void bfs(Node *cur) {
        std::queue<Node*> qu;
        qu.push(cur);
        while (!qu.empty()) {
            int sz = qu.size();
            while (sz--) {
                auto now = qu.front();
                qu.pop();
                std::cout << now->Data << " ";
                if (now->Left) qu.push(now->Left);
                if (now->Right) qu.push(now->Right);
            }
            std::cout << "\n";
        }
    }

    Node* findMin(Node* node) {
        while (node->Left != nullptr) {
            node = node->Left;
        }
        return node;
    }

    int height(Node *cur) {
        if (cur == nullptr) return 0;
        return 1 + std::max(height(cur->Left), height(cur->Right));
    }

    int checkHeight(Node* node) {
        if (node == nullptr) return 0;

        int leftHeight = checkHeight(node->Left);
        if (leftHeight == -1) return -1;

        int rightHeight = checkHeight(node->Right);
        if (rightHeight == -1) return -1;

        if (std::abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + std::max(leftHeight, rightHeight);
    }
};

#endif // ITIBST_H