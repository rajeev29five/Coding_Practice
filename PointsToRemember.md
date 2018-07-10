## C++ STL

### Vector

|Method		                          |Return Type                  |Description               |Example |
|-----------------------------------------|-----------------------------|--------------------------|--------|
|size( )                                  |integer                      |size of vector            |v.size()|
|push_back(data)                          |void                         |add element at the end    |v.push_back(object)|
|begin( )                                 |iterator                     |iterator to first element |v.begin()|
|end( )                                   |iterator                     |iterator to second element|v.end()|
|erase(position iterator)                 |void                         |remove specified element  |v.end(iterator)|
|upper_bound(iter first, iter last, value)|iterator                     |iterator to first element in range > value, if not present returns iter to end|upper_bound(itr first, itr last, value)|
|lower_bound(iter first, iter last, value)|iterator                     |iterator to first element in range which has value not less than **value**, if not present returns iter to end|lower_bound(iter first, iter last, value)|

### Map

|Method                  |Return Type|Description                                              |Example                                   |
|------------------------|-----------|---------------------------------------------------------|------------------------------------------|
|size( )                 |integer    |size of vector                                           |m.size()                                  |
|insert(pair<key, value>)|void       |add a new element                                        |m.insert(pair<object, object>(key, value))|
|begin( )                |iterator   |iterator to first element                                |m.begin()                                 |
|end( )                  |iterator   |iterator to second element                               |m.end()                                   |
|find(key)               |iterator   |iterator to key value if present else iterator to the end|m.find(key)                               |
|erase(key)              |void       |removes specified key                                    |m.erase(key)                              |

### Queue

|Method    |Return Type |Description           |Example      |
|----------|------------|----------------------|-------------|
|size( )   |integer     |size of queue         |q.size()     |
|empty( )  |boolean     |empty or not          |q.empty()    |
|front( )  |reference   |first element of queue|q.front()    |
|back( )   |reference   |last element of queue |q.back()     |
|push(data)|void        |add element at the end|q.push(objec)|
|pop()     |void        |deletes first element |q.pop()      |