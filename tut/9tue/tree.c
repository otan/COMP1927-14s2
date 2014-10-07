typedef struct BSTNode *BSTree;
 
BSTree newBSTree(); // create an empty BSTree
void dropBSTree(BSTree); // free memory associated with BSTree
void showBSTree(BSTree); // display a BSTree
void showBSTreeNode(BSTree); // display BSTree root node
 
void BSTreeInfix(BSTree root) { // print values in infix order
    if (root == NULL) {
        return;
    }
    BSTreeInfix(root->left);
    printf("%d\n", root->value);
    BSTreeInfix(root->right);
}

void BSTreePrefix(BSTree root) { // print values in prefix order
    if (root == NULL) {
        return;
    }
    printf("%d\n", root->value);
    BSTreeInfix(root->left);
    BSTreeInfix(root->right);
}

void BSTreePostfix(BSTree root) { // print values in postfix order
    if (root == NULL) {
        return;
    }
    BSTreeInfix(root->left);
    BSTreeInfix(root->right);   
    printf("%d\n", root->value);
}

void BSTreeLevelOrder(BSTree root) { // print values in level-order
    
}
 
int BSTreeNumNodes(BSTree root) { // count #nodes in BSTree
    if (root == NULL) {
        return 0;
    }
    return 1 + BSTreeNumNodes(root->left) + BSTreeNumNodes(root->right);
}

int BSTreeSumNodes(BSTree root) {
    if (root == NULL) {
        return 0;
    }
    return root->value + BSTreeSumNodes(root->left) + BSTreeSumNodes(root->right);
}

int BSTreeNumLeaves(BSTree); // count #leaves in BSTree

int BSTreeHeightR(BSTree root) { 
    if (root == NULL) {
        return 0;
    }
    return 1 + max(BSTreeHeightR(root->left), BSTreeHeightR(root->right));
}

int BSTreeHeight(BSTree root) {
    return BSTreeHeightR(root) - 1;
}

int BSTreeWidth(BSTree root) {
    return 3 * BSTreeNumNodes(root);
}


BSTree BSTreeInsert(BSTree root, int val)  { // insert a new value into a BSTree
    if (root == NULL) {
        return newNode(val);
    }
    if (root->value == val) {
    } else if (root->value < val) {
        root->left = BSTreeInsert(root->left, val);
    } else {
        root->right = BSTreeInsert(root->right, val);
    }
    return root;
/*
 * BSTreeInsert(t,6);
 * BSTreeInsert(t,2);
 * BSTreeInsert(t,10);
 * BSTreeInsert(t,8);
 * BSTreeInsert(t,12);
 * BSTreeInsert(t,4);
 * BSTreeInsert(t,1);
 * BSTreeDelete(t,12);
 * BSTreeDelete(t,6);
 * BSTreeDelete(t,2);
 * BSTreeDelete(t,4);
 */
}

int BSTreeFind(BSTree, int); // check whether a value is in a BSTree
BSTree BSTreeDelete(BSTree, int) { // delete a value from a BSTree
    if (root == NULL) {
        return NULL;
    }
    if (root->value < val) {
        root->left = BSTreeDelete(root->left, val);
    } else if (root->value > val) {
        root->right = BSTreeDelete(root->right, val);
    } else {
        BSTree curr = root->left;
        BSTree prev = root;
        if (curr == NULL) {
            return root->right;
        }
        while (curr->right != NULL) {
            prev = curr;
            curr = curr->right;
        }
        prev->right = curr->left;
        curr->left = root->left;
        curr->right = root->right;
        return curr;
    }
    return root;
}
