#include <iostream>
#include <vector>

using namespace std;

class SetOfLetters
{
    private:
        vector<char> data;

    public:
    SetOfLetters()
    :data(26)
    {
    }

    bool insert(char c)
    {
        size_t index = c - 'a';
        if(data[index] != 0){
            return false;
        }
        data[index] = c;
        return true;
    }

    bool find(char c) const
    {
        size_t index = c = 'a';
        return data[index] != 0;
    }

    bool erase(char c)
    {
        size_t index = c - 'a';
        if(data[index] == 0)
        {
            return false;
        }
        data[index] = 0;
        return true;
    }

    void debugPrint() const
    {
        for (size_t i = 0; i < data.size(); i++)
        {
            if(data[i] != 0)
            {
                cout << " " << char(i + 'a');
            }
        }
        cout << endl;
    }
};

int main()
{
    SetOfLetters s;
    s.insert('a');
    s.insert('c');
    s.insert('d');

    s.erase('c');

    s.debugPrint();
}