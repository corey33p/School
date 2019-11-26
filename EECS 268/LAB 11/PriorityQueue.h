template <typename T>
class PriorityQueue
{
public:
	PriorityQueue(int initialSize);
	PriorityQueue(const PriorityQueue<T>& pq); // The copy constructor
	~PriorityQueue();

	void enqueue(T newEntry);
	void dequeue() /* throw EmptyPriorityQueue */;
	bool isEmpty() const;
	T peekFront() const /* throw EmptyPriorityQueue */;
private:
	Heap<T>* theHeap;
};
