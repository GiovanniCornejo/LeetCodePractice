#!/bin/bash

# Navigate to the easy/ directory
cd "$(dirname "$0")"

# Test a single problem
if [ -n "$1" ]; then
    # Check if the provided problem directory exists
    if [ -d "$1" ]; then
        # Navigate to problem directory
        cd "$1"

        # Extract problem name from directory name
        problem_name=$(basename "$PWD")

        echo "Testing problem: $problem_name"

        # Compile the main.cpp file for the current problem
        if g++ *.cpp -o a.out; then
            # Run the compiled executable then delete it
            ./a.out
            rm a.out
        else
            echo "Compilation failed for $problem_name"
        fi

        echo "----------------------------------------"
    else
        echo "Problem '$1' not found."
    fi
else
    echo "Please provide the name of the problem directory to test."
fi