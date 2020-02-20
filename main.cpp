#include <iostream>


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
struct binarytreeNode
{
    binarytreeNode* left;
    binarytreeNode* right;
    int data;
};

class binarytree {
public:
    binarytreeNode* head = nullptr;

    void add(int input, bool rec, binarytreeNode* recursed)
    {

        if (head == nullptr) {
            head = new binarytreeNode();
            head->data = input;
            return;
        }
        auto current = head;
        if (rec)
        {
            current = recursed;
        }
        if (input < current->data)
        {
            if (current->left == nullptr) {
                current->left = new binarytreeNode();
                current->left->data = input;
            }
            else {
                add(input, true, current->left);
            }

        }
        else if (input > current->data)
        {
            if (current->right == nullptr) {
                current->right = new binarytreeNode();
                current->right->data = input;
            }
            else {
                add(input, true, current->right);
            }

        }



    }

    void printBSTree(binarytreeNode* node) {

        if (node->left != nullptr)
        {
            printBSTree(node->left);
        }
        std::cout << node->data << std::endl;
        if (node->right != nullptr)
        {
            printBSTree(node->right);
        }

    }
};


int main() {
    binarytree* bt = new binarytree;
    char str[255];
    std::cin.getline(str, 255);
    int counter = 0;
    int NumSize = 0;
    std::vector<int> Numbers;
    std::string current = "";
    while (str[counter] != '\0') {
        if (str[counter] != ' ') {
            NumSize++; counter++;
        }
        else {
            for (int i = counter-NumSize; i < counter; i++) {
                current += str[i];
            }
            Numbers.push_back(std::stoi(current));
            current = "";
            NumSize = 0;
            counter++;
        }
    }
    for (int i = counter - NumSize; i < counter; i++) {
        current += str[i];
    }
    Numbers.push_back(std::stoi(current));
    current = "";
    std::set<int> uniqueValues(Numbers.begin(), Numbers.end());
    for (auto x : uniqueValues) {
        bt->add(x, false, nullptr);
    }
    bt->printBSTree(bt->head);
}