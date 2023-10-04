#ifndef mat_algo
#define mat_algo
#include <iostream>
#include <vector>

template <typename T, typename S>
inline T MAXIMUM(T x1, T x2) { return x1 < x2 ? x2 : x1; }
template <class T>
struct MAT2
{
private:
	std::pair<T, T> data;
	// Helper function to swap the elements of a pair
	static std::pair<T, T> SWAP_FUNC(std::pair<T, T> mat)
	{
		std::swap(mat.first, mat.second);
		return mat;
	}

public:
	MAT2(const MAT2& a) : data(a.data) {}

	// Default constructor is not needed, as it is implicitly provided for simple types like std::pair

	// Default destructor is not needed either, as there are no custom resources to release

	// Other constructors, if needed, can be defined as well

	// Example: constructor taking two values of type T
	MAT2(const T& x, const T& y) : data(x, y) {}

	// Example: constructor taking a std::pair<T, T>
	MAT2(const std::pair<T, T>& p) : data(p) {}

	// Example: constructor taking an array of two elements of type T
	MAT2(const T(&arr)[2]) : data(arr[0], arr[1]) {}

	// Example: constructor taking an initializer list of two elements of type T
	MAT2(std::initializer_list<T> il) : data(*il.begin(), *(il.begin() + 1)) {}

	// Accessors to retrieve individual elements
	const T& getX() const { return data.first; }
	const T& getY() const { return data.second; }

	// Other member functions, if needed, can be defined here
};

//


#ifndef DEBUG
//Test Unit Here
#define DEBUG
#endif
#endif
