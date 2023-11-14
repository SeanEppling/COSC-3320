k=ceiling(n/2);
function shiftNode(node, k) {
    right = node->right;
    left = node->left;
    CG = right->num_values_in_subtree;
    CL = left->num_values_in_subtree;
    CE = node->multiplicity;
    if ( CG >= k ) {
        findNode = shiftNode(right, k);
        // swaps nodes wherever they are in the tree
        swap( node, findNode );
        return node;
    }
    else if (CG + CE >= k) {
        // kth largest node
        return node;
    }
    else {
        findNode = shift( left, k - CG - CE );
        swap( node, findNode );
        return node;
    }
}

function formatTree( node ) {
    // pass through root of tree as node
    // undo the swapping so nodes left are less than parent and nodes right are greater than parent
    if ( right && node->value > right->value ) {
        swap( node, right );
        formatTree( right );
    }
    else if ( left && node->value < left->value ) {
        swap( node, left );
        formatTree( left );
    }
}