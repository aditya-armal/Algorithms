# Minimum Total Cost Calculation

The C code you provided is designed to calculate the minimum total cost of a set of elements in an array. The code defines functions to find the minimum and maximum of two numbers and sorts an array of costs. It then calculates the minimum total cost based on certain rules.

## Code Overview

Here is a brief overview of the code's components:

1. **Function Definitions:**
   - `min(int num1, int num2)`: Returns the minimum of two numbers.
   - `max(int num1, int num2)`: Returns the maximum of two numbers.
   - `sort(int arr[], int n)`: Sorts an array of integers in ascending order using the Bubble Sort algorithm.

2. **Main Function (`main()`):**
     - It reads the number of test cases (`test_cases`) from the user.
     - For each test case, it reads the number of elements in the array (`n`) and the corresponding costs.
     - It sorts the array of costs in ascending order.
     - It iteratively calculates the minimum total cost based on certain conditions and prints the intermediate and final results.

3. **Cost Calculation Logic:**
   - The code calculates the minimum total cost based on the following logic:
     - It starts with the largest and smallest elements of the sorted array and calculates two possible sums (`cost1` and `cost2`).
     - The code iteratively selects pairs of elements and calculates the minimum of these two sums.
     - The algorithm considers different cases for the size of the array (`k`) and handles them accordingly.
     - Finally, it prints the minimum total cost for the current test case.

## How to Use

To use this code, follow these steps:

1. Compile the code using a C compiler (e.g., GCC) in your terminal:

   ```
   gcc filename.c -o program_name
   ```

   Replace `filename.c` with the name of your C source file and `program_name` with the desired name for the compiled program.

2. Run the compiled program:

   ```
   ./program_name
   ```

3. Enter the number of test cases and input data as prompted by the program.

4. The program will calculate and display the minimum total cost for each test case.

## Example

Suppose you run the program and input the following data:

```
2               // Number of test cases
5               // Number of elements in the first test case
10 20 30 40 50  // Cost values for the first test case
4               // Number of elements in the second test case
5 2 10 8        // Cost values for the second test case
```

The program will display the minimum total cost for each test case, which can be used for further analysis or decision-making.

## Application Areas
The algorithm implemented in this code can be used in various real-world scenarios, including:

1. Travel Planning: Optimizing travel routes and expenses for multi-destination trips.
2. Resource Allocation: Efficiently allocating resources in project management and budgeting.
3. Inventory Management: Minimizing inventory holding and restocking costs.
4. Network Routing: Finding the most cost-effective data transmission paths in computer networks.
5. Supply Chain Optimization: Reducing transportation and storage costs in distribution.

## Conclusion

This code demonstrates a method for calculating the minimum total cost of a set of elements using a specific algorithm. It can be customized and integrated into other applications as needed.
