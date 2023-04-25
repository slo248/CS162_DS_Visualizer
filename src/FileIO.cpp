#include "FileIO.h"

HWND hwnd;
TCHAR szFileName[MAX_PATH];

std::vector<int> openWindowExplorer()
{
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";

    std::vector<int> res;
    if (GetOpenFileName(&ofn) == TRUE) {
        // User selected a file
        std::ifstream file(ofn.lpstrFile);
        int x; 
        while(file>>x) res.push_back(x);        
    } else {
        // User cancelled the dialog
    }
    return res;
}