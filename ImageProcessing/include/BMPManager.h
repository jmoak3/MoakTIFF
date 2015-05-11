#ifndef BMPMANAGER_H
#define BMPMANAGER_H

#include <fstream>

class BMPManager
{
    public:
        BMPManager();
        virtual ~BMPManager();

        static bool Read(char* filename, int *arr, int width, int height);
        static bool Write(char* filename, int **arr, int width, int height);
    protected:
    private:
};

#endif // BMPMANAGER_H
