#include <bits/stdc++.h>
using namespace std;

bool in(string mystr, char mychar)
{
    int count = 0;
    for (int i = 0; i < mystr.length(); i++)
    {
        if (mychar == mystr[i])
        {
            count++;
        }
    }
    return (count) ? true : false;
}

class HashTable
{
public:
    string myarr[9];
    HashTable()
    {
        for (int i = 0; i < 9; i++)
        {
            myarr[i] = "NULL";
        }
    }
    int hashing(string newStr);
    void insert(string newStr);
    void deletehash(string newStr);
    bool search(string newStr);
};

int HashTable::hashing(string newStr)
{
    string number = "0123456789";
    string vowel = "AEIOUaeiou";
    int con_count = 0;
    int digit_sum = 0;
    for (int i = 0; i < newStr.length(); i++)
    {
        if (!in(vowel, newStr[i]) && !in(number, newStr[i]))
        {
            con_count++;
        }
        else if (in(number, newStr[i]))
        {
            digit_sum += (newStr[i] - '0');
        }
    }
    return (con_count * 24 + digit_sum) % 9;
}

void HashTable::insert(string newStr)
{
    int hash_index = hashing(newStr);
    int i = 0;
    while (myarr[hash_index] != "NULL")
    {
        hash_index = (hash_index + 1) % 9;
    }
    myarr[hash_index] = newStr;
}

bool HashTable::search(string newStr)
{
    int k = hashing(newStr);
    while (myarr[k] != newStr)
    {
        if (myarr[k] == "NULL")
        {
            return false;
        }
        k = (k + 1) % 9;
    }
    return myarr[k] == newStr;
}

void HashTable::deletehash(string newStr)
{
    int k = hashing(newStr);
    while (myarr[k] != newStr)
    {
        if (myarr[k] == "NULL")
        {
            return;
        }
        k = (k + 1) % 9;
    }
    if (myarr[k] == newStr)
    {
        myarr[k] = "NULL";
    }
}

int main()
{
    string newstr = "ST1E89B8A32";
    string newstr2 = "Hi9IamTaj";
    HashTable myHash;
    myHash.insert(newstr);
    myHash.insert(newstr);
    myHash.insert(newstr2);
    myHash.deletehash(newstr2);
    cout << myHash.search("ABC") << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << myHash.myarr[i] << " ";
    }

    return 0;
}
