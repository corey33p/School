template <class T>
class Heap {
    public:
    	Heap(int initialSize);
    	Heap(const Heap<T>& heap); // The copy constructor
    	~Heap();

    	void add(T* newItem);
    	bool isEmpty() const;
    	void remove() /* throw EmptyHeap */;
    	T peekTop() const /* throw EmptyHeap */;
        void print();
    private:
    	T** theHeap;
    	int sizeOfArray;
        int height;
    	int numItemsInHeap=0;
        void doubleTheSize();
};
