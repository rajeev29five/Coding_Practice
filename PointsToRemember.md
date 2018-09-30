## C++ STL

### Vector

|Method		                                |Return Type                  |Description               |Example |
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
|push(data)|void        |add element at the end|q.push(object)|
|pop()     |void        |deletes first element |q.pop()      |

### Stack

|Method    |Return Type |Description              |Example      |
|----------|------------|-------------------------|-------------|
|size( )   |integer     |size of stack            |s.size()     |
|empty( )  |boolean     |empty or not             |s.empty()    |
|top( )    |reference   |topmost element in stack |s.top()      |
|push(data)|void        |add element at the end   |s.push(objec)|
|pop()     |void        |deletes first element    |s.pop()      |


## Java

### Scanner

|Method      |Return Type| Description                   |
|----------- |-----------|-------------------------------|
|next( )     | String    |returns next token from scanner|
|nextLine( ) | String    |moves scanner position to the next line and returns the value as a string|
|nextByte( ) | byte      |returns next token as byte  |
|nextShort() | short     |returns next token as short |
|nextInt( )  | integer	 |returns next token as int   |
|nextLong( ) | long      |returns next token as long  |
|nextFloat() | float     |returns next token as float |
|nextDouble()| double    |returns next token as double|

### ArrayList

The important points about Java ArrayList class are:

* Java ArrayList class can contain duplicate elements.
* Java ArrayList class maintains insertion order.
* Java ArrayList class is non synchronized.
* Java ArrayList allows random access because array works at the index basis.
* In Java ArrayList class, manipulation is slow because a lot of shifting needs to be occurred if any element is removed from the array list.


|Method      |Return Type| Description                   |
|----------- |-----------|-------------------------------|
|add(int index, Object )     | void    |add objects to array list|
|addAll(Collection) | boolean    |add all the element of Collection to list|
|size()|integer|size of ArrayList|

Iterator itr = al.iterator();  
  while(itr.hasNext()){  
   System.out.println(itr.next());  
  }  

### LinkedList

|Method      |Return Type| Description                   |
|----------- |-----------|-------------------------------|
|add(Object)    | void    |adds object to list|
|addFirst(Object) | void    |adds object by head insertion|
|addLast(Object) | void      |adds object by tail insertion  |
|contains(Object) | boolean     |return true if object is present |
|getFirst( )  | Object	 |returns first object in list  |
|getLast( ) | Object      |returns last object in list |
|remove(Object) | boolean     |removes particular object from the list |
|size()|integer|size of LinkeList|

### HashSet

|Method      |Return Type| Description                   |
|----------- |-----------|-------------------------------|
|add(Object)    | void    |adds object to HashSet|
|size() | integer    |size of HashSet|
|contains(Object) | boolean     |return true if object is present |
|isEmpty()| boolean| return true if empty else false|
