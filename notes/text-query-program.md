## Design of the Query Program

设计程序时可以从程序需要具备的功能（operations）入手，通过列出功能点，我们可以知道我们大概需要哪些数据结构：

- 因为我们需要记住word出现的行的行号，所以我们要逐行的读取文本内容，同时，建立word与行号的关系
- 在输出结果时：
  - 我们需要通过行号找到文本中对应行的内容
  - 我们需要知道所有word出现的行号
  - 行号必须是递增且去重的

针对上述功能，我们可能需要一下数据结构：

- `vector<string> text`，逐行存储文本内容，可以通过下标（行号-1）直接获取文本内容。e.g. `text[3]`获取第2行的文本内容
- `map<string, set<int>> ln_map`，map保存了word与其出现的行号之间的关系，set保证了行号是递增的且不重复的

Q

- 为什么不能用下标访问共享指针中的vector
  - shared_ptrs don't have subscript operator and don't support pointer arithmetic