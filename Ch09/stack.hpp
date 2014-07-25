
// Define a stack data structure:
template <class T> class stack {
private:
  int size;
  int top;
  T* S;
  
public:
  // Constructor:
  stack(int s) {
    size = s;
    top = -1;
    S = new T[size];
  }

  // Destructor:
  ~stack() {
    delete [] S;
    // cout << "Stack deleted!\n";
  }

  bool stackEmpty() {
    return (top == -1);
  }

  bool stackFull() {
    return (top+1 == size);
  }

  void push (T x) {
    if (stackFull()) {
      cout << "(OVERFLOW) Stack is full - Cannot PUSH!\n";
      return;
    } else {
      top++;
      S[top] = x;
    }
  }
  
  T pop () {
    if (stackEmpty()) {
      cout << "(UNDERFLOW) Stack is empty - Cannot POP!\n";
      return INT_MIN;
    } else {
      top--;
      return S[top+1];
    }
  }

};
