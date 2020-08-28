# Range-Vector

Add the class `range`:

The class `range` has for objective to mimic the way python work with the operator `[start:end:step]` on it list.
`range` will accept any container that has random access iterator ex: `std::vector`, `const char[N]` etc... .

Info: `range` does not copy the data at instantiation, it only use iterator.

### How to use it

    std::vector src = {1, 2, 3, 4, 5, 6, 7};
    
    for (int i : range(src)(1, {}, 2))
        std::cout << i << ':';
        
    output -> "2:4:6:"

or you can use the warped version of std::vector fund in "range_vector.hpp"!

    vector src = {1, 2, 3, 4, 5, 6, 7};
    
    for (int i : src(1, {}, 2)) // no need to create a range, the operator() has been added
        std::cout << i << ':';
        
    output -> "2:4:6:"

`range` can also create new container, to which each element will be copied

    std::array src = {'1', '2', '3', '4', '5', '6', '7'};
    std::string str = range(src)(3, {}, -1).to<std::string>();
    
    std::cout << str;
        
    output -> "4321"

`range` also work with **constexpr** !!

    constexpr range range1("Hello World!!");
    // /!\ there is an exception with the type const char[N], it doesn't take the last element of the array ('\0')!

    constexpr range hello_range = range1(0, 5);
    constexpr range world_range = range1(6, 11);
    
    std::cout << std::integral_constant<char, world_range[0]>::value << ": "; // Display "W: "
    for (char c : hello_range)
        std::cout << c; // Display "Hello"

    output -> "W: Hello"

The lib can compile in C++14, but it was design for C++17 or higher.
The examples above and the unit tests can only be compiled in C++17 or higher.

### How to implement it in your project

It's an header only lib, therefore you only need to include the file "range.hpp"

- You can ether copy "range.hpp" into your project.
- Or use `git submodule`.

You can use this lib for any of your project but you have to keep the licence!

### Coverage & Tests

- To this day there is 100% line coverage, but I couldn't find any way to get the branches in C++ that work (if you wish to offer help).
- The tests are performed using google tests https://github.com/google/googletest
- Tested with GCC(g++) on fedora 27

### Link

GitHub: https://github.com/Ail-nare/Range-Vector