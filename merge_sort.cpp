#include<bits\stdc++.h>
using namespace std;

void Merge(int a[],int l,int mid,int h);

void MergeSort(int a[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,h);
        Merge(a,l,mid,h);
    }
}


void Merge(int a[],int l,int mid,int h)
{
    int i=l;
    int j=mid+1;
    int k=l;
    int temp[100];

    while(i<=mid && j<=h)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=a[j];
            j++;
            k++;
        }

    }

    while(i<=mid)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
     while(j<=h)
    {
        temp[k]=a[j];
        j++;
        k++;
    }

    for(int m=l;m<=h;m++)
        a[m]=temp[m];
}

int main()
{

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    MergeSort(a,0,n-1);
    cout<<"after sorting-";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;

}

