template <class T>
Core::SLL<T>::SLL() {
    mHead = nullptr;
    mTail = nullptr;
}

template <class T>
Core::SLL<T>::~SLL() {
    Node* node = mHead;
    while (node) {
        Node* next = node->next;
        delete node;
        node = next;
    }
}

template <class T>
void Core::SLL<T>::pushFront(T value) {
    Node* node = new Node;
    node->value = value;
    node->next = mHead;
    node->prev = nullptr;
    if (mHead) {
        mHead->prev = node;
    }
    mHead = node;
    if (!mTail) {
        mTail = node;
    }
    this->mSize++;
}

template <class T>
void Core::SLL<T>::pushBack(T value) {
    Node* node = new Node;
    node->value = value;
    node->next = nullptr;
    node->prev = mTail;
    if (mTail) {
        mTail->next = node;
    }
    mTail = node;
    if (!mHead) {
        mHead = node;
    }
    this->mSize++;
}

template <class T>
void Core::SLL<T>::insert(int index, T value) {
    if (index < 0 || index > this->mSize) {
        throw std::out_of_range("Core::SLL => Index out of range");
    }
    if (index == 0) {
        pushFront(value);
        return;
    }
    if (index == this->mSize) {
        pushBack(value);
        return;
    }
    Node* node = mHead;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = node;
    newNode->prev = node->prev;
    node->prev->next = newNode;
    node->prev = newNode;
    this->mSize++;
}

template <class T>
T Core::SLL<T>::popFront() {
    if (!mHead) {
        throw std::out_of_range("Core::SLL => List is empty");
    }
    Node* node = mHead;
    T value = node->value;
    mHead = node->next;
    if (mHead) {
        mHead->prev = nullptr;
    }
    delete node;
    this->mSize--;
    return value;
}

template <class T>
T Core::SLL<T>::popBack() {
    if (!mTail) {
        throw std::out_of_range("Core::SLL => List is empty");
    }
    Node* node = mTail;
    T value = node->value;
    mTail = node->prev;
    if (mTail) {
        mTail->next = nullptr;
    }
    delete node;
    this->mSize--;
    return value;
}

template <class T>
T Core::SLL<T>::eraseByIndex(int index) {
    if (index < 0 || index >= this->mSize) {
        throw std::out_of_range("Core::SLL => Index out of range");
    }
    if (index == 0) {
        return popFront();
    }
    if (index == this->mSize - 1) {
        return popBack();
    }
    Node* node = mHead;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    T value = node->value;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    this->mSize--;
    return value;
}

template <class T>
void Core::SLL<T>::eraseByValue(T value) {
    Node* node = mHead;
    while (node) {
        if (node->value == value) {
            if (node == mHead) {
                popFront();
                node = mHead;
            } else if (node == mTail) {
                popBack();
                node = nullptr;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                Node* next = node->next;
                delete node;
                node = next;
                this->mSize--;
            }
        } else {
            node = node->next;
        }
    }
}

template <class T>
void Core::SLL<T>::updateByIndex(int index, T value) {
    if (index < 0 || index >= this->mSize) {
        throw std::out_of_range("Core::SLL => Index out of range");
    }
    Node* node = mHead;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    node->value = value;
}

template <class T>
void Core::SLL<T>::updateByValue(T oldValue, T newValue) {
    Node* node = mHead;
    while (node) {
        if (node->value == oldValue) {
            node->value = newValue;
        }
        node = node->next;
    }
}

template <class T>
bool Core::SLL<T>::contains(T value) {
    Node* node = mHead;
    while (node) {
        if (node->value == value) {
            return true;
        }
        node = node->next;
    }
    return false;
}
