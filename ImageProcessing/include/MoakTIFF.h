#ifndef MOAKTIFF_H
#define MOAKTIFF_H

#include <fstream>

class MoakTIFF
{
    public:
        MoakTIFF();
        virtual ~MoakTIFF();

        static bool Read(char* filename, int *arr, int width, int height);
        static bool Write(char* filename, int **arr, int width, int height);
    protected:
    private:
};

#endif // MOAKTIFF_H
