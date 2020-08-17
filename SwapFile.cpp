#include <iostream>
#include <fstream>
using namespace std;
void writeToFile(string, string);
string readFileOne(string);

int main() {
    string contentFileOne;
    string contentFileTwo;

    contentFileOne = readFileOne("fileOne.txt");
    contentFileTwo = readFileOne("fileTwo.txt");

    writeToFile("fileTwo.txt", contentFileOne);
    writeToFile("fileOne.txt", contentFileTwo);
    return 0;
}

string readFileOne(string fileName) {
    fstream fileStream;
    string fileContent;
    fileStream.open(fileName);
    if (fileStream.is_open()) {
        while (getline (fileStream, fileContent)) {
        }
        fileStream.close();
    } else {
        cout << "Unable to open file";
    }
    fileStream.open(fileName, ios::out | ios::trunc);
    fileStream.close();
    return fileContent;
}

void writeToFile(string fileName, string fileContent) {
    fstream fileStream;
    fileStream.open(fileName, ios::out | ios::trunc);
    if (fileStream.is_open()) {
        fileStream << fileContent ;
        fileStream.close();
    }
}
