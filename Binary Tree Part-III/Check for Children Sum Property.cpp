void increment(BinaryTreeNode < int > * root, int diff) {
    if (root -> right != NULL) {
        root -> right -> data += diff;
        increment(root -> right, diff);
    } 
    else if (root -> left != NULL) {
        root -> left -> data += diff;
        increment(root -> left, diff);
    }

}

void change(BinaryTreeNode < int > * root) {

    // Base case.
    if (root == NULL || (root -> left == NULL && root -> right == NULL)) {
        return;
    }

    // Traverse substrees.
    change(root -> left);
    change(root -> right);

    // Child sum.
    int childVal = 0;
    if (root -> left != NULL) {
        childVal += root -> left -> data;
    }

    if (root -> right != NULL) {
        childVal += root -> right -> data;
    }

    int diff = childVal - root -> data;

    // childVal > parentVal
    if (diff > 0) {
        root -> data += diff;
    } 

    else {
        increment(root, -diff);
    }

}
void changeTree(BinaryTreeNode < int > * root) {
    change(root);
}  