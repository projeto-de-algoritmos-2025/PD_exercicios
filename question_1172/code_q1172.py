class DinnerPlates:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.stacks = []
        self.available_stacks = []
    def push(self, val: int) -> None:
        while self.available_stacks and (self.available_stacks[0] >= len(self.stacks) or len(self.stacks[self.available_stacks[0]]) == self.capacity):
            heapq.heappop(self.available_stacks)
        if not self.available_stacks:
            idx = len(self.stacks)
            self.stacks.append([])
            heapq.heappush(self.available_stacks, idx)
        idx = self.available_stacks[0]
        self.stacks[idx].append(val)
        if len(self.stacks[idx]) == self.capacity:
            heapq.heappop(self.available_stacks)
    def pop(self) -> int:
        while self.stacks and not self.stacks[-1]:
            self.stacks.pop()
        if not self.stacks:
            return -1
        return self.popAtStack(len(self.stacks) - 1)
    def popAtStack(self, index: int) -> int:
        if index < 0 or index >= len(self.stacks) or not self.stacks[index]:
            return -1
        if len(self.stacks[index]) == self.capacity:
             heapq.heappush(self.available_stacks, index)
        val = self.stacks[index].pop()
        while self.stacks and not self.stacks[-1]:
            self.stacks.pop()
        return val