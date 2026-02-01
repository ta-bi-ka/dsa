#include <iostream>
#include <fstream>
#include "listBST.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file)
    {
        cerr << "Unable to open file\n";
        return 2;
    }
    char c, str[5];
    int val;
    BST<int, int> *bst = new ListBST<int, int>();
    if (!bst)
    {
        cerr << "Memory allocation failed\n";
        return 3;
    }
    while (in_file >> c)
    {
        // TODO: Implement the logic to read commands from the file and output accordingly
        // After every insertion and removal, print the BST in nested parentheses format
        // Handle exceptions where necessary and print appropriate error messages

        // Start your code here
        try
        {
            switch (c)
            {
            case 'F':
                in_file >> val;
                if (bst->find(val))
                {
                    cout << " Key " << val << " found in BST.\n";
                }
                else
                {
                    cout << "Key " << val << " not found in BST\n";
                }
                break;
            case 'E':
                if (bst->empty())
                {
                    cout << "Empty\n";
                }
                else
                {
                    cout << "Not Empty\n";
                }
                break;
            case 'I':
                in_file >> val;
                if (bst->insert(val, val))
                {
                    cout << "Key " << val << " inserted into BST, BST (Default): ";
                    bst->print('D');
                    cout << "\n";
                }
                else
                {
                    cout << "Insertion failed! Key " << val << " already exists in BST, BST (Default): ";
                    bst->print('D');
                    cout << "\n";
                }
                break;
            case 'M':
                in_file >> str;
                if (string(str) == "Min")
                {
                    try
                    {
                        int min_val = bst->find_min();
                        cout << "Minimum value: " << min_val << "\n";
                    }
                    catch (const std::runtime_error &e)
                    {
                        cout << e.what() << "\n";
                    }
                }
                else if (string(str) == "Max")
                {
                    try
                    {
                        int max_val = bst->find_max();
                        cout << "Maximum value: " << max_val << "\n";
                    }
                    catch (const std::runtime_error &e)
                    {
                        cout << e.what() << "\n";
                    }
                }
                break;
            case 'D':
                in_file >> val;
                if (bst->remove(val))
                {
                    cout << "Key " << val << " removed from BST, BST (Default): ";
                    bst->print('D');
                    cout << "\n";
                }
                else
                {
                    cout << "Removal failed! Key " << val << " not found in BST, BST (Default): ";
                    bst->print('D');
                    cout << "\n";
                }
                break;
            case 'T':
                in_file >> str;
                if (string(str) == "In")
                {   
                    cout << "BST (In-order): ";
                    bst->print('I');
                    cout << " \n";
                }
                else if (string(str) == "Pre")
                {
                    cout << "BST (Pre-order): ";
                    bst->print('P');
                    cout << " \n";
                }   
                else if (string(str) == "Post")
                {
                    cout << "BST (Post-order): ";
                    bst->print('O');
                    cout << " \n";
                }

                break;
            case 'S':
                cout << "Size: " << bst->size() << "\n";
                break;

            default:
                cout << "Invalid command: " << c << "\n";
                break;
            }
       }
        catch (const std::exception &e)
        {
            cout << e.what() << "\n";
        }

        // End your code here
    }
//bst->insertWithHeight(x, x);


in_file.close();
delete bst;
return 0;
}

/*Key 1 not found in BST.
Empty
Key 8 inserted into BST, BST (Default): (8:8)
Key 10 inserted into BST, BST (Default): (8:8 () (10:10))
Key 3 inserted into BST, BST (Default): (8:8 (3:3) (10:10))
Minimum value: 3
Key 1 inserted into BST, BST (Default): (8:8 (3:3 (1:1)) (10:10))
Minimum value: 1
Maximum value: 10
Key 14 inserted into BST, BST (Default): (8:8 (3:3 (1:1)) (10:10 () (14:14)))
Maximum value: 14
Insertion failed! Key 3 already exists in BST, BST (Default): (8:8 (3:3 (1:1)) (10:10 () (14:14)))
Key 3 removed from BST, BST (Default): (8:8 (1:1) (10:10 () (14:14)))
Key 6 inserted into BST, BST (Default): (8:8 (1:1 () (6:6)) (10:10 () (14:14)))
Key 4 inserted into BST, BST (Default): (8:8 (1:1 () (6:6 (4:4))) (10:10 () (14:14)))
Key 13 inserted into BST, BST (Default): (8:8 (1:1 () (6:6 (4:4))) (10:10 () (14:14 (13:13))))
Key 7 inserted into BST, BST (Default): (8:8 (1:1 () (6:6 (4:4) (7:7))) (10:10 () (14:14 (13:13))))
Key 9 inserted into BST, BST (Default): (8:8 (1:1 () (6:6 (4:4) (7:7))) (10:10 (9:9) (14:14 (13:13))))
BST (In-order): (1:1) (4:4) (6:6) (7:7) (8:8) (9:9) (10:10) (13:13) (14:14) 
BST (Pre-order): (8:8) (1:1) (6:6) (4:4) (7:7) (10:10) (9:9) (14:14) (13:13) 
BST (Post-order): (4:4) (7:7) (6:6) (1:1) (9:9) (13:13) (14:14) (10:10) (8:8) 
Key 8 removed from BST, BST (Default): (9:9 (1:1 () (6:6 (4:4) (7:7))) (10:10 () (14:14 (13:13))))
BST (Pre-order): (9:9) (1:1) (6:6) (4:4) (7:7) (10:10) (14:14) (13:13) 
Size: 8
Key 6 removed from BST, BST (Default): (9:9 (1:1 () (7:7 (4:4))) (10:10 () (14:14 (13:13))))
Size: 7
Key 10 removed from BST, BST (Default): (9:9 (1:1 () (7:7 (4:4))) (14:14 (13:13)))
Removal failed! Key 10 not found in BST, BST (Default): (9:9 (1:1 () (7:7 (4:4))) (14:14 (13:13)))
Key 4 found in BST.
BST (In-order): (1:1) (4:4) (7:7) (9:9) (13:13) (14:14) 
BST (Pre-order): (9:9) (1:1) (7:7) (4:4) (14:14) (13:13) 
BST (Post-order): (4:4) (7:7) (1:1) (13:13) (14:14) (9:9) 
*/