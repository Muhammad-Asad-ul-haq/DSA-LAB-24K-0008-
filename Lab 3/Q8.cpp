struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* concatenate(Node* headL, Node* headM) {
    if (!headL) return headM;
    if (!headM) return headL;

    Node* tailL = headL;
    while (tailL->next) {
        tailL = tailL->next;
    }

    tailL->next = headM;
    headM->prev = tailL;

    return headL;
}
