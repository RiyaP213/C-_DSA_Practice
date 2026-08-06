#include<iostream>
#include<queue>
using namespace std;

void Interleave( queue<int> &original)
{
    queue<int> firstHalf;
    int n = original.size();
    int halfSize = n / 2;
    queue<int> firstHalf;

    // Step 1: Push the first half of the elements into firstHalf queue
    for (int i = 0; i < halfSize; i++)
    {
        firstHalf.push(original.front());
        original.pop();
    }

    // Step 2: Interleave the elements from firstHalf and original
    while (!firstHalf.empty())
    {
        original.push(firstHalf.front());
        firstHalf.pop();
            original.push(original.front());
            original.pop();
        }
    }
    int main(){
        queue<int> q;
        for(int i=1; i<=10;i++){
            q.push(i);
        }
        Interleave(q);

        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout<<endl;
        return 0;
    }