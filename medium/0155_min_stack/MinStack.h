/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * Implement the MinStack class:
 *      MinStack() initializes the stack object.
 *      void push(int val) pushes the element val onto the stack.
 *      void pop() removes the element on the top of the stack.
 *      int top() gets the top element of the stack.
 *      int getMin() retrieves the minimum element in the stack.
 *
 * You must implement a solution with O(1) time complexity for each function.
 *
 * Constraints:
 *      -2^31 <= val <= 2^31 - 1
 *      Methods pop, top and getMin operations will always be called on non-empty stacks.
 *      At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <stack>

class MinStack
{
public:
    MinStack() : front{}, min{} {}

    void push(int val)
    {
        front.push(val);
        if (min.empty() || val <= min.top())
            min.push(val);
    }

    void pop()
    {
        if (front.top() == min.top())
            min.pop();
        front.pop();
    }

    int top() { return front.top(); }

    int getMin() { return min.top(); }

private:
    std::stack<int> front;
    std::stack<int> min;
};
#endif