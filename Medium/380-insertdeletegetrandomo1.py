import random

class RandomizedSet:

    def __init__(self):
        self.elems = []
        self.idx = {}

    def insert(self, val: int) -> bool:
        if val in self.idx:
            return False

        self.elems.append(val)
        self.idx[val] = len(self.elems) - 1

        return True

    def remove(self, val: int) -> bool:
        if val not in self.idx:
            return False

        idx = self.idx[val]

        tmp = self.elems[-1]

        self.elems[-1] = self.elems[idx]
        self.elems[idx] = tmp

        self.idx[tmp] = idx

        self.elems.pop()
        del self.idx[val]

        return True

    def getRandom(self) -> int:
        return random.choice(self.elems)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()