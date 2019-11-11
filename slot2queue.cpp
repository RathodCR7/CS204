#include <bits/stdc++.h>
using namespace std;


struct Queue
{
    int frt, rear, Size;
    unsigned capacity;
    int* arr;
};


struct Queue* createQueue(unsigned capacity)
{
    struct Queue* que = new Queue();
    que->capacity = capacity;
    que->frt = que->Size = 0;
    que->rear = capacity - 1;
    que->arr = new int[(que->capacity * sizeof(int))];
    return que;
}


int isFull(struct Queue* que)
{ return (que->Size == que->capacity); }

int isEmpty(struct Queue* que)
{ return (que->Size == 0); }

void enqueue(struct Queue* que, int item)
{
    if (isFull(que)) {
        return;
    }
    que->rear = (que->rear + 1) % que->capacity;
    que->arr[que->rear] = item;
    que->Size = que->Size + 1;
}


int dequeue(struct Queue* que)
{
    if (isEmpty(que)){
        return INT_MIN;
    }

    int item = que->arr[que->frt];
    que->frt = (que->frt + 1) % que->capacity;
    que->Size = que->Size - 1;
    return item;
}

int Front(struct Queue* que)
{
    if (isEmpty(que)){
        return INT_MIN;
    }
    return que->arr[que->frt];
}

int rear(struct Queue* que)
{
    if (isEmpty(que)){
         return INT_MIN;
    }

    return que->arr[que->rear];
}

int main()
{
    Queue* que = createQueue(1000);
    int n;
    cin>>n;
    int ans[n][2];
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='D'){
            if(isEmpty(que)){
                ans[i][0] = -1;
                ans[i][1] = 0;
            }
            else{
                ans[i][0] = dequeue(que);
                ans[i][1] = que->Size;
            }
        }
        else{
            int x;
            cin>>x;
            enqueue(que,x);
            ans[i][0] = que->Size;
            ans[i][1] = INT_MIN;
        }
    }
    for(int i=0;i<n;i++){
        if(ans[i][1] == INT_MIN){
            cout<<ans[i][0]<<endl;
        }
        else{
            cout<<ans[i][0]<< " " <<ans[i][1]<<endl;

        }
    }
    return 0;
}
