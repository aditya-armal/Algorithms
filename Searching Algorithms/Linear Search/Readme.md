# Linear Search Algorithm

This repository contains a C++ implementation of the Linear Search algorithm. Linear search is a simple searching algorithm that scans each element of a collection to find a specific target value.

## Table of Contents
- [Introduction](#introduction)
- [Code Overview](#code-overview)
- [How to Use](#how-to-use)

## Introduction

Linear search, also known as sequential search, is a basic searching algorithm used to find a target element within a collection (such as an array or a vector). It works by iterating through each element in the collection and comparing them with the target element until a match is found.

## Code Overview

The C++ code in this folder consists of two main parts:
- `linearSearch` function: This function takes a vector of integers and a target integer as its parameters. It iterates through the vector and returns the index of the target element if found, or -1 if the element is not present in the vector.

- `main` function: In the `main` function, a sample vector `arr` is defined, and a target value `target` is specified. The `linearSearch` function is called to search for the target element in the vector, and the result is displayed on the console.

## How to Use

To use the linear search algorithm:

1. Ensure you have a C++ compiler installed on your system.

2. Download or clone this repository to your local machine.

3. Open the terminal and navigate to the directory where the code is located.

4. Compile the code using the C++ compiler. For example, you can use g++:

   ```bash
   g++ linear_search.cpp -o linear_search
   ```

5. Run the compiled executable:

   ```bash
   ./linear_search
   ```

6. The program will output whether the target element was found in the vector and its index if found.
