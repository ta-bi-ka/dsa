#include <iostream>
#include <fstream>
#include <string>
#include "listBST.hpp"
using namespace std;
int successfulbids = 0;
int rejectedbids = 0;
int totalbids = 0;

void printstats(string item_id, ListBST<string, int> *bst1, ListBST<string, int> *bst2, ListBST<string, int> *bst3, ListBST<string, int> *bst4)
{
    if (bst1->find(item_id))
    {
        int total_bids = bst2->get(item_id);
        int successful_bids = bst3->get(item_id);
        int rejected_bids = bst4->get(item_id);
        std::cout << "Statistics for " << item_id << ":\n";
        std::cout << " Current highest bid: " << bst1->get(item_id) << "\n";
        std::cout << " Total bids placed: " << total_bids << "\n";
        std::cout << " Successful bids: " << successful_bids << "\n";
        std::cout << " Rejected bids: " << rejected_bids << "\n";
    }
    else
    {
        std::cout << "Item " << item_id << " not found\n";
    }
}

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
        return 1;
    }

    // TODO: Declare data structures to track bid statistics for each item
    // You need to track: total bids, successful bids, rejected bids for each item
    // Hint: You may use additional BSTs or other data structures
    // Start your code here

    ListBST<string, int> *bst1 = new ListBST<string, int>();
    ListBST<string, int> *bst2 = new ListBST<string, int>();
    ListBST<string, int> *bst3 = new ListBST<string, int>();
    ListBST<string, int> *bst4 = new ListBST<string, int>();

    // End your code here

    int n;
    in_file >> n;
    string *items = new string[2 * n];
    for (int i = 0; i < n; ++i)
    {
        // TODO: Implement the logic to read initial items and their starting bids
        // Initialize statistics tracking for each item
        // Start your code here
        string item_id;
        int starting_bid;

        in_file >> item_id >> starting_bid;
        bst1->insert(item_id, starting_bid);
        bst2->insert(item_id, 0);
        bst3->insert(item_id, 0);
        bst4->insert(item_id, 0);

        // End your code here
    }

    // TODO: Implement the logic to print the initial auction state
    // Start your code here
    std::cout << "Initial auction starts:\n";
    std::cout << "BST(In-order):";
    bst1->print('I');
    std::cout << "\n";

    // End your code here
    std::cout << "\nAuction starts!\n\n";
    std::cout << "==============================\n";

    string operation;
    while (in_file >> operation)
    {
        // TODO: Implement the logic to process operations (ADD, BID, CHECK, STATS, REPORT) and print auction state after each operation
        // For BID operations: update statistics (total bids, successful/rejected counts)
        // For STATS operations: display statistics for the specified item
        // For REPORT operations: display comprehensive auction statistics
        // For other operations: print auction state using in-order traversal
        // Start your code here

        if (operation == "ADD")
        {
            string item_id;
            int starting_bid;
            in_file >> item_id >> starting_bid;

            if (!bst1->find(item_id))
            {
                bst1->insert(item_id, starting_bid);
                bst2->insert(item_id, 0);
                bst3->insert(item_id, 0);
                bst4->insert(item_id, 0);
                std::cout << "Item " << item_id << " added with starting bid " << starting_bid << "\n";
            }
            else if (bst1->get(item_id) < starting_bid)
            {
                bst1->update(item_id, starting_bid);
                std::cout << "Updated item " << item_id << " with new starting bid " << starting_bid << "\n";
            }
            else
            {
                std::cout << "Item " << item_id << " already exists with a higher or equal starting bid\n";
            }

            std::cout << "BST (In-order):";
            bst1->print('I');
            std::cout << "\n";
            std::cout << "==============================\n";
            continue;
        }
        else if (operation == "BID")
        {
            string item_id;
            int bid_amount;
            in_file >> item_id >> bid_amount;
            if (bst1->find(item_id))
            {
                if (bst1->get(item_id) < bid_amount)
                {
                    bst1->update(item_id, bid_amount);
                    int total_bids = bst2->get(item_id);
                    bst2->update(item_id, total_bids + 1);
                    int successful_bids = bst3->get(item_id);
                    bst3->update(item_id, successful_bids + 1);
                    totalbids++;
                    successfulbids++;
                    std::cout << "Bid of " << bid_amount << " on " << item_id << " accepted. Current bid: " << bid_amount << "\n";
                }
                else
                {
                    int total_bids = bst2->get(item_id);
                    bst2->update(item_id, total_bids + 1);
                    int rejected_bids = bst4->get(item_id);
                    bst4->update(item_id, rejected_bids + 1);
                    totalbids++;
                    rejectedbids++;
                    std::cout << "Bid of " << bid_amount << " on " << item_id << " rejected. Current bid: " << bst1->get(item_id) << "\n";
                }
            }
            else
            {
                std::cout << "Item " << item_id << " not found for bidding\n";
            }

            std::cout << "BST (In-order):";
            bst1->print('I');
            std::cout << "\n";
            std::cout << "==============================\n";
            continue;
        }
        else if (operation == "CHECK")
        {
            string item_id;
            in_file >> item_id;
            if (bst1->find(item_id))
            {
                int current_bid = bst1->get(item_id);
                std::cout << "Current bid for " << item_id << ": " << current_bid << "\n";
            }
            else
            {
                std::cout << "Item " << item_id << " not found\n";
            }

            std::cout << "BST (In-order):";
            bst1->print('I');
            std::cout << "\n";
            std::cout << "==============================\n";
            continue;
        }
        else if (operation == "STATS")
        {
            string item_id;
            in_file >> item_id;
            printstats(item_id, bst1, bst2, bst3, bst4);
            std::cout << "\n";
            std::cout << "==============================\n";
            continue;
        }
        else if (operation == "REPORT")
        {

            std::cout << "Auction Report:\n";
            std::cout << "Total items: " << bst1->size() << "\n";
            std::cout << "Total bids placed: " << totalbids << "\n";
            std::cout << "Total successful bids: " << successfulbids << "\n";
            std::cout << "Total rejected bids: " << rejectedbids << "\n";
            std::cout << "Item Statistics:\n";
            delete[] items;
            int total = bst1->size();
            items = new string[total];
            bst1->get_all_keys(items);
            for (int i = 0; i < total; i++)
            {
                string item_id = items[i];
                int current_bid = bst1->get(item_id);
                int total_bids = bst2->get(item_id);
                int successful_bids = bst3->get(item_id);
                int rejected_bids = bst4->get(item_id);
                std::cout << item_id << ": Current bid: " << current_bid << ", Total bids: " << total_bids
                          << ", Successful: " << successful_bids << ", Rejected: " << rejected_bids << "\n";
            }

            std::cout << "\n";
            std::cout << "==============================\n";
            continue;
        }

        // End your code here
        
    }

    in_file.close();
    // TODO: Delete data structures you created
    // Start your code here
    delete bst1;
    delete bst2;
    delete bst3;
    delete bst4;
    delete[] items;

    // End your code here

    return 0;
}
