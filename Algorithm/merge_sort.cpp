#include <bits/stdc++.h>

#define SIZE 10000

using namespace std;


void Merge(int *data,int left,int mid,int right)
{
    int tempdata[right-left+1];
    int index=0, left_index=left, right_index=mid+1;
    while(left_index<=mid && right_index<=right)
        {
            if(data[left_index]<data[right_index])
                tempdata[index++] = data[left_index++];
            else
                tempdata[index++] = data[right_index++];
        }
    while(left_index<=mid)
        tempdata[index++] = data[left_index++];
    while(right_index<=right)
        tempdata[index++] = data[right_index++];

    for(int i=0; i<index; i++)
        data[i+left] = tempdata[i];
    return ;
}

void MergeSort(int *data,int left,int right)
{
    int mid = (left+right)/2;

    if(left<right)
        {
            MergeSort(data,left,mid);
            MergeSort(data,mid+1,right);
            Merge(data,left,mid,right);
        }
    return ;
}

int main()
{
    int i,nelements;
    while(scanf("%d",&nelements)==1 && nelements)
    {
        int data[nelements];
        for(i=0; i<nelements; i++)
            scanf("%d",&data[i]);

        MergeSort(data,0,nelements-1);
        cout << "Sorted List : ";
        for(i=0; i<nelements; i++)
            printf("%d ",data[i]);
        printf("\n");
    }
    return 0;
}

