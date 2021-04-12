#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Solver
{
    struct Frame
    {
        int mRow;
        int mCol;
        Frame(int row, int col)
        : mRow(row), mCol(col)
        {
        }
    };

    int mN;
    int mCount;
    vector<bool> mRows;
    vector<bool> mDiag1;
    vector<bool> mDiag2;
    vector<int> mSolution;

public:
    Solver(int n)
        : mN(n), mCount(0)
    {
        if (n < 1)
        {
            throw runtime_error("Incorrect size of puzzle");
        }
        mRows.resize(n, false);
        mDiag1.resize(n * 2 - 1);
        mDiag2.resize(n * 2 - 1);
        mSolution.resize(n);
    }

    void solve(int col)
    {
        if (col == mN)
        {
            print();
        }
        else
        {
            for (int row = 0; row < mN; row++)
            {
                if (canPutQueen(row, col))
                {
                    putQueen(row, col);
                    solve(col + 1);
                    takeQueen(row, col);
                }
            }
        }
    }

    bool canPutQueen(int row, int col)
    {
        return !mRows[row] && !mDiag1[row + col] && !mDiag2[col - row + mN - 1];
    }

    void putQueen(int row, int col)
    {
        mRows[row] = mDiag1[row + col] = mDiag2[col - row + mN - 1] = true;
        mSolution[col] = row;
    }

    void takeQueen(int row, int col)
    {
        mRows[row] = mDiag1[row + col] = mDiag2[col - row + mN - 1] = false;
    }

    void print()
    {
        cout << ++mCount << ":";
        for (auto e : mSolution)
        {
            cout << " " << e;
        }
        cout << endl;
    }

    void run()
    {
        //solve(0);
        vector<Frame> stack;
        stack.emplace_back(0, 0);
        while(!stack.empty())
        {
            if(stack.back().mCol == mN)
            {
                print();
                stack.pop_back();
                takeQueen(stack.back().mRow, stack.back().mCol);
                ++stack.back().mRow;
            }
            else if (canPutQueen(stack.back().mRow, stack.back().mCol))
            {
                putQueen(stack.back().mRow, stack.back().mCol);
                stack.emplace_back(0, stack.back().mCol + 1);
            }
            else if (stack.back().mRow == mN)
            {
                stack.pop_back();
                if(!stack.empty())
                {
                    takeQueen(stack.back().mRow, stack.back().mCol);
                    ++stack.back().mRow;
                }
            }
            else
            {
                ++stack.back().mRow;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;

    Solver(n).run();
}