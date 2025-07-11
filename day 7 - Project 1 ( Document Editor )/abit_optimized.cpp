#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Base interface for all document elements
class documentElement {
public:
    virtual string render() = 0;
};

// Text element
class textElement : public documentElement {
private:
    string text;

public:
    textElement(string text) {
        this->text = text;
    }

    string render() override {
        return text;
    }
};

// Image element
class imageElement : public documentElement {
private:
    string imagePath;

public:
    imageElement(string text) {
        imagePath = text;
    }

    string render() override {
        return "[Image : " + imagePath + " ]";
    }
};

// New line element represents a line break
class newLine : public documentElement {
public:
    string render() override {
        return "\n";
    }
};

// Tab space element represents tab space in the document
class tabSpaceElement : public documentElement {
public:
    string render() override {
        return "\t";
    }
};

// Document class holds a collection of elements
class Document {
private:
    vector<documentElement*> lists;

public:
    void addElement(documentElement* elements) {
        lists.push_back(elements);
    }

    string render() {
        string result = "";
        for (auto element : lists) {
            result += element->render();
        }
        return result;
    }
};

// Persistence interface
class persistence {
public:
    virtual void save(string data) = 0;
};

// Save to file implementation
class saveToFile : public persistence {
public:
    void save(string data) override {
        ofstream outFile("document.txt"); // fixed extension to match printed name
        if (outFile) {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error : Unable to open file for writing";
        }
    }
};

// Save to database stub
class saveToDB : public persistence {
public:
    void save(string data) override {
        cout << "File saved to DB";
    }
};

// Document editor class
class documentEditor {
private:
    Document* document;
    persistence* storage;
    string renderedDocument;

public:
    documentEditor(Document* document, persistence* storage) {
        this->document = document;
        this->storage = storage;
    }

    void addText(string text) {
        document->addElement(new textElement(text));
    }

    void addImage(string imagePath) {
        document->addElement(new imageElement(imagePath));
    }

    void addNewLine() {
        document->addElement(new newLine());
    }

    void addTabSpace() {
        document->addElement(new tabSpaceElement());
    }

    // Render the document (caching the result)
    string renderDocument() {
        if (renderedDocument.empty()) {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    // Save rendered document using the chosen storage
    void saveDocument() {
        storage->save(renderDocument());
    }
};

// Client usage example
int main() {
    Document* document = new Document{};
    persistence* saving = new saveToFile{};

    documentEditor* editor = new documentEditor(document, saving);

    editor->addText("Hello world!");
    editor->addNewLine();
    editor->addText("This is a real world document editor example");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    cout << editor->renderDocument() << endl;
    editor->saveDocument();

    return 0;
}
