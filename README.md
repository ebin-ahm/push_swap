*This project has been created as part of the 42 curriculum by ebin-ahm.*

# Push Swap

## Algorithm Overview

This implementation of **push_swap** uses a hybrid strategy combining:

- **Index normalization**
- **Chunk-based partitioning**
- **Greedy cost-based reinsertion**

This approach efficiently handles large stacks while keeping the number of operations low.

---

## 1. Index Normalization

The first step is converting all input values into **sorted indices**.

Instead of working with raw numbers, each value is assigned a rank based on its position in the sorted order.

Example:

```bash
Input numbers:
42 -5 100 7

Sorted values:
-5 7 42 100

Assigned indices:
2 0 3 1
```

Working with indices allows the algorithm to operate on a clean range:
0 → smallest number
n-1 → largest number


This simplifies comparisons and improves algorithm efficiency.

---

## 2. Chunk-Based Partitioning (Stack A → Stack B)

For large inputs, elements are pushed from **Stack A to Stack B** using a **chunk strategy**.

The chunk size is calculated dynamically:

```c
chunk_size = (n * 91) / 100;
```

For example, with an input size of **100**, approximately **91 elements are pushed to Stack B**, leaving the remaining elements in **Stack A** to form the initial sorted base.

Through experimentation with different chunk percentages, it was observed that **pushing around 90–91% of the elements generally produces the best results for large inputs**. Moving most elements to Stack B reduces the number of rotations required when scanning Stack A, allowing the algorithm to push elements more quickly and letting the greedy reinsertion phase handle the majority of the ordering.

However, when the input size is **smaller (e.g., ≤ 100)**, using a slightly **smaller chunk percentage tends to perform better**. Keeping more elements in Stack A provides a stronger structural base for reinserting elements from Stack B, which reduces the number of rotations required during the greedy insertion phase.

As a result, the optimal chunk percentage depends on the input size: **larger inputs benefit from larger chunk ratios**, while **smaller inputs perform better with more conservative chunk sizes**.

### Process

While Stack A contains more than 3 elements:

1. Inspect the top element of Stack A

2. If its index is within the current chunk range → push to B (pb)

3. Otherwise → rotate A (ra)

Additionally, when pushing elements to B, smaller indices may be rotated (rb) to maintain a structure that improves reinsertion efficiency.

This step gradually moves most values into Stack B, leaving only a few elements in Stack A.

## 3. Sorting the Remaining Elements in Stack A
Once 3 elements remain in Stack A, they are sorted using a small deterministic routine.

Sorting 3 elements requires only a few operations:

- sa
- ra
- rra

This ensures Stack A is correctly ordered before reinserting elements from Stack B.

## 4. Greedy Insertion (Stack B -> Stack A)
Next, elements from Stack B are inserted back into Stack A using a greedy cost model.

For each element in Stack B:

1. Determine the target position in Stack A where it should be inserted.
2. Compute the cost of moving that element:
	- rotations required in Stack A
	- rotations required in Stack B
3. Choose the element with the lowest total cost.
4. Execute the necessary rotations.
5. Push the element back into Stack A (pa).

This greedy approach minimizes the number of operations required during reinsertion.

## 5. Final Alignment
After all elements are moved back to Stack A, the stack may be correctly sorted but rotated.

The algorithm performs a final step:

- Rotate Stack A until the smallest index is at the top.

This guarantees that Stack A is fully sorted.

## Testing

Expected Results for:
1. No parameters = nothing to be displayed and return to prompt
```bash
./push_swap
```
2. Non integer parameters = display "Error" followed by a '\n'
```bash
./push_swap 2 1 N
```
3. Duplicate integer parameters = display "Error" followed by a '\n'
```bash
./push_swap 6 3 2 2 1
```

#### 10 tests for 100 numbers (line by line)
```bash
max=0
for i in {1..10}; do
  ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
  moves=$(./push_swap $ARG | tee /tmp/moves | wc -l)
  result=$(cat /tmp/moves | ./checker_linux $ARG)
  [ "$moves" -gt "$max" ] && max=$moves
  echo "Test $i -> $result | $moves moves"
done
echo "Worst: $max moves"
```
#### 100 tests for 100 numbers (display only worst result)
```bash
max=0
for i in {1..100}; do
  ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
  m=$(./push_swap $ARG | wc -l | tr -d ' ')
  if [ "$m" -gt "$max" ]; then
    max=$m
  fi
done
echo "worst(100) = $max"
```
#### 10 tests for 500 numbers (line by line)
```bash
max=0
for i in {1..10}; do
  ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
  moves=$(./push_swap $ARG | tee /tmp/moves | wc -l)
  result=$(cat /tmp/moves | ./checker_linux $ARG)

  if [ "$moves" -gt "$max" ]; then
    max=$moves
  fi

  echo "Test $i -> $result | $moves moves"
done

echo "Worst: $max moves"
```

#### 100 tests for 500 numbers (display only worst result)
```bash
max=0
for i in {1..100}; do
  ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
  m=$(./push_swap $ARG | wc -l | tr -d ' ')
  if [ "$m" -gt "$max" ]; then
    max=$m
  fi
done
echo "worst(500) = $max"
```