#include <vector> //for using std::vector
/*std::vector is a dynamic array that has the ability to change size while program execution*/

#include <algorithm> //for standard library algorithms
/*std::sort and such*/

#include <iostream> //for cin/cout (std::cin or std::cout)

#include <string> //for string (std::string)

bool EqualCaseInsensitive(const std::string &s1, const std::string &s2)
{
	return std::equal(begin(s1), end(s1), begin(s2), end(s2), [](auto const &x, auto const &y)
					  { return tolower(x) == tolower(y); });
}
/* CASE INSENSITIVE FXN:
	- EqualCaseInsensitive fxn here performs case insensitive comparision of 2 given strings, return type must be bool as it will be used in lambda[] of find_if().
	- std::equal(startPos_stringOne, endPos_stringOne, startPos_stringTwo, endPos_stringTwo, condition_lambda_fxn) returns a bool value if the items are equal.
	- lambda function inside of this equal converts the each character of strings to lower case using tolower() and then compares them for equality.
	- const& are used to save size and time for large data.
*/

int main()
{
	std::vector<int> marks{};
	/* SYNTAX:
		- std::vector<_data_type_> vector_name{values if required, or can leave empty, or even omit the curly braces}
	*/

	marks.push_back(10);
	/* INSERTION:
		- vector.push_back(_data_value_) is the method to append a new value to existing vector array, and it will also increase the size of the vector as needed for the new  value.
	*/

	for (int i = 0; i < 10; i++)
	{
		marks.push_back(i);
	}
	// Inserting some more values

	for (auto x : marks)
	{
		std::cout << x << "\n";
	}
	/* Displaying vector using range-based for loop
		- for(auto x: vector_or_variable) the auto variable x will go from initial value of vector to its last value and end there, hence a range-based for loop.
		- std::cout is used to display on console.
	*/

	std::vector<std::string> v{3, "hello"};
	/* Add repeating elements (only for strings)
		- std::vector<std::string> _name_{_count_int_, "_string_"} the passed string will be repeated count times in the  vector
	*/

	for (auto x : v) // displaying the vector
	{
		std::cout << x << "\n";
	}

	std::cout << marks.size() << "\t" << v.size() << "\n";
	/* SIZE:
		- size of vector can be find out by _vector_name_.size()
	*/

	if (marks.empty() || v.empty())
	{
		std::cout << "either one vector is empty" << marks.empty() << v.empty() << "\n";
	}
	else
	{
		std::cout << marks.empty() << "\t" << v.empty() << std::endl;
	}
	/* Checking empty vector
		- _vector_name_.empty() checks whether the vector is empty or not.
		- it returns 1 if vector is empty and 0 otherwise.
	*/

	marks.clear();
	std::cout << marks.size() << "\n";
	v.clear();
	std::cout << v.size() << "\n";
	/* CLEAR:
		- _vector_name_.clear() clears the contents of vector and make it an empty zero sized vector.
	*/

	marks.push_back(69);
	v.push_back("hehe");

	std::cout << marks[0] << "\t" << v[0] << std::endl;
	std::cout << marks.at(0) << "\t" << v.at(0) << std::endl;
	/* Accessing individual element of Vector
		- _vector_name_[_index_] this will display the content at the specified index, but it does not have out of bounds check. (index is 0 based)
		- _vector_name_.at(_index_) this will display the content at the specified index, and it does have out of bounds check, it throws std::out_of_bounds_exception when index is out of bounds. (index is 0 based)
	*/
	// .at() IS SLOW THAN [] FOR VERY LARGE CALULATIONS THAT INVOLVES MATRICES OR LARGE INTEGERS

	std::cout << marks.capacity() << "\t" << v.capacity() << std::endl;
	/* CAPACITY:
		- A vector allocates itself a very large chunk of contigous memory locations and then the pushback() add the elements into it and increases its size.
		- _vector_name_.capacity() returns the max capacity a vector has, or the large chunk of memory it allocated itself.
		- capacity >= size
	*/

	marks.reserve(50);
	v.reserve(10);
	std::cout << marks.capacity() << "\t" << v.capacity() << std::endl;
	/* CHANGE CAPACITY:
		- capacity of a vector can be changed by reserve(), it is useful when we have an estimate of how many entries of data will be stored in the vector, so we already reserve the sufficient memory.
		- _vector_name_.reserve(_integer_value_) it will reserve the specified continous memory locations for the vector.
	*/

	for (int i = 0; i < 5; i++)
	{
		marks.push_back(rand());
	}
	std::sort(begin(marks), end(marks));
	for (auto x : marks)
	{
		std::cout << x << "\t";
	}
	std::cout << "\n";
	/* SORT
		- std::sort(_starting_pos_, _end_pos_) sorts the data present in between the start position and end position.
		- start and end can be extracted using "begin(_vector_name_)" & "end(_vector_name_)"
	*/
	/* BEGIN & END
		- both the functions return an iterator.
		- the begin(_vector_name_) points to the first element of the passed vector.
		- the end(_vector_name_) not points to the last element it points to the element next to last.
		- sort() fxn includes begin() in the sorting but excludes the end() point, so the vector is sorted from start to last element and hence end() points to next to last the last is included in sort.
	*/
	/* ITERATORS
		- iterators are like general pointers that point to a location inside a container (here std::vector)
		- they can be used as any pointer, accesing the next iterator will be simmply ++it, accesing its data will be *it
		- iterator can be defined as auto _iteratorName_ = begin(_sampleVector_) [just an example]
	*/

	std::vector<std::string> names{};
	names.push_back("Kushagra");
	names.push_back("Yashu");
	names.push_back("John Doe");
	names.push_back("Ram");
	names.push_back("Shyam");
	names.push_back("longg stringg or wottttt????");

	std::sort(begin(names), end(names), [](auto const &a, auto const &b)
			  { return a.length() < b.length(); });
	for (auto const &x : names)
	{
		std::cout << x << std::endl;
	}
	/* CUSTOM SORT
		- custom sort is implemented by passing another argument in std::sort(), the additional argument will be the custom sort condition. A faster way to do so can be lambda function i.e. [](_fxn_arguments_){_fxn_body_}
		- [] is passed alongside the begin() and end()
		- the above example sorts the names vector based on string length, the [] fxn arguments (auto const &a, auto const &b) are auto constant reference variables to fastly accesing all elements of vector names without wasting memory in case of large number of elements. (range-for loop also has constant reference variable for fast and memory friendly access of vector elements)
		- the [] function returns 1 if length of a (a.length()) is less than length of b (b.length()), hence sorting the vector based on length of the string.
	*/

	std::vector<int> demo{1, 2, 3, 4, 5};
	marks.insert(begin(marks), 1776);
	marks.insert(begin(marks) + 1, 2, 100);
	marks.insert(begin(marks) + 3, {10, 20, 30});
	marks.insert(begin(marks) + 4, begin(demo), end(demo));
	for (auto x : marks)
	{
		std::cout << x << "  ";
	}
	std::cout << std::endl;
	/* INSERT:
		- _vector_name_.insert(pos, value) this will insert a new data entry with the given value just before the passed pos iterator, this iterator can be something like marks.begin() or an offset to marks.begin() i.e. marks.begin()+2
		- _vectorName_.insert(pos, count, value) this inserts the provided value, count times before the pos.
		- _vectorName_.insert(pos, {data range(values seprated by commas)}) this will insert all the data values before the provided pos.
		- _vectorName_.insert(pos, startPos, endPos) this will insert the values between the startPos and endPos, it can be used to insert another whole vector to existing vector.
	*/

	auto it = std::remove(begin(marks), end(marks), 1);
	for (auto x : marks)
	{
		std::cout << x << "  ";
	}
	std::cout << "\n";
	marks.erase(it, end(marks));
	it = std::remove_if(begin(marks), marks.end(), [](auto a)
						{ return a < 1000; });
	for (auto x : marks)
	{
		std::cout << x << "  ";
	}
	std::cout << "\n";
	marks.erase(it, end(marks));
	for (auto x : marks)
	{
		std::cout << x << "  ";
	}
	std::cout << "\n";
	/* REMOVE, REMOVE_IF & ERASE:
		- std::remove(startPos_iterator, endPos_iterator, value) removes the passed value and returns an iterator to the end of the modified vector, the modified vector have an additional value incompensation of the removed value and the returned iterator  can be used to remove that additional value.
		- std::remove_if(startPos_Iterator, endPos_Iterator, conditionOnWhichRemovalShouldBeDone) it shifts all the good/required elements in the start of vector and shifts all the elements to be removed at the end of the vector.
		- the condition can be defined in a lambda function [] same as custom sort.
		- remove_if also returns an iterator pointing to the extra/garbage values.
		- _vectorName_.erase(startPos_Iterator, endPos_Iterator) it erases and frees all the memory between the passed startPos and endPos, startPos can be the iterator returned by remove or remove_if and endPos can be end of vector i.e. end(_vectorName_) or _vectorName_.end()
	*/

	it = std::find(begin(marks), end(marks), 1776);
	std::cout << *it << std::endl;
	auto itString = std::find(begin(names), end(names), "YashU");
	if (itString == end(names))
	{
		std::cout << "Element not Found" << std::endl;
	}
	else
	{
		std::cout << *itString << std::endl;
	}
	std::string strr = "yashu";
	itString = std::find_if(begin(names), end(names), [&strr](auto &x)
							{ return EqualCaseInsensitive(x, strr); });
	if (itString == end(names))
	{
		std::cout << "Element not Found";
	}
	else
	{
		std::cout << *itString << std::endl;
	}
	/* FIND and FIND_IF:
		- std::find(startPos, endPos, valueToFind) returns an iterator pointing to the value existing in the given vector.
		- if the value does not exist it points to the end of the vector, hence an if cond. to check whether it returned end or not should be implemented.
		- the returned iterator will be of the type the vector was, int vector's find will return int iterator.
		- std::find_if(startPos, endPos, condition_or_predicate) finds the element based on given condition, condition can be defined in lambda[] fxn.
		- if use of an external variable is needed inside of lambda, it can be referenced inside the lambda square brackets ([&strr]) as done in the example of find_if() above.
	*/
}