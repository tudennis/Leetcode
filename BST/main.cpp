#include <iostream>
#include <cstdlib>

using namespace std;

struct BTNode {
    int m_value;
    BTNode * m_left;
    BTNode * m_right;
    
    BTNode(int v) : m_value(v), m_left(NULL), m_right(NULL) {};
};

BTNode * remove(BTNode * root, int target)
{
    if (root == NULL)
        return NULL;
    
    if (root->m_value < target)
    {
        root->m_right = remove(root->m_right, target);
    }
    else if (root->m_value > target) 
    {
        root->m_left = remove(root->m_left, target);
    }
    else
    {
        if (root->m_left != NULL && root->m_right != NULL)
        {
            BTNode * cur = root->m_right;
            while (cur != NULL)
            {
                cur = cur->m_left;
            }
            root->m_value = cur->m_value;
            root->m_right = remove(root->m_right, cur->m_value);
        }
        else
        {
            if (root->m_left != NULL)
                root = root->m_left;
            else
                root = root->m_right;
        }
    }
    return root;
}

int main(int argc, char** argv) {

    return 0;
}

