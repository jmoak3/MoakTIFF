#include <stdio.h>
#include "include/MoakTIFF.h"
#include <assert.h>


bool testWriting()
{
    bool flag = true;
    const int width = 100;
    const int height = 100;
    int *arr[width*height];
    for (int i=0;i<height;++i)
    {
        for (int j=0;j<width;++j)
        {
            arr[i*width+ j] = new int[3];
            arr[i*width+ j][0] = i*1;
            arr[i*width+ j][1] = 0;
            arr[i*width+ j][2] = (height-1-j);
        }
    }
    flag = flag && MoakTIFF::Write("file1.TIF", arr, width, height);

    return flag;
}

int main()
{
    printf("Hello WOrld\n");
    assert(testWriting());
    return 0;
}


