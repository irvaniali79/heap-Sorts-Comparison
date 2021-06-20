# heap-Sorts-Comparison
compare heapsort;insert;heapify

# in fact 
![des](https://user-images.githubusercontent.com/66170668/120933184-35bd4c80-c70e-11eb-87ce-75dc4340aa8f.png)


  for see the site click on the link:
  https://okabe-rintaru.github.io/heap-Sorts-Comparison/


# in the theory
- ## insert 
  In the worst case, the newly inserted node has to be swapped at each level from the bottom up to the root node to maintain the heap property. Now we know that a heap tree is a balanced complete tree data structure.

  In the worst case, we need one swap at each level of the tree. So the total number of the swaps would be equal to the height of the heap tree. The height of a balanced complete tree with N number of nodes is logN. Each swap takes O(1) time.

  Therefore, in the worst case, the time complexity of inserting a node in a heap would be O(logN).
- ## heapfiy
  you can read this refrence:
  - https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/
- ## heapsort
  Total Time Complexity of Heapsort

  The adjust() method is called n-1 times. So the total complexity for repairing the heap is also O(n log n).

  Both sub-algorithms, therefore, have the same time complexity. Hence:

  The time complexity of Heapsort is:O(n log n) 
  
