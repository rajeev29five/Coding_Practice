## C++ STL

### Vector

|Method| Return Type|Description|Example|
|---|---|---|---|
|size( )|integer|size of vector|v.size()|
|push_back(data)|void|add element at the end|v.push_back(object)|
|begin( )|iterator|iterator to first element|v.begin()|
|end( )|iterator|iterator to second element|v.end()|
|erase(position iterator)||remove specified element|v.end(iterator)|

### Map

|Method| Return Type|Description|Example|
|---|---|---|---|
|size( )|integer|size of vector|m.size()|
|insert(pair<key, value>)|void|add a new element|m.insert(pair<objec, object>(key, value))|
|begin( )|iterator|iterator to first element|m.begin()|
|end( )|iterator|iterator to second element|m.end()|
|find(key)|iterator|iterator to key value if found else iterator to the end|m.find(key)|
|erase(position iterator)||remove specified element|m.end()|

### Queue

| Method | Return Type | Description |
|---|---|---|
|size( )|integer|size of queue |   
|empty( )|boolean|empty or not|
|front( )|reference|first element of queue|
|back( )|reference|last element of queue|
|push(data)|void|add element at the end|
|pop()|void|deletes first element|
