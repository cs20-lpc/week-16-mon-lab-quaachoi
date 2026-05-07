template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    while (i > 0 && data[i] < data[parent(i)]) 
    {
        swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if (l < size() && data[l] < data[smallest])
    {
        smallest = l;
    }

    if (r < size() && data[r] < data[smallest])
    {
        smallest = r;
    }

    if (smallest != i) 
    {
        swap(data[i], data[smallest]);
        siftDown(smallest);
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    data.push_back(value);
    siftUp(size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue;
    // TODO: Implement removing the root element.
    if (empty())
    {
        throw runtime_error("Heap is empty");
    }

    rootValue = data[0];

    data[0] = data.back();
    data.pop_back();

    if (!empty())
    {
        siftDown(0);
    }
    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property
    if (index < size()) 
    {
        if (index > 0 && data[index] < data[parent(index)])
        {
            siftUp(index);
        }
        else
        {
            siftDown(index);
        }
    }
}
