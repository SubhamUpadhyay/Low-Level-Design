#include<bits/stdc++.h>
using namespace std;


class documentEditor{
    private:
        vector<string>documentElements;
        string renderDoc;
    public:
        //Add text as a plain string
        void addText(string s)
            {
                documentElements.push_back(s);
            }
        
            //Add an image represented by its file path 
        void addImage(string s)
            {
                documentElements.push_back(s);
            }

        //Render the Document
            string renderDocument(){
                if(renderDoc.empty()) //if not empty return 1;
                    {
                        string result = "";
                        for(auto elements : documentElements)
                            {
                                if(elements.size() > 4 && (elements.substr(elements.size()-4)==".jpg") || (elements.substr(elements.size()-4)==".png"))
                                    {
                                        result += "[image :" +elements +"]"+"\n";
                                    }
                                else
                                    {
                                        result+=elements+"\n";
                                    }
                                    
                            
                            }
                        renderDoc = result;
                    }
                return renderDoc;
            }


        void saveToFile()
            {
                ofstream file("These Document Files");
                if(file.is_open())
                    {
                        //put the render document in file
                        file<<renderDocument();
                        file.close();
                        cout<<"Document saved to document.txt"<<endl;

                    }
                else
                    {
                        cout<<"Error : Unable to open file for writing"<<endl;
                    }
            }

        
};




int main()
{
    documentEditor obj1;
    obj1.addText("Hello World!");
    obj1.addText("This is my first Project");
    obj1.addImage("picture.jpg");
    obj1.addImage("picture.png");
    obj1.addImage("photo.abc");
    

    cout<<obj1.renderDocument()<<endl;
    obj1.saveToFile();
    return 0;
}