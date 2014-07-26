
// Define a queue data structure:
template <class T> class queue {
private:
  int size;
  int head;
  int tail;
  bool full;	// Holds information if the queue is filled
  bool empty;	// Holds information if the queue is empty
  T* Q;
  
public:
  // Constructor:
  queue(int s) {
    size = s;
    head = 0;
    tail = 0;
    full = 0;
    empty = 1;
    Q = new T[size];
  }

  // Destructor:
  ~queue() {
    delete [] Q;
  }

  void enqueue(T x) {
    if (full) {
      cout << "(OVERFLOW) Cannot ENQUEUE!\n";
    } else {
      Q[tail] = x;
      tail = (tail + 1) % size;
      empty = false;	// If we pushed something - we are not empty
      if (tail == head) full = true;	// tail incremented to full
    }
  }
  
  T dequeue() {
    T x = 0;
    if (empty) {
      cout << "(UNDERFLOW) Cannot DEQUEUE!\n";
    } else {
      x = Q[head];
      head = (head + 1) % size;
      full = false;
      if (head == tail) empty = true;
    }
    return x;
  }

  void print() {
    cout << "head: " << head;
    cout << " tail: " << tail;
    cout << " Q: ";
    for (int i = 0; i < size; i++) {
      cout << Q[i] << ' ';
    }
    cout << endl;
  }

};
