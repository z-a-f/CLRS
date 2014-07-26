#include "../support/myIncludes.hpp"

using namespace std;

#include "../support/myFunctions.hpp"

template <class T> class doubleStack {
private:
  int size;
  int top[2]; // top[0] is the first stack, top[1] is the second
  T* S;

public:
  doubleStack(int s) {
    size = s;
    top[0] = -1;
    top[1] = s;
    S = new T[size];
  }

  ~doubleStack() {
    delete [] S;
  }

  bool stackEmpty () {
    return (top[0] == -1 && top[1] == size);
  }

  bool stackEmpty(int option) {
    if (option == 0) {
      return (top[0] == -1);
    } else if (option == 1) {
      return (top[1] == size);
    } else {
      return stackEmpty();
    }
  }

  bool stackFull () {
    return top[0] >= top[1]-1;
  }
  
  void push (T x, int option) {
    assert(option >= 0 && option <= 1);
    if (stackFull()) {
      cout << "(OVERFLOW) Both stacks are full - Cannot PUSH!\n";
    } else {
      // If compiler is bad - replace with an if statement.
      // "if-statements" are faster than pow():
      top[option] += pow(-1, option);	
      S[top[option]] = x;
    }
  }

  T pop (int option) {
    assert(option >= 0 && option <= 1);
    if (stackEmpty(option)) {
      cout << "(UNDERFLOW) Stack " << option << " is empty - Cannot POP!\n";
      return 0;
    } else {
      // If compiler is bad - replace with an if statement.
      // "if-statements" are faster than pow():
      top[option] -= pow(-1, option);
      return S[top[(int)option]+1];
    }
  }

  void print () {
    for (int i = 0; i <= top[0]; i++) {
      cout << S[i] << '\t';
    }
    for (int i = top[0]+1; i < top[1]; i++) {
      cout << "X\t";
    }
    for (int i = top[1]; i < size; i++) {
      cout << S[i] << '\t';
    }
    cout << endl;
  }
    
};

int main() {
  doubleStack<int> S(5);
  S.print();
  S.pop(1);
  S.pop(0);
  S.print();

  S.push(1, 0); S.print();
  S.push(2, 0); S.print();
  S.push(3, 0); S.print();
  S.push(4, 1); S.print();
  S.push(5, 1); S.print();
  S.push(6, 1); S.print();
  S.pop(1); S.print();
  S.push(7, 0); S.print();
  S.pop(0); S.print();
  S.push(8, 1); S.print();
  S.push(8, 1); S.print();
  
  S.pop(0); S.print();
  S.pop(0); S.print();
  S.pop(0); S.print();
  S.pop(0); S.print();
  S.pop(0); S.print();
}
