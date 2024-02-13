template <class T>
LinearList<T>::LinearList() : head(nullptr), tail(nullptr) {}

template <class T>
LinearList<T>::~LinearList() {
    head.reset();
    tail.reset();
}

template <class T>
void LinearList<T>::pushFront(const T& data) {
    NodePtr newNode = std::make_shared<Node>(data);
    if (!head)
        head = tail = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
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
        newNode->prev = tail;
        tail = newNode;
    }
    mSize++;
}

template <class T>
void LinearList<T>::insert(size_t pos, const T& data) {
    if (!(0 <= pos && pos < mSize))
        throw std::out_of_range("LinearList::insert() => out of range!");
    if (!pos)
        pushFront(data);
    else if (pos == mSize - 1)
        pushBack(data);
    else {
        NodePtr newNode = std::make_shared<Node>(data);
        NodePtr shiftNode = head;
        for (size_t i = 0; i < pos; i++, shiftNode = shiftNode->next)
            ;
        newNode->prev = shiftNode->prev;
        newNode->next = shiftNode;
        shiftNode->prev->next = newNode;
        shiftNode->prev = newNode;
        mSize++;
    }
}

template <class T>
T LinearList<T>::popFront() {
    if (!mSize)
        throw std::underflow_error("LinearList::popFront() => List is empty!");
    T res = head->data;
    if (mSize == 1)
        head = tail = nullptr;
    else {
        NodePtr del = head;
        head = head->next;
        del->next = nullptr;
        del.reset();
    }
    return res;
}

template <class T>
T LinearList<T>::popBack() {
    if (!mSize)
        throw std::underflow_error("LinearList::popBack() => List is empty!");
    T res = tail->data;
    if (mSize == 1)
        tail = tail = nullptr;
    else {
        NodePtr del = tail;
        tail = tail->prev;
        del->prev = nullptr;
        del.reset();
    }
    return res;
}

template <class T>
T LinearList<T>::erase(size_t pos) {
    if (!(0 <= pos && pos < mSize))
        throw std::out_of_range("LinearList::erase(pos) => out of range!");
    if (pos == 0)
        return popFront();
    else if (pos == mSize - 1)
        return popBack();

    NodePtr del = head;
    for (size_t i = 0; i < pos; i++, del = del->next)
        ;

    T res = del->data;
    del->prev->next = del->next;
    del->next->prev = del->prev;
    del.reset();

    return res;
}

template <class T>
void LinearList<T>::erase(const T& target) {
    NodePtr cur = head;
    for (size_t i = 0; i < mSize; i++, cur = cur->next)
        if (cur->data == target) {
            erase(i);
            break;
        }
}

template <class T>
void LinearList<T>::update(size_t pos, const T& newData) {
    if (!(0 <= pos && pos < mSize))
        throw std::out_of_range(
            "LinearList::update(pos,newData) => out of range!"
        );

    NodePtr upd = head;
    for (size_t i = 0; i < pos; i++, upd = upd->next)
        ;
    upd->data = newData;
}

template <class T>
void LinearList<T>::update(const T& oldData, const T& newData) {
    NodePtr upd = head;
    for (size_t i = 0; i < mSize; i++, upd = upd->next)
        if (upd->data == oldData) upd->data = newData;
}
