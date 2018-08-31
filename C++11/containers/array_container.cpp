/* Fixed size
 * Just a wrapper over standard array declaration with few global functions
 * so that arrays can be used as standard containers
 * do not manage allocation through allocator
 * cannot be expanded as vector
 * members :- front, back & data
 * can be treated as tuple objects
 * methods:-
 * declaring : std::array<int, 10> myarray = {1,2,3,4,5};
 * i) at : element at sepcified position
 * ii) back : reference to the last element in the array container
 * 		e.g myarray.back() = 30
 * iii) front : reference to the first element
 *      e.g myarray.front() = 20
 * iv) begin : returns an iterator to the begining of the array
 *      e.g auto it = myarray.begin()
 * v) end : returns an iterator to the end of the array
 * vi) cbegin : returns a const iterator to the begining of the array
 *     using this data cannot be modified
 * vii) cend : returns a const iterator to the end of the array
 * viii) crbegin : returns a const reverse iterator which can be used to print
 *       array in reverse order
 * ix) data : pointer to the data contained by the array object
 * x) empty : check if array is empty, true if array size is 0 o.w false
 * xi) fill : sets the value to the all elements of the array
 * xii) max_size : maximum elements that array can hold. Same as size
 * xiii) [] : to access
 * xiv) swap : swaps 2 arrays of same size
