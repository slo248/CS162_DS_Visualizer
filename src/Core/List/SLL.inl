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
    Node* node = new Node(value, mHead);
    mHead = node;
    if (!mTail) mTail = node;
    this->mSize++;
}

template <class T>
void Core::SLL<T>::pushBack(T value) {
    Node* node = new Node(value, nullptr);
    if (!mHead) {
        mHead = node;
        mTail = node;
    } else {
        mTail->next = node;
        mTail = node;
    }
    this->mSize++;
}

template <class T>
void Core::SLL<T>::insert(int index, T value) {
    if (index < 0 || index > this->mSize)
        throw std::out_of_range("Core::SLL => Index out of range");
    if (index == 0) {
        pushFront(value);
        return;
    }
    if (index == this->mSize) {
        pushBack(value);
        return;
    }
    Node* node = mHead;
    for (int i = 0; i < index - 1; i++) {
        node = node->next;
    }
    Node* newNode = new Node(value, node->next);
    node->next = newNode;
    this->mSize++;
}

template <class T>
T Core::SLL<T>::popFront() {
    if (!mHead) throw std::out_of_range("Core::SLL => List is empty");
    Node* node = mHead;
    T value = node->value;
    mHead = node->next;
    delete node;
    this->mSize--;
    return value;
}

template <class T>
T Core::SLL<T>::popBack() {
    if (!mHead) throw std::out_of_range("Core::SLL => List is empty");
    Node* node = mHead;
    T value = node->value;
    if (this->mSize == 1) {
        mHead = nullptr;
        mTail = nullptr;
    } else {
        while (node->next != mTail) {
            node = node->next;
        }
        node->next = nullptr;
        mTail = node;
    }
    delete node;
    this->mSize--;
    return value;
}

template <class T>
T Core::SLL<T>::eraseByIndex(int index) {
    if (index < 0 || index >= this->mSize)
        throw std::out_of_range("Core::SLL => Index out of range");
    if (index == 0) return popFront();
    if (index == this->mSize - 1) return popBack();
    Node* node = mHead;
    for (int i = 0; i < index - 1; i++) {
        node = node->next;
    }
    Node* temp = node->next;
    T value = temp->value;
    node->next = temp->next;
    delete temp;
    this->mSize--;
    return value;
}

template <class T>
void Core::SLL<T>::eraseByValue(T value) {
    Node* node = mHead;
    if (node->value == value) {
        popFront();
        return;
    }
    while (node->next) {
        if (node->next->value == value) {
            Node* temp = node->next;
            node->next = temp->next;
            delete temp;
            this->mSize--;
            return;
        }
        node = node->next;
    }
    throw std::out_of_range("Core::SLL => Value not found");
}

template <class T>
void Core::SLL<T>::updateByIndex(int index, T value) {
    if (index < 0 || index >= this->mSize)
        throw std::out_of_range("Core::SLL => Index out of range");
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
            return;
        }
        node = node->next;
    }
    throw std::out_of_range("Core::SLL => Value not found");
}

template <class T>
bool Core::SLL<T>::contains(T value) {
    Node* node = mHead;
    while (node) {
        if (node->value == value) return true;
        node = node->next;
    }
    return false;
}
