Node* makeAVL_A() {
    Node* n4 = new Node(4);
    Node* n8a = new Node(8);
    Node* n8b = new Node(8);
    Node* n10 = new Node(10);

    n8a->left = n4;
    n8a->right = n8b;
    n10->left = n8a;

    Node* x = n10;
    Node* y = n8a;
    Node* t2 = y->right;

    y->right = x;
    x->left = t2;

    return y;
}

Node* makeAVL_B() {
    Node* n10 = new Node(10);
    Node* n16 = new Node(16);
    Node* n12 = new Node(12);
    Node* n18 = new Node(18);

    n16->left = n12;
    n16->right = n18;
    n10->right = n16;

    Node* x = n10;
    Node* y = n16;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    return y;
}
