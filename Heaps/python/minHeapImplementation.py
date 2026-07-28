# Problem Statement: Implement min heap

# Problem Link: https://www.codingninjas.com/studio/problems/min-heap-implementation_5480527?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class MinHeap:
    def __init__(self, size):
        self.capacity = size
        self.heap = [0] * size
        self.size = 0

    def extract_min_element(self):
        if self.size == 0:
            return -1
            
        min_value = self.heap[0]
        self.heap[0] = self.heap[self.size - 1]
        self.size -= 1
        self._heapify(0)
        return min_value

    def delete_element(self, ind):
        if ind < 0 or ind >= self.size:
            return
            
        self.heap[ind] = self.heap[self.size - 1]
        self.size -= 1
        self._heapify(ind)

    def insert(self, val):
        if self.size == self.capacity:
            return
            
        self.heap[self.size] = val
        self.size += 1
        current_index = self.size - 1
        
        while current_index > 0:
            parent_index = (current_index - 1) // 2
            if self.heap[parent_index] > self.heap[current_index]:
                self.heap[parent_index], self.heap[current_index] = self.heap[current_index], self.heap[parent_index]
                current_index = parent_index
            else:
                break

    def _heapify(self, i):
        smallest = i
        left_child = 2 * i + 1
        right_child = 2 * i + 2
        
        if left_child < self.size and self.heap[left_child] < self.heap[smallest]:
            smallest = left_child
            
        if right_child < self.size and self.heap[right_child] < self.heap[smallest]:
            smallest = right_child
            
        if i != smallest:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self._heapify(smallest)
