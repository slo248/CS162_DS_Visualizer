template <class T>
Core::SLL<T>::SLL() {
    mHead = nullptr;
}

template <class T>
Core::SLL<T>::~SLL() {
    clear();
}

template <class T>
void Core::SLL<T>::pushFront(T value) {
    NodePtr node = std::make_unique<Node>(value, std::move(mHead));
    if (!mHead) mHead = std::move(node);
    mHead = std::move(node);
    this->mSize++;
}

template <class T>
void Core::SLL<T>::pushBack(T value) {
    NodePtr node = std::make_unique<Node>(value);
    if (!mHead)
        mHead = std::move(node);
    else {
        Node* lastNode = mHead.get();
        while (lastNode->next) lastNode = lastNode->next.get();
        lastNode->next = std::move(node);
    }
    this->mSize++;
}

template <class T>
void Core::SLL<T>::insert(int index, T value) {
    if (index < 0 || index > this->mSize) return;
    if (index == 0) {
        pushFront(value);
        return;
    }
    if (index == this->mSize) {
        pushBack(value);
        return;
    }
    Node* node = mHead.get();
    for (int i = 0; i < index - 1; i++) node = node->next.get();
    NodePtr newNode = std::make_unique<Node>(value, std::move(node->next));
    node->next = std::move(newNode);
    this->mSize++;
}

template <class T>
T Core::SLL<T>::popFront() {
    if (!mHead) throw std::runtime_error("Core::SLL => List is empty");
    NodePtr node = std::move(mHead);
    mHead = std::move(node->next);
    this->mSize--;
    return node->value;
}

template <class T>
T Core::SLL<T>::popBack() {
    if (!mHead) throw std::runtime_error("Core::SLL => List is empty");
    if (this->mSize == 1) return popFront();
    Node* node = mHead.get();
    while (node->next->next) node = node->next.get();
    NodePtr lastNode = std::move(node->next);
    node->next = nullptr;
    this->mSize--;
    return lastNode->value;
}

template <class T>
T Core::SLL<T>::eraseByIndex(int index) {
    if (index < 0 || index >= this->mSize)
        throw std::runtime_error("Core::SLL => Index out of bounds");
    if (index == 0) return popFront();
    if (index == this->mSize - 1) return popBack();
    Node* node = mHead.get();
    for (int i = 0; i < index - 1; i++) node = node->next.get();
    NodePtr eraseNode = std::move(node->next);
    node->next = std::move(eraseNode->next);
    this->mSize--;
    return eraseNode->value;
}

template <class T>
void Core::SLL<T>::eraseByValue(T value) {
    if (!mHead) throw std::runtime_error("Core::SLL => List is empty");
    if (mHead->value == value) {
        popFront();
        return;
    }
    Node* node = mHead.get();
    while (node->next && node->next->value != value) node = node->next.get();
    if (!node->next) return;
    NodePtr eraseNode = std::move(node->next);
    node->next = std::move(eraseNode->next);
    this->mSize--;
}

template <class T>
void Core::SLL<T>::updateByIndex(int index, T value) {
    if (index < 0 || index >= this->mSize)
        throw std::runtime_error("Core::SLL => Index out of bounds");
    Node* node = mHead.get();
    for (int i = 0; i < index; i++) node = node->next.get();
    node->value = value;
}

template <class T>
void Core::SLL<T>::updateByValue(T oldValue, T newValue) {
    if (!mHead) throw std::runtime_error("Core::SLL => List is empty");
    Node* node = mHead.get();
    while (node && node->value != oldValue) node = node->next.get();
    if (!node) return;
    node->value = newValue;
}

template <class T>
bool Core::SLL<T>::contains(T value) {
    if (!mHead) return false;
    Node* node = mHead.get();
    while (node && node->value != value) node = node->next.get();
    return node;
}

template <class T>
void Core::SLL<T>::init() {
    // dev later
}

template <class T>
void Core::SLL<T>::clear() {
    while (mHead) popFront();
}
