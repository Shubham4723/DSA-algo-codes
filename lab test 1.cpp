#include<iostream>
using namespace std;

void swap(char *x, char *y)
{
    cout<<"Entered swap";
    char temp;
    temp = *x;
    x=y;
    *y=temp;
    cout<<"Finished swap";
}

int main()
{
    char a[]="RRRRGGGGBBBB"; // Desired output RGBRGBRGBRGB
    int size = sizeof(a)/sizeof(a[0]);

    int low =0;
    int mid =0;
    int high = size-2;
    cout<<size<<high<<mid<<low;
    char temp;
    while(mid<=high)
    {

        if(a[mid]== 'R')
        {

            swap(&a[low],&a[mid]);
            low++;
            mid++;
        }
        else if(a[mid] == 'B')
        {
            mid++;
        }
        else if(a[mid] == 'G')
        {
            swap(&a[high],&a[mid]);

            high--;

        }
        for(int i=0;i<size-1;i++)
            {
                cout<<a[i];
            }
            cout<<endl;
    }

    for(int i=0;i<size-1;i++)
    {
        cout<<a[i];
    }

    return 0;
}
