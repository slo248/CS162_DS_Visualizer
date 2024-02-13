template <class T>
LinearList<T>::LinearList() : head(nullptr), tail(nullptr) {}

template <class T>
void LinearList<T>::pushFront(const T& data) {
    NodePtr newNode = std::make_shared<Node>(data);
    if (!head)
        head = tail = newNode;
    else {
        newNode->next = head;
        head = newNode;
    }
    mSize++;
}

template <class T>
void LinearList<T>::pushBack(const T& data) {
    NodePtr newNode = std::make_shared<Node>(data);
    if (!head)
        head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
    mSize++;
}

template <class T>
void LinearList<T>::insert(int pos, const T& data) {
    if (!(0 <= pos && pos < mSize))
        throw std::out_of_range("LinearList::insert() => out of range!");
    if (!pos)
        pushFront(data);
    else if (pos == mSize - 1)
        pushBack(data);
    else {
        NodePtr newNode = std::make_shared<Node>(data);
        if (!head)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
        mSize++;
    }
}
