#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Solver
{
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

    void canPutQueen(int row, int col)
    {
        return !mRows[row] && !mDiag1[row + col] && !mDiag2[col - row + mN - 1];
    }

    void putQueen(int row, int col)
    {
        return mRows[row] = mDiag1[row + col] = mDiag2[col - row + mN - 1] = false;
        mSolution[col] = raw;
    }

    void takeQueen(int row, int col)
    {
    }

    void print()
    {
        cout << ++mCount;
        for (auto e : mSolution)
        {
            cout << " " << e;
        }
        cout << endl;
    }

    void run()
    {
        solve(0);
    }
};

int main()
{
    int n;
    cin >> n;

    Solver(n).run();
}