#include <bits/stdc++.h>
using namespace std;

// Forward Declaration
class TextFile;
class ImageFile;
class VideoFile;

class Ivisit
{
public:
    virtual void visit(TextFile *tf) = 0;
    virtual void visit(ImageFile *imgf) = 0;
    virtual void visit(VideoFile *vf) = 0;
    virtual ~Ivisit() {};
};

class DocumentElement
{
public:
    virtual void accept(Ivisit *visit) = 0;
    virtual ~DocumentElement() {};
};

class TextFile : public DocumentElement
{
private:
    int size;

public:
    TextFile(int size) : size(size) {};

    void accept(Ivisit *vt) override
    {
        vt->visit(this);
    };

    int getSize()
    {
        return size;
    }
    void setSize(int newSize)
    {
        size = newSize;
    }
};

class ImageFile : public DocumentElement
{
private:
    int size;

public:
    ImageFile(int size) : size(size) {};

    void accept(Ivisit *vt) override
    {
        vt->visit(this);
    };

    int getSize()
    {
        return size;
    }
    void setSize(int newSize)
    {
        size = newSize;
    }
};

class VideoFile : public DocumentElement
{
private:
    int size;

public:
    VideoFile(int size) : size(size) {};

    void accept(Ivisit *vt) override
    {
        vt->visit(this);
    };

    int getSize()
    {
        return size;
    }
    void setSize(int newSize)
    {
        size = newSize;
    }
};

class SizeCalculator : public Ivisit
{
public:
    void visit(TextFile *tf) override
    {
        cout << "\n Text File : ";
        cout << "\nSize is " << tf->getSize() << "\n";
    }
    void visit(ImageFile *imgf) override
    {
        cout << "\n Image File";
        cout << "\nSize is " << imgf->getSize() << "\n";
    }
    void visit(VideoFile *vf) override
    {
        cout << "\nVideo File";
        cout << "\nSize is " << vf->getSize() << "\n";
    }
};

class Compress : public Ivisit
{
public:
    void visit(TextFile *tf) override
    {
        cout << "\nText File Compressed Successfully !";
        int x = (tf->getSize()) / 2;
        cout << "\n New size : " << x;
        tf->setSize(x);
    }
    void visit(ImageFile *imgf) override
    {

        cout << "\nImage File compressed Successfully !";
        int x = (imgf->getSize()) / 2;
        cout << "\n New size : " << x;
        imgf->setSize(x);
    }
    void visit(VideoFile *vf) override
    {

        cout << "\nVideo File compressed Successfully !";
        int x = (vf->getSize()) / 2;
        cout << "\n New size : " << x;
        vf->setSize(x);
    }
};

int main()
{
    TextFile txt(10);
    ImageFile img(20);
    VideoFile vid(50);

    SizeCalculator sizecalc;
    Compress compressor;

    txt.accept(&sizecalc);
    img.accept(&sizecalc);
    vid.accept(&sizecalc);

    txt.accept(&compressor);
    img.accept(&compressor);
    vid.accept(&compressor);

    return 0;
}