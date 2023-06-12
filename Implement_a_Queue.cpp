#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int frontt;
    int rear;
    int cnt;
    int n;
public:
    Queue() {
        arr = new int[5001];
        n = 5001;
        frontt = 0;
        rear = 0;
        cnt = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return cnt == 0;
    }

    void enqueue(int data) {
        if(cnt ==  n) return ;
        arr[rear %n] = data;
        rear++;cnt++;
    }

    int dequeue() {
        if(cnt == 0) return -1;
        int fr =  arr[frontt % n];
        frontt++;cnt--;
        return fr;
    }

    int front() {
        if(cnt == 0) return -1;
        return arr[frontt % n];
    }
};