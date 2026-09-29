DSA Assignment 2 – Question 11

Binary Search Tree and Linear Search

Problem Statement

A government database stores the following identification numbers:

A102, A25, A7, B100, B12, A120, B3, A45

The task is to:

1. Implement a Binary Search Tree (BST) to organize the identification numbers.
2. Display the IDs using inorder traversal.
3. Compare BST Search and Linear Search.
4. Record the number of comparisons.
5. Analyse how key length and insertion order affect BST height and search performance.
6. Compare the observed results with theoretical time complexities.

---

Technologies Used

- Language: C
- Data Structure: Binary Search Tree
- Searching Techniques:
  - BST Search
  - Linear Search
- Compiler: GCC

---

Input Data

A102
A25
A7
B100
B12
A120
B3
A45

Search keys used:

A120
B3
A45
C10

---

BST Construction

The IDs are inserted into the BST in the given order.

Insertion Order

A102 → A25 → A7 → B100 → B12 → A120 → B3 → A45

Resulting Inorder Traversal

A102 A120 A25 A45 A7 B100 B12 B3

Inorder traversal of a BST produces the keys in lexicographical order.

---

Search Comparison

ID| BST Comparisons| Linear Comparisons| Result
A120| 4| 6| Found
B3| 6| 7| Found
A45| 5| 8| Found
C10| 4| 8| Not Found

The number of comparisons is counted during program execution.

---

Trace Table

BST Insertion Trace

Step| ID Inserted| Comparison Path| Position
1| A102| —| Root
2| A25| A25 > A102| Right of A102
3| A7| A7 > A102, A7 > A25| Right of A25
4| B100| B100 > A102, > A25, > A7| Right of A7
5| B12| B12 > A102, > A25, > A7, > B100| Right of B100
6| A120| A120 > A102, A120 > A25, A120 < A7| Left of A7
7| B3| B3 > A102, > A25, > A7, > B100, > B12| Right of B12
8| A45| A45 > A102, > A25, > A7, A45 < B100, A45 < B12, A45 > A120| Right of A120

Search Trace

Search ID| BST Comparisons| Linear Comparisons| Result
A120| 4| 6| Found
B3| 6| 7| Found
A45| 5| 8| Found
C10| 4| 8| Not Found

Trace Observation

BST search follows the appropriate path through the tree, while linear search checks the IDs sequentially from the beginning. Therefore, the number of comparisons depends on the BST structure for BST Search and on the position of the key in the array for Linear Search.

---

Effect of BST Structure

The insertion order affects the shape and height of the BST.

For the given insertion order, the BST has a height of 6. An unbalanced tree may require more comparisons during searching.

A balanced BST provides better search performance because its height is smaller.

In the worst case, a BST can become skewed and its search complexity becomes O(n).

---

Effect of Key Length

The identification numbers are strings, so they are compared using "strcmp()".

Longer keys may require more character comparisons before a difference is found. Therefore, key length can affect the actual execution time even when the number of BST nodes visited is unchanged.

---

Complexity Analysis

Operation| Average/Best Case| Worst Case
BST Search| O(log n)| O(n)
BST Insertion| O(log n)| O(n)
Inorder Traversal| O(n)| O(n)
Linear Search| O(n)| O(n)

Space Complexity

The BST requires O(n) space for storing n nodes.

The linear search array requires O(n) space for storing the IDs.

---

BST Search vs Linear Search

BST search can reduce the number of comparisons when the tree is reasonably balanced.

Linear search checks elements one by one. Therefore, its search time increases directly with the number of stored IDs.

However, BST performance depends on the tree structure and insertion order.

---

Conclusion

The program successfully constructs a Binary Search Tree using the given government identification numbers and performs inorder traversal.

BST Search and Linear Search were implemented and their comparison counts were recorded. The analysis shows that BST search can provide faster searching when the tree is reasonably balanced, while an unbalanced BST can have O(n) worst-case search time.

For a growing database, maintaining a suitably balanced search tree can help provide efficient searching.

---

Files in This Repository

src/bst_search.c       → C source code
input/input.txt        → Input data
output/output.txt      → Program output
trace/trace_table.md   → Trace table
analysis/complexity_analysis.md → Complexity analysis
README.md              → Project documentation

How to Run

Compile

gcc src/bst_search.c -o bst_search

Run

./bst_search

---

Assignment

Subject: Data Structures and Algorithms
Assignment: Assignment 2
Question: 11
Language: C