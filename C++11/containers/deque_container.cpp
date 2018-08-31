/* deque : doubly ended queue, pronounced as deck
 * Its a sequence containers with dynamic sizes that can be expanded / contracted
 * on both ends.
 * Provide efficient insertion & deletion of elements at both ends
 * Unlike vectors, deques are not guaranteed to store all its elements in contigous
 * storage locations. 
 * Accessing elements in deque by offsetting a pointer to another elements can cause
 * undefined behavior.
 * deque & vector provide very similar interface and can be used for similar purposes.
 * Vector allocate single array which might be needed to be reallocated for growth.
 * deque allocates in scattered manner in different different chunks of storage,
 * container keeps the necessary information to provide direct access to any of its
 * elements in constant time with a iterators.
 * Hence deques are little complex than vectors.
 * deques should be used where long sequences needs to be stored and reallocation
 * is expensive.
 * For insertion & removal operations deques perform worst compare lists & forward
 * lists.
 * methods :- assign, at, back, begin, cbegin, cend, clear, 
 * emplace :- add element at specified position and returns iterator at that point
 * emplace_front, emplace_back.
 * erase : to delete single or range of elements
 * get_allocator : returns allocator
