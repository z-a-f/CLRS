
// Define a queue data structure:
template <class T> class queue {
private:
  int size;
  int head;
  int tail;
  T* Q;
  
public:
  // Constructor:
  queue(int s) {
    size = s;
    head = 0;
    tail = 0;
    Q = new T[size];
  }

  // Destructor:
  ~queue() {
    delete [] Q;
  }

  bool queueEmpty() {
    return (head == tail);
  }

  bool queueFull() {
    return (head == tail+1);
  }
  
  void enqueue(T x) {
    if (queueFull()) {
      cout << "(OVERFLOW) Queue is full - Cannot ENQUEUE!\n";
    } else {
      Q[tail] = x;
      if (tail == size-1){
	tail = 0;
      } else {
	tail++;
      }
    }
  }
  
  T dequeue() {
    if (queueEmpty()) {
      cout << "(UNDERFLOW) Queue is empty - Cannot DEQUEUE!\n";
      return INT_MIN;
    } else {
      T x = Q[head];
      if (head == size-1) {
	head = 1;
      } else {
	head++;
      }
      return x;
    }
  }

};
