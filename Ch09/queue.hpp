
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
  
  int len() {
    return abs(tail - head);
  }

  bool queueEmpty() {
    return (head == tail);
  }

  bool queueFull() {
    return (len() == size);
  }
  
  void enqueue(T x) {
    if (queueFull()) {
      cout << "(OVERFLOW) Queue is full - Cannot ENQUEUE!\n";
    } else {
      Q[tail] = x;
      tail = (tail+1) % size;
    }
  }
  
  T dequeue() {
    if (queueEmpty()) {
      cout << "(UNDERFLOW) Queue is empty - Cannot DEQUEUE!\n";
      return INT_MIN;
    } else {
      T x = Q[head];
      head = (head+1) % size;
      return x;
    }
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
