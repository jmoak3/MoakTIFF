#include "../include/BMPManager.h"
#include <malloc.h>
#include <iostream>
BMPManager::BMPManager()
{
    //ctor
}

BMPManager::~BMPManager()
{
    //dtor
}

bool BMPManager::Read(char* filename, int *arr, int width, int height)
{
    return false;
}

static void ByteWrite(std::ofstream &fout, unsigned short *out, int num)
{
   fout.write((char*)out, sizeof(unsigned short)*num);
}

static void IDF(std::ofstream &fout, int width, int height)
{
    unsigned short offset = 0x75ce;
    int len = 1;
    unsigned short *whatTag = new unsigned short[1];
    whatTag[0] = 0x000C;
    ByteWrite(fout, whatTag, len);
    delete whatTag;

    len = 6;
    unsigned short *widthTag = new unsigned short[6];
    widthTag[0] = 0x0100;
    widthTag[1] = 0x0003;
    widthTag[3] = 0x0000;
    widthTag[2] = 0x0001;
    widthTag[4] = width;
    widthTag[5] = 0x0000;
    ByteWrite(fout, widthTag, len);
    delete widthTag;

    len = 6;
    unsigned short *heightTag = new unsigned short[6];
    heightTag[0] = 0x0101;
    heightTag[1] = 0x0003;
    heightTag[3] = 0x0000;
    heightTag[2] = 0x0001;
    heightTag[4] = height;
    heightTag[5] = 0x0000;
    ByteWrite(fout, heightTag, len);
    delete heightTag;

    len = 6;
    unsigned short *bitsPerSampleTag = new unsigned short[6];
    bitsPerSampleTag[0] = 0x0102;
    bitsPerSampleTag[1] = 0x0003;
    bitsPerSampleTag[3] = 0x0000;
    bitsPerSampleTag[2] = 0x0003;
    bitsPerSampleTag[5] = 0x0000;
    bitsPerSampleTag[4] = offset; offset+=3*2;
    ByteWrite(fout, bitsPerSampleTag, len);
    delete bitsPerSampleTag;
    // 0102 0003 0000 0003 0000 eb16

    len = 6;
    unsigned short *compressTag = new unsigned short[6];
    compressTag[0] = 0x0103;
    compressTag[1] = 0x0003;
    compressTag[3] = 0x0000;
    compressTag[2] = 0x0001;
    compressTag[4] = 0x0001;
    compressTag[5] = 0x0000;
    ByteWrite(fout, compressTag, len);
    delete compressTag;
    // 0103 0003 0000 0001 0001 0000

    len = 6;
    unsigned short *photometTag = new unsigned short[6];
    photometTag[0] = 0x0106;
    photometTag[1] = 0x0003;
    photometTag[3] = 0x0000;
    photometTag[2] = 0x0001;
    photometTag[4] = 0x0002;
    photometTag[5] = 0x0000;
    ByteWrite(fout, photometTag, len);
    delete photometTag;

    len = 6;
    unsigned short *stripOffTag = new unsigned short[6];
    stripOffTag[0] = 0x0111;
    stripOffTag[1] = 0x0004;
    stripOffTag[3] = 0x0000;
    stripOffTag[2] = 0x0002; //strips per image
    stripOffTag[5] = 0x0000;
    stripOffTag[4] = offset; offset+=2*4;
    ByteWrite(fout, stripOffTag, len);
    delete stripOffTag;

    len = 6;
    unsigned short *samplesPerPixTag = new unsigned short[6];
    samplesPerPixTag[0] = 0x0115;
    samplesPerPixTag[1] = 0x0003;
    samplesPerPixTag[3] = 0x0000;
    samplesPerPixTag[2] = 0x0001;
    samplesPerPixTag[4] = 0x0003;
    samplesPerPixTag[5] = 0x0000;
    ByteWrite(fout, samplesPerPixTag, len);
    delete samplesPerPixTag;

    len = 6;
    unsigned short *rowsPerStripTag = new unsigned short[6];
    rowsPerStripTag[0] = 0x0116;
    rowsPerStripTag[1] = 0x0003;
    rowsPerStripTag[3] = 0x0000;
    rowsPerStripTag[2] = 0x0001;
    rowsPerStripTag[4] = height/2;
    rowsPerStripTag[5] = 0x0000;
    ByteWrite(fout, rowsPerStripTag, len);
    delete rowsPerStripTag;

    len = 6;
    unsigned short *stripByteCountTag = new unsigned short[6];
    stripByteCountTag[0] = 0x0117;
    stripByteCountTag[1] = 0x0004;
    stripByteCountTag[3] = 0x0000;
    stripByteCountTag[2] = 0x0002; //strips per image
    stripByteCountTag[5] = 0x0000;
    stripByteCountTag[4] = offset; offset+=2*4;
    ByteWrite(fout, stripByteCountTag, len);
    delete stripByteCountTag;

    len = 6;
    unsigned short *xResTag = new unsigned short[6];
    xResTag[0] = 0x011A;
    xResTag[1] = 0x0005;
    xResTag[3] = 0x0000;
    xResTag[2] = 0x0001;
    xResTag[5] = 0x0000;
    xResTag[4] = offset; offset+=2*4;
    ByteWrite(fout, xResTag, len);
    delete xResTag;
    len = 6;
    unsigned short *yResTag = new unsigned short[6];
    yResTag[0] = 0x011B;
    yResTag[1] = 0x0005;
    yResTag[3] = 0x0000;
    yResTag[2] = 0x0001;
    yResTag[5] = 0x0000;
    yResTag[4] = offset; offset+=2*4;
    ByteWrite(fout, yResTag, len);
    delete yResTag;

    len = 6;
    unsigned short *resUnitTag = new unsigned short[6];
    resUnitTag[0] = 0x0128;
    resUnitTag[1] = 0x0003;
    resUnitTag[3] = 0x0000;
    resUnitTag[2] = 0x0001;
    resUnitTag[4] = 0x0001;
    resUnitTag[5] = 0x0000;
    ByteWrite(fout, resUnitTag, len);
    delete resUnitTag;

    len = 2;
    unsigned short *nextOffTag = new unsigned short[2];
    nextOffTag[0] = 0x0000;
    nextOffTag[1] = 0x0000;
    ByteWrite(fout, nextOffTag, len);
    delete nextOffTag;

    len = 19;
    unsigned short *extraContent = new unsigned short[19];
    extraContent[0] = 0x0008;//bitspersample
    extraContent[1] = 0x0008;
    extraContent[2] = 0x0008;
    extraContent[4] = 0x0000;//stripoffsets long!
    extraContent[3] = 0x0008;
    extraContent[6] = 0x0000;
    extraContent[5] = 3*width*height/2 + 8;
    extraContent[8] = 0x0000;//stripbytecount LONG
    extraContent[7] = 3*width*height/2;
    extraContent[10] = 0x0000;
    extraContent[9] = 3*width*height/2;
    extraContent[11] = 0x0000;//xres
    extraContent[12] = width;
    extraContent[13] = 0x0000;
    extraContent[14] = 0x0001;
    extraContent[15] = 0x0000;//yres
    extraContent[16] = height;
    extraContent[17] = 0x0000;
    extraContent[18] = 0x0001;
    ByteWrite(fout, extraContent, len);
    delete extraContent;

}

bool BMPManager::Write(char* filename, int **arr, int width, int height)
{
    std::ofstream fout;
    fout.open(filename, std::ios_base::binary);

    int len = 4;
    unsigned short *header = new unsigned short[4];
    header[0] = 0x4949;
    header[1] = 0x002A;
    header[3] = 0x0000;
    header[2] = 0x7538;
    ByteWrite(fout, header, len);
    delete header;

    for (int y=0;y<height;++y)
    {
        for (int x=0;x<width;++x)
        {
            fout << (char)arr[y*width + x][0] << (char)arr[y*width + x][1] << (char)arr[y*width + x][2];
        }
    }

    IDF(fout, width, height);

    fout.close();
    return true;
}
