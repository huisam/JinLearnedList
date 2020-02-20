from collections import OrderedDict
class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.db = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.db:
            return -1

        self.db.move_to_end(key)
        return self.db[key]


    def put(self, key: int, value: int) -> None:
        if key in self.db:
            self.db.move_to_end(key)
        self.db[key] = value
        if len(self.db) > self.capacity:
            self.db.popitem(last=False)