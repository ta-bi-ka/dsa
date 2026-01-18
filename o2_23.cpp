void reverse_pos(int ind1, int ind2) {
    while (ind1 < ind2) {
        Node* left = head;
        Node* right = head;

        for (int i = 0; i < ind1; i++) left = left->next;
        for (int i = 0; i < ind2; i++) right = right->next;

        int temp = left->item;
        left->item = right->item;
        right->item = temp;

        ind1++;
        ind2--;
    }
}
bool nextIsInsert;
nextIsInsert = true; // because first call must insert
void surprise_insert(int item){
    if(nextIsInsert){
        insert(item);   // your existing insert function
    }else{
        append(item);   // your existing append function
    }
    nextIsInsert = !nextIsInsert;
}


void combine() {
    if (curr >= length - 2) {
        cout << "Invalid" << endl;
        return;
    }

    int sum = list[curr] + list[curr + 1] + list[curr + 2];
    list[curr] = sum;

    // shift left by 2 positions
    for (int i = curr + 1; i < length - 2; i++) {
        list[i] = list[i + 2];
    }

    length -= 2;
}
void combine() {
    if (current == nullptr || current->next == nullptr || current->next->next == nullptr) {
        cout << "Invalid" << endl;
        return;
    }

    Node *a = current;
    Node *b = current->next;
    Node *c = current->next->next;

    a->data = a->data + b->data + c->data;

    // delete b and c from list
    a->next = c->next;

    delete b;
    delete c;

    // size decreases by 2 (if you maintain size)
    length -= 2;
}
