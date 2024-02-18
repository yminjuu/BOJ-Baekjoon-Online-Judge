#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int heap[100001] = {
    0,
};
int N, tmp, n, idx, siz = 0;

int min(int a, int b)
{
    if (heap[a] <= heap[b])
        return a;
    else
        return b;
}

void pop()
{
    if (siz == 1)
    {
        heap[1] = 0;
        siz--;
        return;
    }

    heap[1] = heap[siz];
    heap[siz--] = 0;
    tmp = heap[1];
    idx = 1; // idx는 1부터 시작
    while (idx * 2 <= siz)
    {
        if (idx * 2 == siz) // 1. 왼쪽 자식 노드가 마지막이면
        {
            if (tmp > heap[idx * 2])
            {
                heap[idx] = heap[idx * 2];
                heap[idx * 2] = tmp;
                idx *= 2;
            }
            break;
        }
        else // 2. 왼쪽, 오른쪽 노드 둘 다 존재한다면
        {
            int k = min(idx * 2, idx * 2 + 1);
            if (tmp <= heap[k])
            {
                break;
            }
            else
            {
                heap[idx] = heap[k];
                heap[k] = tmp;
                idx = k;
            }
        }
    }
    return;
}

void push(int num)
{
    if (siz == 0)
    {
        siz++;
        heap[1] = num;
    }
    else
    {
        heap[++siz] = num; // 넣는 숫자: num
        idx = siz;         // 삽입 원소의 현재 위치: idx
        while (idx > 1)
        {
            if (heap[idx / 2] <= num)
                break;
            else
            {
                heap[idx] = heap[idx / 2];
                heap[idx / 2] = num;
                idx /= 2;
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    while (N--)
    {
        cin >> n;
        if (n == 0)
        {
            if (siz == 0)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << heap[1] << "\n";
                pop();
            }
        }
        else
        {
            push(n);
        }
    }
    return 0;
}