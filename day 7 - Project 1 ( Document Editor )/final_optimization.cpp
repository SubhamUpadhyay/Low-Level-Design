#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class DocumentElement
{
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text) : text(text) {}
    string render() override
    {
        return text;
    }
};

class ImageElement : public DocumentElement
{
private:
    string imagePath;

public:
    ImageElement(string path) : imagePath(path) {}
    string render() override
    {
        return "[Image : " + imagePath + " ]";
    }
};

class NewLine : public DocumentElement
{
public:
    string render() override
    {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement
{
public:
    string render() override
    {
        return "\t";
    }
};

class Document
{
private:
    vector<DocumentElement *> elements;

public:
    void addElement(DocumentElement *element)
    {
        elements.push_back(element);
    }
    const vector<DocumentElement *> &getElements() const
    {
        return elements;
    }
};

class DocumentRenderer
{
private:
    Document *document;

public:
    DocumentRenderer(Document *doc) : document(doc) {}
    string render()
    {
        string result = "";
        for (auto element : document->getElements())
        {
            result += element->render();
        }
        return result;
    }
};

class Persistence
{
public:
    virtual void save(string data) = 0;
};

class SaveToFile : public Persistence
{
public:
    void save(string data) override
    {
        ofstream outFile("document.txt");
        if (outFile)
        {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        }
        else
        {
            cout << "Error: Unable to open file for writing" << endl;
        }
    }
};

class SaveToDB : public Persistence
{
public:
    void save(string data) override
    {
        cout << "File saved to DB" << endl;
    }
};

class DocumentEditor
{
private:
    Document *document;

public:
    // DocumentEditor(Document* doc) : document(doc) {}
    DocumentEditor(Document *doc)
    {
        document = doc;
    }

    void addText(string text)
    {
        document->addElement(new TextElement(text));
    }
    void addImage(string imagePath)
    {
        document->addElement(new ImageElement(imagePath));
    }
};

int main()
{
    Document *doc = new Document();
    DocumentEditor editor(doc);

    editor.addText("Hello world!");
    doc->addElement(new NewLine());
    editor.addText("This is a real world document editor example");
    doc->addElement(new NewLine());
    doc->addElement(new TabSpaceElement());
    editor.addText("Indented text after a tab space.");
    doc->addElement(new NewLine());
    editor.addImage("picture.jpg");

    DocumentRenderer renderer(doc);
    string renderedOutput = renderer.render();
    cout << renderedOutput << endl;

    SaveToFile saver;
    saver.save(renderedOutput);

    return 0;
}
