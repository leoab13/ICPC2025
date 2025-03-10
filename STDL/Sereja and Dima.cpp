#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> sol(set<int>& cards)
{

}

int main()
{
    int x;
    cin >> x;
    set<int> cards;
    int tmp;
    for(int i = 0; i < x ; i++)
    {
        cin >> tmp;
        cards.insert(tmp);
    }
    cout << "Hello World" << endl;
    return 0;
}