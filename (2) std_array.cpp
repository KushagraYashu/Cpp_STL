#include <array> //for using std::array
/*  std::array is an advanced implementation of basic C arrays with optimizations for C++.
    they should be used only for small containers (small dataset).
    they are fixed size.
    they are fixed size and allocated before execution, hence its faster than std::vector.
    std::array takes stack memory and hence has the danger of running out of stack space if used for large datasets (as stack space is less).
    std::vector uses heap and hence is more suitable for large datasets.
*/

#include <algorithm> //for standard library algorithms
/*std::sort and such*/

#include <iostream> //for cin/cout (std::cin or std::cout)

#include <string> //for string (std::string)

int main()
{
    std::array<float, 3> a = {11, 22, 33};
    /* SYNTAX:
        - std::array<_data_type_, _size_) _array_Name_ = {datavalues}; the equals sign (a '=' {datavalues}) can be omitted, ex: std::array<int, 3> b{1,2,3};
        - if the comipler supports C++ 17 or higher the syntax can be more simplified: std::array c{10.0, 13.5}; no need to define size and type.
    */

    std::cout << a.size() << std::endl; // size() returns the size of the array

    std::cout << a[0] << "\t" << a.at(2) << std::endl; // a[index] returns the element at index, a.at(index) does the same operation with safe access that is with bounds check and avoids any out of bound access.

    std::array<float, 3> b{10.0, 14.3, 13.5};
    a = b;
    std::cout << a[0] << "\t" << a.at(2) << std::endl;
    /* ASSIGNMENT:
        - std::array supports direct assignment, that is 2 std::arrays can directly assign values of each other by simply equating.
        - the same cannot be done with raw basic arrays.
        - to use this property the arrays must be of same size and datatype.
    */

    auto it = a.begin();
    it = begin(a); // begin(arrayName) returns an iterator pointing to the start of the array (first element).
}