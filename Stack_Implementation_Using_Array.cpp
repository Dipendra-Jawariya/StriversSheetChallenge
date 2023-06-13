#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr;
    int max_size;
    int size;

public:
    
    Stack(int capacity) {
        arr = new int[capacity];
        max_size = capacity;
        size = -1;
    } 

    void push(int num) {
        if(isFull()) return;

        size++;
        arr[size] = num;
    }

    int pop() {
        if(isEmpty()) return -1;
        int ans = arr[size];
        size--;
        return ans;
    }
    
    int top() {
        // Write your code here.
        if(isEmpty()) return -1;

        return arr[size];

    }
    
    int isEmpty() {
        return size==-1;
    }
    
    int isFull() {
        return (size-1) == max_size;
    }
    
};