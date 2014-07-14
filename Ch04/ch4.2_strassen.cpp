#include <iostream>

using namespace std;

template <class T> class matrix {
	public:
		T create(int rows, int cols);
	private:
		T **data;
};
template <class T> T matrix<T>::create(int rows, int cols) {
	data = new T*[rows][cols];
}

int main() {
	int matrix<int>::create(5, 5);
}

