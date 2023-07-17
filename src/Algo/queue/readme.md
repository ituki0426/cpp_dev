# dequeue

- O(1)で先頭/末尾への追加(deq.push_front(x)/deq.push_back(x)), 削除(deq.pop_front()/deq.pop_back()), 参照(deq.front()/deq.back())を行えます
- 途中への挿入はO(n)なため基本行いません
- 01BFSに使われます(後述)